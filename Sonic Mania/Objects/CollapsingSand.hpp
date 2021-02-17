#ifndef OBJ_COLLAPSINGSAND_H
#define OBJ_COLLAPSINGSAND_H

#include "../SonicMania.hpp"

// Object Class
struct ObjectCollapsingSand : Object{

};

// Entity Class
struct EntityCollapsingSand : Entity {

};

// Object Struct
extern ObjectCollapsingSand *CollapsingSand;

// Standard Entity Events
void CollapsingSand_Update();
void CollapsingSand_LateUpdate();
void CollapsingSand_StaticUpdate();
void CollapsingSand_Draw();
void CollapsingSand_Create(void* data);
void CollapsingSand_StageLoad();
void CollapsingSand_EditorDraw();
void CollapsingSand_EditorLoad();
void CollapsingSand_Serialize();

// Extra Entity Functions


#endif //!OBJ_COLLAPSINGSAND_H