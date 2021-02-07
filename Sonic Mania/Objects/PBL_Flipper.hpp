#ifndef OBJ_PBL_FLIPPER_H
#define OBJ_PBL_FLIPPER_H

#include "../SonicMania.hpp"

// Object Class
struct ObjectPBL_Flipper : Object {

};

// Entity Class
struct EntityPBL_Flipper : Entity {

};

// Object Struct
extern ObjectPBL_Flipper PBL_Flipper;

// Standard Entity Events
void PBL_Flipper_Update();
void PBL_Flipper_LateUpdate();
void PBL_Flipper_StaticUpdate();
void PBL_Flipper_Draw();
void PBL_Flipper_Create(void* data);
void PBL_Flipper_StageLoad();
void PBL_Flipper_EditorDraw();
void PBL_Flipper_EditorLoad();
void PBL_Flipper_Serialize();

// Extra Entity Functions


#endif //!OBJ_PBL_FLIPPER_H
