#include "SlimeController.h"


SlimeController::SlimeController() 
	: MonsterController(MonsterType::Slime)
{
	_hp = 30;
	_attack = 3;
	_defense = 1;
	_name = "ΩΩ∂Û¿”";

	PrintInfo();
}