// ---------------------------------------------------------------------
// RSDK Project: Sonic Mania
// Object Description: Kabasira Object
// Object Author: Christian Whitehead/Simon Thomley/Hunter Bridges
// Decompiled by: Rubberduckycooly & RMGRich
// ---------------------------------------------------------------------

#include "SonicMania.h"

ObjectKabasira *Kabasira;

void Kabasira_Update(void)
{
    RSDK_THIS(Kabasira);
    StateMachine_Run(self->state);
}

void Kabasira_LateUpdate(void) {}

void Kabasira_StaticUpdate(void) {}

void Kabasira_Draw(void)
{
    RSDK_THIS(Kabasira);

    if (self->state == Kabasira_State_LaunchedAttack) {
        self->drawFX = FX_SCALE | FX_FLIP;
        RSDK.DrawSprite(&self->bodyAnimator, NULL, false);
        RSDK.DrawSprite(&self->wingsAnimator, NULL, false);
        RSDK.ProcessAnimation(&self->wingsAnimator);
    }
    else {
        int32 speed = (2 * (self->direction == FLIP_NONE) - 1);
        int32 angle = self->angle + 72 * speed;
        if (angle < 0)
            angle = ((-1 - angle) & -0x200) + angle + 0x200;
        angle &= 0x1FF;

        int32 alpha    = 0x100 / Kabasira_SegmentCount; // default is 0x40
        int32 angleVel = 24 * speed;

        for (int32 i = 0; i < Kabasira_SegmentCount - 1; ++i) {
            Kabasira_DrawSegment(angle, alpha);

            angle -= angleVel;
            if (angle < 0)
                angle = ((-1 - angle) & -0x200) + angle + 0x200;
            angle &= 0x1FF;

            alpha += 0x100 / Kabasira_SegmentCount; // default is 0x40
        }

        Kabasira_DrawSegment(angle, alpha);
        self->angle = angle;
    }
}

void Kabasira_Create(void *data)
{
    RSDK_THIS(Kabasira);

    self->inkEffect = INK_ALPHA;
    self->drawFX    = FX_FLIP | FX_ROTATE | FX_SCALE;
    self->scale.x   = 0x200;
    self->scale.y   = 0x200;
    if (!SceneInfo->inEditor) {
        self->visible       = true;
        self->drawOrder     = Zone->drawOrderLow;
        self->startPos      = self->position;
        self->startDir      = self->direction;
        self->active        = ACTIVE_BOUNDS;
        self->updateRange.x = 0x800000;
        self->updateRange.y = 0x800000;
        RSDK.SetSpriteAnimation(Kabasira->aniFrames, 0, &self->bodyAnimator, true, 0);
        RSDK.SetSpriteAnimation(Kabasira->aniFrames, 1, &self->wingsAnimator, true, 0);
        self->wingsAnimator.frameCount = 3;

        if (data) {
            self->alpha = 0x80;
            self->state = Kabasira_State_LaunchedAttack;
        }
        else {
            self->wingsAnimator.frameCount = 3;
            self->wingsAnimator.loopIndex  = 0;
            self->state                = Kabasira_State_Setup;
        }
    }
}

void Kabasira_StageLoad(void)
{
    if (RSDK.CheckStageFolder("SSZ1"))
        Kabasira->aniFrames = RSDK.LoadSpriteAnimation("SSZ1/Kabasira.bin", SCOPE_STAGE);
    else if (RSDK.CheckStageFolder("SSZ2"))
        Kabasira->aniFrames = RSDK.LoadSpriteAnimation("SSZ2/Kabasira.bin", SCOPE_STAGE);

    Kabasira->hitbox.left   = -6;
    Kabasira->hitbox.top    = -6;
    Kabasira->hitbox.right  = 6;
    Kabasira->hitbox.bottom = 6;

    Kabasira->checkRange.x  = 0x60000;
    Kabasira->checkRange.y  = 0x60000;

    Kabasira->sfxPon        = RSDK.GetSfx("Stage/Pon.wav");
    Kabasira->sfxExplosion2 = RSDK.GetSfx("Stage/Explosion2.wav");

    DEBUGMODE_ADD_OBJ(Kabasira);
}

void Kabasira_DebugSpawn(void)
{
    RSDK_THIS(DebugMode);

    CREATE_ENTITY(Kabasira, NULL, self->position.x, self->position.y);
}

void Kabasira_DebugDraw(void)
{
    RSDK.SetSpriteAnimation(Kabasira->aniFrames, 0, &DebugMode->animator, true, 0);
    RSDK.DrawSprite(&DebugMode->animator, NULL, false);
}

bool32 Kabasira_HandleAnimations(uint8 angle)
{
    RSDK_THIS(Kabasira);

    int32 rotation  = 2 * angle;
    int32 prevFrame = self->wingsAnimator.frameID % 3;
    int32 frame     = 0;
    switch (rotation >> 7) {
        case 0:
        case 2: frame = (rotation >> 5) & 3; break;
        case 1:
        case 3: frame = 3 - ((rotation >> 5) & 3); break;
    }

    int32 frameCount                 = 3 * frame;
    self->wingsAnimator.loopIndex  = frameCount;
    self->wingsAnimator.frameID    = prevFrame + frameCount;
    self->wingsAnimator.frameCount = frameCount + 3;
    return rotation > 0x80 && rotation < 0x180;
}

void Kabasira_DrawSegment(int32 angle, int32 alpha)
{
    RSDK_THIS(Kabasira);
    Vector2 drawPos;

    int32 rotation = 2 * angle;
    drawPos.x    = 0xA00 * RSDK.Sin512(rotation) + self->startPos.x;
    drawPos.y    = (RSDK.Cos512(angle) << 13) + self->startPos.y;
    RSDK.SetSpriteAnimation(Kabasira->aniFrames, 0, &self->bodyAnimator, true, (11 - rotation % 512 / 42 % 12));

    if (!self->bodyAnimator.frameID || self->bodyAnimator.frameID > 6) {
        self->scale.x = 0x200;
        self->scale.y = 0x200;
    }
    else {
        self->scale.x = ((abs(2 * self->bodyAnimator.frameID - 7) << 5) / 5) + 480;
        self->scale.y = self->scale.x;
    }

    uint8 dir         = Kabasira_HandleAnimations(angle) ? FLIP_X : FLIP_NONE;
    int32 storedDir   = self->direction;
    int32 storedAlpha = self->alpha;
    if (self->angle < 0x100) {
        self->direction = FLIP_NONE;
        self->alpha     = alpha;
        RSDK.DrawSprite(&self->bodyAnimator, &drawPos, false);

        self->direction = dir;
        alpha >>= 1;
        self->alpha = alpha;
        RSDK.DrawSprite(&self->wingsAnimator, &drawPos, false);
    }
    else {
        self->direction = dir;
        self->alpha     = alpha >> 1;
        RSDK.DrawSprite(&self->wingsAnimator, &drawPos, false);

        self->direction = FLIP_NONE;
        self->alpha     = alpha;
        RSDK.DrawSprite(&self->bodyAnimator, &drawPos, false);
    }

    self->alpha     = storedAlpha;
    self->direction = storedDir;
}

void Kabasira_CheckPlayerCollisions(void)
{
    RSDK_THIS(Kabasira);

    foreach_active(Player, player)
    {
        if (Player_CheckBadnikTouch(player, self, &Kabasira->hitbox))
            Player_CheckBadnikBreak(player, self, true);
    }
}

void Kabasira_State_Setup(void)
{
    RSDK_THIS(Kabasira);

    self->active = ACTIVE_NORMAL;
    self->angle  = 0;
    self->timer  = 0;
    self->state  = Kabasira_State_Moving;
    Kabasira_State_Moving();
}

void Kabasira_State_Moving(void)
{
    RSDK_THIS(Kabasira);

    RSDK.ProcessAnimation(&self->wingsAnimator);

    self->angle += 2;
    if (self->timer > 0) {
        self->timer--;
    }
    else {
        self->timer = 240;
        if (RSDK.CheckOnScreen(self, &Kabasira->checkRange)) {
            EntityPlayer *player = Player_GetNearestPlayer();
            if (player) {
                RSDK.PlaySfx(Kabasira->sfxPon, false, 255);
                EntityKabasira *attack = CREATE_ENTITY(Kabasira, intToVoid(true), self->position.x, self->position.y);
                int32 angle           = RSDK.ATan2(player->position.x - self->position.x, player->position.y - self->position.y);
                attack->velocity.x     = RSDK.Cos256(angle) << 9;
                attack->velocity.y     = RSDK.Sin256(angle) << 9;
                attack->direction      = player->position.x < self->position.x;
            }
        }
    }

    self->position.x = self->startPos.x + (0xA00 * RSDK.Sin512(2 * self->angle));
    self->position.y = self->startPos.y + (RSDK.Cos512(self->angle) << 13);

    Kabasira_CheckPlayerCollisions();

    if (!RSDK.CheckOnScreen(self, NULL) && !RSDK.CheckPosOnScreen(&self->startPos, &self->updateRange)) {
        self->position.x = self->startPos.x;
        self->position.y = self->startPos.y;
        self->direction  = self->startDir;
        Kabasira_Create(NULL);
    }
}

void Kabasira_State_LaunchedAttack(void)
{
    RSDK_THIS(Kabasira);

    self->position.x += self->velocity.x;
    self->position.y += self->velocity.y;

    foreach_active(Player, player)
    {
        if (Player_CheckBadnikTouch(player, self, &Kabasira->hitbox)) {
            if (Player_CheckAttacking(player, self)) {
                CREATE_ENTITY(Explosion, intToVoid(EXPLOSION_ITEMBOX), self->position.x, self->position.y)->drawOrder = Zone->drawOrderHigh;
                RSDK.PlaySfx(Kabasira->sfxExplosion2, false, 255);
                destroyEntity(self);
                foreach_break;
            }
            else
                Player_CheckHit(player, self);
        }
    }
}

#if RETRO_INCLUDE_EDITOR
void Kabasira_EditorDraw(void)
{
    RSDK_THIS(Kabasira);
    RSDK.SetSpriteAnimation(Kabasira->aniFrames, 0, &self->bodyAnimator, false, 0);
    RSDK.SetSpriteAnimation(Kabasira->aniFrames, 1, &self->wingsAnimator, false, 0);
    self->startPos = self->position;
    self->startDir = self->direction;

    Kabasira_Draw();
}

void Kabasira_EditorLoad(void)
{
    if (RSDK.CheckStageFolder("SSZ1"))
        Kabasira->aniFrames = RSDK.LoadSpriteAnimation("SSZ1/Kabasira.bin", SCOPE_STAGE);
    else if (RSDK.CheckStageFolder("SSZ2"))
        Kabasira->aniFrames = RSDK.LoadSpriteAnimation("SSZ2/Kabasira.bin", SCOPE_STAGE);

    RSDK_ACTIVE_VAR(Kabasira, direction);
    RSDK_ENUM_VAR("No Flip", FLIP_NONE);
    RSDK_ENUM_VAR("Flip X", FLIP_X);
}
#endif

void Kabasira_Serialize(void) { RSDK_EDITABLE_VAR(Kabasira, VAR_UINT8, direction); }
