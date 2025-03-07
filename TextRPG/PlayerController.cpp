#include "PlayerController.h"

PlayerController::PlayerController(PlayerType playerType)
	: CreatureController(CreatureType::Player), _playerType(playerType)
{

}
PlayerController::~PlayerController()
{

}