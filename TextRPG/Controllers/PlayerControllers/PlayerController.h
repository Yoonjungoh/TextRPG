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
public:
	PlayerController(PlayerType playerType);
	~PlayerController();

protected:
	PlayerType _playerType;
};