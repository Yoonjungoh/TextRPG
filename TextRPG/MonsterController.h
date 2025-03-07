#pragma once

#include "CreatureController.h"

enum class MonsterType
{
	None,
	Slime,
	Skeleton,
	Dragon,
};

class MonsterController : public CreatureController
{
public:
	MonsterController(MonsterType monsterType);
	~MonsterController();

protected:
	MonsterType _monsterType;
};