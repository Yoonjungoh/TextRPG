#include "KnightController.h"

KnightController::KnightController() 
	: PlayerController(PlayerType::Knight)
{
	_hp = 100;
	_attack = 5;
	_defense = 3;
	_name = "ภüป็";

	PrintInfo();
}