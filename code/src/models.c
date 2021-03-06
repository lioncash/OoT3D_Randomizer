#include "z3D/z3D.h"
#include "models.h"
#include "item_override.h"
#include "item_table.h"
#include <stddef.h>

typedef s32 (*Object_proc)(ObjectContext* objectCtx, s16 objectId);
#define Object_Spawn_addr 0x32E21C
#define Object_Spawn ((Object_proc)Object_Spawn_addr)
#define Object_GetIndex_addr 0x363C10
#define Object_GetIndex ((Object_proc)Object_GetIndex_addr)
#define Object_IsLoaded_addr 0x373074
#define Object_IsLoaded ((Object_proc)Object_IsLoaded_addr) //For Object_IsLoaded, second param is bankIndex

typedef void (*GlModel_MatrixCopy_proc)(GlModel* glModel, nn_math_MTX34* mtx);
#define GlModel_MatrixCopy_addr 0x3721E0
#define GlModel_MatrixCopy ((GlModel_MatrixCopy_proc)GlModel_MatrixCopy_addr)

typedef void (*GlModel_Draw_proc)(GlModel* glModel, s32 param_2);
#define GlModel_Draw_addr 0x372170
#define GlModel_Draw ((GlModel_Draw_proc)GlModel_Draw_addr)

typedef void (*GlModel_SpawnAt_proc)(Actor* actor, GlobalContext* globalCtx, GlModel** glModel, s32 objModelIdx);
#define GlModel_SpawnAt_addr 0x372F38
#define GlModel_SpawnAt ((GlModel_SpawnAt_proc)GlModel_SpawnAt_addr)

typedef GlModel* (*GlModel_Spawn_proc)(Actor* actor, GlobalContext* globalCtx, s16 objId, s32 objModelIdX);
#define GlModel_Spawn_addr 0x36A924
#define GlModel_Spawn ((GlModel_Spawn_proc)GlModel_Spawn_addr)

typedef void (*Actor_SetModelMatrix_proc)(f32 x, f32 y, f32 z, nn_math_MTX34* mtx, ActorShape* shape);
#define Actor_SetModelMatrix_addr 0x3679D0
#define Actor_SetModelMatrix ((Actor_SetModelMatrix_proc)Actor_SetModelMatrix_addr)

typedef void (*Matrix_Multiply_proc)(nn_math_MTX34* dst, nn_math_MTX34* lhs, nn_math_MTX44* rhs) __attribute__((pcs("aapcs-vfp")));
#define Matrix_Multiply_addr 0x36C174
#define Matrix_Multiply ((Matrix_Multiply_proc)Matrix_Multiply_addr)

#define LOADEDMODELS_MAX 16
Model ModelContext[LOADEDMODELS_MAX] = { 0 };

void Model_Init(Model* model, GlobalContext* globalCtx) {
    model->glModel = GlModel_Spawn(model->actor, globalCtx, model->info.objectId, model->info.objectModelIdx);
    model->loaded = 1;
}

void Model_Destroy(Model* model) {
    if (model->glModel != NULL) {
        model->glModel->vtbl->destroy(model->glModel);
        model->glModel = NULL;
    }
    model->actor = NULL;
    model->info.objectId = 0;
    model->info.objectBankIdx = 0;
    model->info.objectModelIdx = 0;
    model->loaded = 0;
}

void Model_UpdateAll(GlobalContext* globalCtx) {
    Model* model;

    for (s32 i = 0; i < LOADEDMODELS_MAX; ++i) {
        model = &ModelContext[i];

        // No actor, considered unused
        if (model->actor == NULL) {
            continue;
        }

        // Actor has been killed, destroy the model
        if (model->actor->update == NULL) {
            Model_Destroy(model);
            continue;
        }

        // Actor is alive, model has not been loaded yet
        if ((model->actor != NULL) && (!model->loaded)) {
            if (Object_IsLoaded(&globalCtx->objectCtx, model->info.objectBankIdx)) {
                Model_Init(model, globalCtx);
            }
        }
    }
}

void Actor_SetModelMatrixWrapper(Actor* actor, nn_math_MTX34* mtx) {
    asm volatile("push {r0-r12, lr}\n"
                 "vldr s1,[r0,#0x2C]\n"
                 "vldr s0,[r0,#0xC4]\n"
                 "vldr s2,[r0,#0x58]\n"
                 "vmla.f32 s1,s0,s2\n" // y coord calc
                 "vldr s0,[r0,#0x28]\n" // x coord
                 "vldr s2,[r0,#0x30]\n" // z coord
                 "add r2,r0,#0xBC\n"
                 "mov r0,r1\n" // mtx
                 "mov r1,r2\n" // shape
                 "push {r0-r12, lr}\n"
                 "bl 0x3679D0\n"
                 "pop {r0-r12, lr}\n"
                 "pop {r0-r12, lr}\n"
                );
}

void Model_UpdateMatrix(Model* model) {
    nn_math_MTX44 scaleMtx;
    Actor_SetModelMatrixWrapper(model->actor, &model->glModel->mtx);

    for (s32 i = 0; i < 4; ++i) {
        for (s32 j = 0; j < 4; ++j) {
            if (i == j) {
                scaleMtx.data[i][j] = (i == 3) ? 1.0f : model->scale;
            } else {
                scaleMtx.data[i][j] = 0.0f;
            }
        }
    }
    Matrix_Multiply(&model->glModel->mtx, &model->glModel->mtx, &scaleMtx);
}

void Model_Draw(Model* model) {
    if ((model->loaded) && (model->glModel != NULL)) {
        model->glModel->unk_AC = 1;
        Model_UpdateMatrix(model);
        GlModel_Draw(model->glModel, 0); //TODO is 0 always okay?
    }
}

void Model_LookupByOverride(Model* model, ItemOverride override) {
    if (override.key.all != 0) {
        u16 itemId = override.value.looksLikeItemId ?
            override.value.looksLikeItemId :
            override.value.itemId;
        u16 resolvedItemId = ItemTable_ResolveUpgrades(itemId);
        ItemRow* itemRow = ItemTable_GetItemRow(resolvedItemId);
        model->info.objectId = itemRow->objectId;
        model->info.objectModelIdx = itemRow->objectModelIdx;
    }
}

void Model_GetObjectBankIndex(Model* model, Actor* actor, GlobalContext* globalCtx) {
    s32 objectBankIdx = Object_GetIndex(&globalCtx->objectCtx, model->info.objectId);
    if (objectBankIdx < 0) {
        objectBankIdx = Object_Spawn(&globalCtx->objectCtx, model->info.objectId);
    }
    model->info.objectBankIdx = objectBankIdx;
}

void Model_InfoLookup(Model* model, Actor* actor, GlobalContext* globalCtx, u16 baseItemId) {
    ItemOverride override = ItemOverride_Lookup(actor, globalCtx->sceneNum, baseItemId);
    if (override.key.all != 0) {
        Model_LookupByOverride(model, override);
        Model_GetObjectBankIndex(model, actor, globalCtx);
    }
}

void Model_Create(Model* model, GlobalContext* globalCtx) {
    Model* newModel = NULL;

    for (s32 i = 0; i < LOADEDMODELS_MAX; ++i) {
        if ((ModelContext[i].actor == NULL) && (ModelContext[i].glModel == NULL)) {
            newModel = &ModelContext[i];
            break;
        }
    }

    if (newModel != NULL) {
        newModel->actor = model->actor;
        newModel->info = model->info;
        newModel->loaded = 0;
        newModel->glModel = NULL;
        switch(newModel->info.objectId) {
            case 0x015C : //Skulltula token
                newModel->scale = 0.25f;
                break;
            default:
                newModel->scale = 0.3f;
                break;
        }
    }
}

void Model_SpawnByActor(Actor* actor, GlobalContext* globalCtx, u16 baseItemId) {
    Model model = { NULL, { 0, 0, 0 }, 0, NULL };
    
    Model_InfoLookup(&model, actor, globalCtx, baseItemId);
    if (model.info.objectId != 0) {
        model.actor = actor;
        Model_Create(&model, globalCtx);
        if ((model.info.objectId == 0x015C) && (model.info.objectModelIdx == 0x00)) { //Special case for Token's second model
            model.info.objectModelIdx = 0x01;
            Model_Create(&model, globalCtx);
        }
    }
}

void Model_DestroyByActor(Actor* actor) {
    for (s32 i = 0; i < LOADEDMODELS_MAX; ++i) {
        if (ModelContext[i].actor == actor) {
            Model_Destroy(&ModelContext[i]);
        }
    }
}

s32 Model_DrawByActor(Actor* actor) {
    s32 actorDrawn = 0;

    for (s32 i = 0; i < LOADEDMODELS_MAX; ++i) {
        if (ModelContext[i].actor == actor) {
            actorDrawn = 1;
            Model_Draw(&ModelContext[i]);
        }
    }
    return actorDrawn;
}
