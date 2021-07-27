#ifndef OBJ_DACONTROL_H
#define OBJ_DACONTROL_H

#include "SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    ushort aniFrames;
} ObjectDAControl;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    int field_5C;
    int field_60;
    int field_64;
    TextInfo text;
    Animator animator1;
    Animator animator2;
    Animator animator3[5];
    Animator animator4;
} EntityDAControl;

// Object Struct
extern ObjectDAControl *DAControl;

// Standard Entity Events
void DAControl_Update(void);
void DAControl_LateUpdate(void);
void DAControl_StaticUpdate(void);
void DAControl_Draw(void);
void DAControl_Create(void* data);
void DAControl_StageLoad(void);
void DAControl_EditorDraw(void);
void DAControl_EditorLoad(void);
void DAControl_Serialize(void);

// Extra Entity Functions


#endif //!OBJ_DACONTROL_H