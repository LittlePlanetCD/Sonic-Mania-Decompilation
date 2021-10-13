#ifndef OBJ_CHEMICALBALL_H
#define OBJ_CHEMICALBALL_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    Hitbox hitbox;
    TABLE(int moveOffset1[196],
          { -0x320000, 0,         -0x320000, -0x48000,  -0x31F500, -0x8E800,  -0x31DF00, -0xD3800,  -0x31BE00, -0x117000, -0x319200, -0x159000,
            -0x315B00, -0x199800, -0x311900, -0x1D8800, -0x30CC00, -0x216000, -0x307400, -0x252000, -0x301100, -0x28C800, -0x2FA300, -0x2C5800,
            -0x2F2A00, -0x2FD000, -0x2EA600, -0x333000, -0x2E1700, -0x367800, -0x2D7D00, -0x39A800, -0x2CD800, -0x3CC000, -0x2C2800, -0x3FC000,
            -0x2B6D00, -0x42A800, -0x2AA700, -0x457800, -0x29D600, -0x483000, -0x28FA00, -0x4AD000, -0x281300, -0x4D5800, -0x272100, -0x4FC800,
            -0x262400, -0x522000, -0x251C00, -0x546000, -0x240900, -0x568800, -0x22EB00, -0x589800, -0x21C200, -0x5A9000, -0x208E00, -0x5C7000,
            -0x1F4F00, -0x5E3800, -0x1E0500, -0x5FE800, -0x1CB000, -0x618000, -0x1B5000, -0x630000, -0x19E500, -0x646800, -0x186F00, -0x65B800,
            -0x16EE00, -0x66F000, -0x156200, -0x681000, -0x13CB00, -0x691800, -0x122900, -0x6A0800, -0x107C00, -0x6AE000, -0xEC400,  -0x6BA000,
            -0xD0100,  -0x6C4800, -0xB3300,  -0x6CD800, -0x95A00,  -0x6D5000, -0x77600,  -0x6DB000, -0x58700,  -0x6DF800, -0x38D00,  -0x6E2800,
            -0x18800,  -0x6E4000, 0x8800,    -0x6E4000, 0x28D00,   -0x6E2800, 0x48700,   -0x6DF800, 0x67600,   -0x6DB000, 0x85A00,   -0x6D5000,
            0xA3300,   -0x6CD800, 0xC0100,   -0x6C4800, 0xDC400,   -0x6BA000, 0xF7C00,   -0x6AE000, 0x112900,  -0x6A0800, 0x12CB00,  -0x691800,
            0x146200,  -0x681000, 0x15EE00,  -0x66F000, 0x176F00,  -0x65B800, 0x18E500,  -0x646800, 0x1A5000,  -0x630000, 0x1BB000,  -0x618000,
            0x1D0500,  -0x5FE800, 0x1E4F00,  -0x5E3800, 0x1F8E00,  -0x5C7000, 0x20C200,  -0x5A9000, 0x21EB00,  -0x589800, 0x230900,  -0x568800,
            0x241C00,  -0x546000, 0x252400,  -0x522000, 0x262100,  -0x4FC800, 0x271300,  -0x4D5800, 0x27FA00,  -0x4AD000, 0x28D600,  -0x483000,
            0x29A700,  -0x457800, 0x2A6D00,  -0x42A800, 0x2B2800,  -0x3FC000, 0x2BD800,  -0x3CC000, 0x2C7D00,  -0x39A800, 0x2D1700,  -0x367800,
            0x2DA600,  -0x333000, 0x2E2A00,  -0x2FD000, 0x2EA300,  -0x2C5800, 0x2F1100,  -0x28C800, 0x2F7400,  -0x252000, 0x2FCC00,  -0x216000,
            0x301900,  -0x1D8800, 0x305B00,  -0x199800, 0x309200,  -0x159000, 0x30BE00,  -0x117000, 0x30DF00,  -0xD3800,  0x30F500,  -0x8E800,
            0x310000,  -0x48000,  0x310000,  0 });
    TABLE(int moveOffset2[98],
          { -0x264000, -0x262800, -0x25F800, -0x25B000, -0x255000, -0x24D800, -0x244800, -0x23A000, -0x22E000, -0x220800, -0x211800,
            -0x201000, -0x1EF000, -0x1DB800, -0x1C6800, -0x1B0000, -0x198000, -0x17E800, -0x163800, -0x147000, -0x129000, -0x109800,
            -0xE8800,  -0xC6000,  -0xA2000,  -0x7C800,  -0x55800,  -0x2D000,  -0x3000,   0x28800,   0x55800,   0x84000,   0xB4000,
            0xE5800,   0x118800,  0x14D000,  0x183000,  0x1BA800,  0x1F3800,  0x22E000,  0x26A000,  0x2A7800,  0x2E6800,  0x327000,
            0x369000,  0x3AC800,  0x3F1800,  0x438000,  0x480000,  0x480000,  0x438000,  0x3F1800,  0x3AC800,  0x369000,  0x327000,
            0x2E6800,  0x2A7800,  0x26A000,  0x22E000,  0x1F3800,  0x1BA800,  0x183000,  0x14D000,  0x118800,  0xE5800,   0xB4000,
            0x84000,   0x55800,   0x28800,   -0x3000,   -0x2D000,  -0x55800,  -0x7C800,  -0xA2000,  -0xC6000,  -0xE8800,  -0x109800,
            -0x129000, -0x147000, -0x163800, -0x17E800, -0x198000, -0x1B0000, -0x1C6800, -0x1DB800, -0x1EF000, -0x201000, -0x211800,
            -0x220800, -0x22E000, -0x23A000, -0x244800, -0x24D800, -0x255000, -0x25B000, -0x25F800, -0x262800, -0x264000 });
    ushort aniFrames;
    ushort sfxBloop;
} ObjectChemicalBall;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    byte type;
    byte interval;
    byte intervalOffset;
    int field_60;
    Vector2 startPos2;
    Vector2 startPos;
    Animator animator;
    int field_8C;
    bool32 master;
} EntityChemicalBall;

// Object Struct
extern ObjectChemicalBall *ChemicalBall;

// Standard Entity Events
void ChemicalBall_Update(void);
void ChemicalBall_LateUpdate(void);
void ChemicalBall_StaticUpdate(void);
void ChemicalBall_Draw(void);
void ChemicalBall_Create(void *data);
void ChemicalBall_StageLoad(void);
void ChemicalBall_EditorDraw(void);
void ChemicalBall_EditorLoad(void);
void ChemicalBall_Serialize(void);

// Extra Entity Functions
void ChemicalBall_CheckHit(void);
void ChemicalBall_MoveType0(void);
void ChemicalBall_MoveType1(void);

#endif //! OBJ_CHEMICALBALL_H
