#include "SlimeController.h"


SlimeController::SlimeController() 
	: MonsterController(MonsterType::Slime)
{
	_maxHp = 30;
	_hp = 30;
	_attack = 3;
	_specialAttackSuccessProbability = 1;
	_defense = 1;
	_name = "ΩΩ∂Û¿”";

	PrintInfo();
}