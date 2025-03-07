#include "SkeletonController.h"


SkeletonController::SkeletonController() 
	: MonsterController(MonsterType::Skeleton)
{
	_maxHp = 40;
	_hp = 40;
	_attack = 4;
	_specialAttackSuccessProbability = 3;
	_defense = 2;
	_name = "½ºÄÌ·¹Åæ";

	PrintInfo();
}