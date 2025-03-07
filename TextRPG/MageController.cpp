#include "MageController.h"


MageController::MageController() 
	: PlayerController(PlayerType::Mage)
{
	_hp = 50;
	_attack = 10;
	_defense = 1;
	_name = "¸¶¹ý»ç";

	PrintInfo();
}