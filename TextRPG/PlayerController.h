#pragma once

#include "CreatureController.h"

enum class PlayerType
{
	None,
	Knight,
	Archer,
	Mage,
};

class PlayerController : public CreatureController
{
protected:
	PlayerController(PlayerType playerType) : CreatureController(CreatureType::Player), _playerType(playerType)
	{

	}

	virtual ~PlayerController()
	{

	}

	PlayerType _playerType;
};