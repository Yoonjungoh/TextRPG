#include "DragonController.h"


DragonController::DragonController()
	: MonsterController(MonsterType::Dragon)
{
	_maxHp = 50;
	_hp = 50;
	_attack = 5;
	_specialAttackSuccessProbability = 5;
	_defense = 3;
	_name = "µå·¡°ï";

	PrintInfo();
}