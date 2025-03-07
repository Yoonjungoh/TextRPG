#include "ArcherController.h"


ArcherController::ArcherController() 
	: PlayerController(PlayerType::Archer)
{
	_maxHp = 75;
	_hp = 75;
	_attack = 7;
	_specialAttackSuccessProbability = 50;
	_defense = 2;
	_name = "±Ã¼ö";

	PrintInfo();
}