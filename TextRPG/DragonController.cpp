#include "DragonController.h"


DragoneController::DragoneController() 
	: MonsterController(MonsterType::Dragon)
{
	_hp = 50;
	_attack = 5;
	_defense = 3;
	_name = "µå·¡°ï";

	PrintInfo();
}