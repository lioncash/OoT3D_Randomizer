#pragma once
#include <string>
#include <cstdio>
#include <algorithm>
#include <3ds.h>

namespace Logic {

  //Child item logic
  extern bool KokiriSword;
  extern bool Slingshot;
  extern bool ZeldasLetter;
  extern bool WeirdEgg;
  extern bool HasBottle;
  extern bool BombBag;
  extern bool Bombchus;
  extern bool MagicBean;
  extern bool MagicBeanPack;
  extern bool RutosLetter;
  extern bool Boomerang;
  extern bool DinsFire;
  extern bool FaroresWind;
  extern bool NayrusLove;
  extern bool LensOfTruth;
  extern bool ShardOfAgony;
  extern bool SkullMask;
  extern bool MaskOfTruth;

  //Adult logic
  extern bool Bow;
  extern bool Hammer;
  extern bool IronBoots;
  extern bool HoverBoots;
  extern bool MirrorShield;
  extern bool GoronTunic;
  extern bool ZoraTunic;
  extern bool Epona;
  extern bool BigPoe;
  extern bool GerudoToken;
  extern bool FireArrows;
  extern bool IceArrows;
  extern bool LightArrows;

  //Songs
  extern bool ZeldasLullaby;
  extern bool SariasSong;
  extern bool SunsSong;
  extern bool SongOfStorms;
  extern bool EponasSong;
  extern bool SongOfTime;
  extern bool MinuetOfForest;
  extern bool BoleroOfFire;
  extern bool SerenadeOfWater;
  extern bool RequiemOfSpirit;
  extern bool NocturneOfShadow;
  extern bool PreludeOfLight;

  //Stones and Meddallions
  extern bool ForestMedallion;
  extern bool FireMedallion;
  extern bool WaterMedallion;
  extern bool SpiritMedallion;
  extern bool ShadowMedallion;
  extern bool LightMedallion;
  extern bool KokirisEmerald;
  extern bool GoronsRuby;
  extern bool ZorasSapphire;

  //Dungeon Clears
  extern bool DekuTreeClear;
  extern bool DodongosCavernClear;
  extern bool JabuJabusBellyClear;
  extern bool ForestTempleClear;
  extern bool FireTempleClear;
  extern bool WaterTempleClear;
  extern bool SpiritTempleClear;
  extern bool ShadowTempleClear;

  extern bool ForestTrialClear;
  extern bool FireTrialClear;
  extern bool WaterTrialClear;
  extern bool SpiritTrialClear;
  extern bool ShadowTrialClear;
  extern bool LightTrialClear;

  //Progression Items
  extern u8 ProgressiveBulletBag;
  extern u8 ProgressiveBombBag;
  extern u8 ProgressiveScale;
  extern u8 ProgressiveHookshot;
  extern u8 ProgressiveBow;
  extern u8 ProgressiveStrength;
  extern u8 ProgressiveWallet;
  extern u8 ProgressiveMagic;
  extern u8 ProgressiveOcarina;

  //Keys
  extern u8 ForestTempleKeys;
  extern u8 FireTempleKeys;
  extern u8 WaterTempleKeys;
  extern u8 SpiritTempleKeys;
  extern u8 ShadowTempleKeys;
  extern u8 BottomOfTheWellKeys;
  extern u8 GerudoTrainingGroundsKeys;
  extern u8 GerudoFortressKeys;
  extern u8 GanonsCastleKeys;

  extern bool BossKeyForestTemple;
  extern bool BossKeyFireTemple;
  extern bool BossKeyWaterTemple;
  extern bool BossKeySpiritTemple;
  extern bool BossKeyShadowTemple;
  extern bool BossKeyGanonsCastle;

  //Gold Skulltula Count
  extern u8 GoldSkulltulaTokens;

  //item and bottle drops
  extern bool DekuNutDrop;
  extern bool NutPot;
  extern bool DekuBabaNuts;
  extern bool DekuStickDrop;
  extern bool StickPot;
  extern bool DekuBabaSticks;
  extern bool BugsAccess;
  extern bool BugShrub;
  extern bool WanderingBugs;
  extern bool BugRock;
  extern bool BlueFireAccess;
  extern bool FishAccess;
  extern bool FishGroup;
  extern bool LoneFish;
  extern bool FairyAccess;
  extern bool GossipStoneFairy;
  extern bool BeanPlantFairy;
  extern bool ButterflyFairy;
  extern bool FairyPot;
  extern bool FreeFairies;
  extern bool FairyPond;

  extern bool BuyDekuShield;
  extern bool BuyHylianShield;
  extern bool BuyDekuNut5;
  extern bool BuyDekuNut10;
  extern bool BuyDekuStick1;
  extern bool BuyBottleBug;
  extern bool BuyBlueFire;
  extern bool BuyBottledFish;
  extern bool BuyFairysSpirit;
  extern bool BuyBombchus5;
  extern bool BuyBombchus10;
  extern bool BuyBombchus20;

  /* --- HELPERS --- */
  /* These are used to simplify reading the logic, but need to be updated
  /  every time a base value is updated.                       */

  extern bool Ocarina;
  extern bool MagicMeter;
  extern bool Hookshot;
  extern bool Longshot;
  extern bool GoronBracelet;
  extern bool SilverGauntlets;
  extern bool GoldenGauntlets;
  extern bool SilverScale;
  extern bool GoldScale;

  extern bool ScarecrowSong;
  extern bool Scarecrow;
  extern bool DistantScarecrow;

  extern bool Bombs;
  extern bool DekuShield;
  extern bool HylianShield;
  extern bool Nuts;
  extern bool Sticks;
  extern bool Bugs;
  extern bool BlueFire;
  extern bool Fish;
  extern bool Fairy;
  extern bool HasBigPoe;

  extern bool Bombs;
  extern bool HasBombchus;
  extern bool FoundBombchus;
  extern bool HasExplosives;
  extern bool IsChild;
  extern bool IsAdult;
  extern bool IsStartingAge;
//extern bool IsGlitched;
  extern bool CanBlastOrSmash;
  extern bool CanChildAttack;
  extern bool CanChildDamage;
  extern bool CanCutShrubs;
  extern bool CanDive;
  extern bool CanLeaveForest;
  extern bool CanPlantBugs;
  extern bool CanRideEpona;
  extern bool CanStunDeku;
  extern bool CanSummonGossipFairy;
  extern bool CanSummonGossipFairyWithoutSuns;
  extern bool CanPlantBean;
  extern bool CanOpenBombGrotto;
  extern bool CanOpenStormGrotto;

  extern bool GuaranteeTradePath;
  extern bool GuaranteeHint;
  extern bool HasFireSource;
  extern bool HasFireSourceWithTorch;

  //Gerudo Fortress
  extern bool CanFinishGerudoFortress;

  extern bool HasShield;
  extern bool CanShield;
  extern bool CanJumpslash;
  extern bool CanUseProjectile;

  //Bridge Requirements
  extern bool HasAllStones;
  extern bool HasAllMedallions;
  extern bool CanBuildRainbowBridge;
  extern bool CanTriggerLACS;

  //Other
  extern bool AtDay;
  extern bool AtNight;
  extern bool HadNightStart;
  extern bool LinksCow;
  extern bool AtDampeTime;
  extern bool DeliverLetter;

  //Events
  extern bool ShowedMidoSwordAndShield;
  extern bool CarpenterRescue;
  extern bool DampesWindmillAccess;
  extern bool GF_GateOpen;
  extern bool DrainWell;
  extern bool GoronCityChildFire;
  extern bool GCWoodsWarpOpen;
  extern bool StopGCRollingGoronAsAdult;
  extern bool ChildWaterTemple;

  /* --- END OF HELPERS --- */

  //Logic Settings
  extern bool LogicMidoBackflip;
  extern bool LogicLostWoodsBridge;
  extern bool LogicGrottosWithoutAgony;
  extern bool LogicBiggoronBolero;
  extern bool LogicGerudoKitchen;
  extern bool LogicWaterHookshotEntry;
  extern bool LogicLensWasteland;
  extern bool LogicReverseWasteland;
  extern bool LogicVisibleCollision;
  extern bool LogicManOnRoof;
  extern bool LogicKakarikoTowerGS;
  extern bool LogicDMTBombable;
  extern bool LogicLinkGoronDins;
  extern bool LogicGoronCityLeftMost;
  extern bool LogicGoronCityPot;
  extern bool LogicGoronCityPotWithStrength;
  extern bool LogicChildRollingWithStrength;
  extern bool LogicCraterUpperToLower;
  extern bool LogicCraterBeanPoHWithHovers;
  extern bool LogicFewerTunicRequirements;
  extern bool LogicZoraWithHovers;
  extern bool LogicZoraWithCucco;
  extern bool LogicDekuB1Skip;
  extern bool LogicDekuB1WebsWithBow;
  extern bool LogicDCStaircase;
  extern bool LogicDCJump;
  extern bool LogicDCSlingshotSkip;
  extern bool LogicJabuBossGSAdult;
  extern bool LogicForestVines;
  extern bool LogicForestScarecrow;
  extern bool LogicForestOutsideBackdoor;
  extern bool LogicLabDiving;
  extern bool LogicZoraRiverLower;
  extern bool LogicZoraRiverUpper;
  extern bool LogicGraveyardPoH;
  extern bool LogicChildDampeRacePoH;
  extern bool LogicFireBossDoorJump;
  extern bool LogicFireStrength;
  extern bool LogicFireScarecrow;
  extern bool LogicFireFlameMaze;
  extern bool LogicWaterTempleTorchLongshot;
  extern bool LogicWaterCentralBow;
  extern bool LogicWaterCrackedWallNothing;
  extern bool LogicWaterCrackedWallHovers;
  extern bool LogicWaterBossKeyRegion;
  extern bool LogicWaterDragonBombchu;
  extern bool LogicWaterBKJumpDive;
  extern bool LogicWaterBKChest;
  extern bool LogicWaterNorthBasementLedgeJump;
  extern bool LogicWaterDragonBombchu;
  extern bool LogicWaterDragonJumpDive;
  extern bool LogicWaterNorthBasementLedgeJump;
  extern bool LogicWaterBKChest;
  extern bool LogicWaterDragonJumpDive;
  extern bool LogicSpiritLowerAdultSwitch;
  extern bool LogicSpiritChildBombchu;
  extern bool LogicSpiritWall;
  extern bool LogicSpiritLobbyGS;
  extern bool LogicSpiritMapChest;
  extern bool LogicSpiritSunChest;
  extern bool LogicShadowFireArrowEntry;
  extern bool LogicShadowUmbrella;
  extern bool LogicShadowFreestandingKey;
  extern bool LogicShadowStatue;
  extern bool LogicBotwCageGS;
  extern bool LogicChildDeadhand;
  extern bool LogicGtgWithoutHookshot;
  extern bool LogicGtgFakeWall;
  extern bool LogicLensSpirit;
  extern bool LogicLensShadow;
  extern bool LogicLensShadowBack;
  extern bool LogicLensBotw;
  extern bool LogicLensGtg;
  extern bool LogicLensCastle;
  extern bool LogicSpiritTrialHookshot;
  extern bool KakarikoVillageGateOpen;
  extern bool ForestTempleJoAndBeth;
  extern bool ForestTempleAmyAndMeg;
  extern bool KingZoraThawed;
  extern bool OpenDoorOfTime;
  extern bool HasNightStart;
  extern bool SkippedTrials;
  extern std::string OpenForest;
  extern std::string OpenKakariko;
  extern std::string Bridge;
  extern std::string LACSCondition;
  extern std::string GerudoFortress;
  extern std::string DamageMultiplier;
  extern std::string ZorasFountain;
  extern std::string StartingAge;
  extern std::string Age;
  extern std::string Keysanity;
  extern std::string BossKeysanity;
  extern std::string MapsAndCompasses;
  extern bool IsStartingAge;
  extern bool CanBeChild;
  extern bool CanBeAdult;
  extern bool ShuffleDungeonEntrances;
  extern bool ShuffleOverworldEntrances;
  extern bool ShuffleSpecialIndoorEntrances;
  extern bool ShuffleWeirdEgg;
  extern bool ShuffleGerudoToken;
  extern bool ShuffleZeldasLetter;
  extern bool ShuffleKokiriSword;
  extern bool ShuffleSongs;
  extern bool BombchusInLogic;
  extern bool Skullsanity;
  extern bool Shopsanity;

  extern u8 AddedProgressiveBulletBags;
  extern u8 AddedProgressiveBombBags;
  extern u8 AddedProgressiveMagics;
  extern u8 AddedProgressiveScales;
  extern u8 AddedProgressiveHookshots;
  extern u8 AddedProgressiveBows;
  extern u8 AddedProgressiveWallets;
  extern u8 AddedProgressiveStrengths;
  extern u8 AddedProgressiveOcarinas;

  extern void UpdateHelpers();
  extern void UpdateSettings();
  extern bool CanPlay(bool song);
  extern bool CanUse(std::string itemName);
  extern bool HasProjectile(std::string age);
  extern bool SmallKeys(u8 dungeonKeyCount, u8 requiredAmount);
  extern bool EventsUpdated();
  extern void GenericGrottoChecks();
}
