#ifndef OBJ_CLAPPERBOARD_H
#define OBJ_CLAPPERBOARD_H

#include "../SonicMania.hpp"

// Object Class
struct ObjectClapperboard : Object{

};

// Entity Class
struct EntityClapperboard : Entity {

};

// Object Struct
extern ObjectClapperboard *Clapperboard;

// Standard Entity Events
void Clapperboard_Update();
void Clapperboard_LateUpdate();
void Clapperboard_StaticUpdate();
void Clapperboard_Draw();
void Clapperboard_Create(void* data);
void Clapperboard_StageLoad();
void Clapperboard_EditorDraw();
void Clapperboard_EditorLoad();
void Clapperboard_Serialize();

// Extra Entity Functions


#endif //!OBJ_CLAPPERBOARD_H
