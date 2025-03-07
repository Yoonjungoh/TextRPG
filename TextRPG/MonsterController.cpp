#pragma once

#include "CreatureController.h"
#include "MonsterController.h"



MonsterController::MonsterController(MonsterType monsterType)
	: CreatureController(CreatureType::Monster), 
	_monsterType(monsterType)
{

}

MonsterController::~MonsterController()
{

}