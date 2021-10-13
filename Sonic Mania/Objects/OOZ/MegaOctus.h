#ifndef OBJ_MEGAOCTUS_H
#define OBJ_MEGAOCTUS_H

#include "SonicMania.h"

typedef enum {
    MEGAOCTUS_BODY,
    MEGAOCTUS_UNUSED1,
    MEGAOCTUS_HARPOON,
    MEGAOCTUS_GUN,
    MEGAOCTUS_ORB,
    MEGAOCTUS_ARM,
    MEGAOCTUS_LASER,
    MEGAOCTUS_ORBSHOT,
    MEGAOCTUS_UNUSED8,
    MEGAOCTUS_LASERFIRE,
} MegaOctusTypes;

// Object Class
typedef struct {
    RSDK_OBJECT
    Entity *bossPtr;
    Animator animator1;
    Animator animator2;
    Animator animator3;
    Animator animator4;
    Animator animator5;
    int field_80;
    int field_84;
    bool32 spawnHarpoon;
    int field_8C;
    TABLE(int field_90[11], { -0x200000, -0x180000, -0x100000, -0xC0000, -0x80000, 0, 0x80000, 0xC0000, 0x100000, 0x180000, 0x200000 });
    TABLE(int field_BC[4], { -0x780000, -0x800000, -0x700000, -0x510000 });
    int orbHealth[2];
    bool32 field_D4;
    ushort aniFrames;
    ushort eggmanFrames;
    ushort hatchFrames;
    Hitbox hitbox;
    ushort sfxBossHit;
    ushort sfxExplosion;
    ushort sfxLaser;
    ushort sfxBullet;
    ushort sfxHarpoon;
    ushort sfxSurface;
    ushort sfxLaserSplash;
} ObjectMegaOctus;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    StateMachine(stateDraw);
    byte type;
    int timer;
    int field_68;
    int field_6C;
    int field_70;
    int shotCount;
    int invincibilityTimer;
    byte health;
    Vector2 origin;
    int orbID;
    Entity *parent;
#if RETRO_USE_PLUS
    int tilePlatY;
#endif
    Animator animator1;
    Animator animator2;
    Hitbox hitbox;
} EntityMegaOctus;

// Object Struct
extern ObjectMegaOctus *MegaOctus;

// Standard Entity Events
void MegaOctus_Update(void);
void MegaOctus_LateUpdate(void);
void MegaOctus_StaticUpdate(void);
void MegaOctus_Draw(void);
void MegaOctus_Create(void *data);
void MegaOctus_StageLoad(void);
void MegaOctus_EditorDraw(void);
void MegaOctus_EditorLoad(void);
void MegaOctus_Serialize(void);

// Extra Entity Functions
void MegaOctus_CheckPlayerCollisions_Body(void);
void MegaOctus_HandleEggmanAnim(void);
void MegaOctus_Explode(void);
void MegaOctus_HandleDirectionChange(void);

void MegaOctus_State_SetupBounds(void);
void MegaOctus_State_SetupArena(void);
void MegaOctus_State_Unknown1(void);
void MegaOctus_State_Unknown2(void);
void MegaOctus_State_Unknown3(void);
void MegaOctus_State_Unknown4(void);
void MegaOctus_State_Unknown5(void);
void MegaOctus_State_SpawnWeapons(void);
void MegaOctus_State_SpawnOrbs(void);
void MegaOctus_State_Destroyed(void);
void MegaOctus_State_Finish(void);
void MegaOctus_StateDraw_Body(void);

void MegaOctus_CheckPlayerCollisions_Unknown(void);
void MegaOctus_State_HarpoonLeft(void);
void MegaOctus_State_HarpoonRight(void);
void MegaOctus_StateDraw_HarpoonLeft(void);
void MegaOctus_StateDraw_HarpoonRight(void);

void MegaOctus_CheckPlayerCollisions_Gun(void);
void MegaOctus_StateGun_Unknown1(void);
void MegaOctus_StateGun_Unknown2(void);
void MegaOctus_StateGun_FireLaser(void);
void MegaOctus_StateGun_Unknown4(void);
void MegaOctus_StateDraw_Gun(void);

void MegaOctus_CheckPlayerCollisions_Orb(void);
void MegaOctus_StateOrb_Wait(void);
void MegaOctus_StateOrb_FireShot(void);
void MegaOctus_StateOrb_Idle(void);
void MegaOctus_StateOrb_Destroyed(void);
void MegaOctus_StateDraw_Orb(void);

void MegaOctus_StateArm_Unknown1(void);
void MegaOctus_StateArm_Unknown2(void);
void MegaOctus_StateArm_Unknown3(void);
void MegaOctus_StateArm_Unknown4(void);
void MegaOctus_StateDraw_Arm_Unknown1(void);

void MegaOctus_StateArm_Unknown5(void);
void MegaOctus_StateDraw_Arm_Unknown2(void);

void MegaOctus_State_Laser(void);

void MegaOctus_State_LaserFire(void);
void MegaOctus_StateDraw_Laser(void);

void MegaOctus_State_Shot(void);
void MegaOctus_StateDraw_OrbShot(void);

#if RETRO_USE_PLUS
void MegaOctus_TilePlatformState_Unknown(void);
#endif

#endif //! OBJ_MEGAOCTUS_H
