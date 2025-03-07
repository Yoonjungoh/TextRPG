#include "KnightController.h"

KnightController::KnightController() 
	: PlayerController(PlayerType::Knight)
{
	_maxHp = 100;
	_hp = 100;
	_attack = 5;
	_specialAttackSuccessProbability = 15;
	_defense = 3;
	_name = "ภüป็";

	PrintInfo();
}