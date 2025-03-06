#include "CreatureController.h"
#include <sstream>
#include <iostream>

CreatureController::CreatureController(CreatureType creatureType)
	:_creatureType(creatureType), _hp(0), _attack(0), _defense(0), _name("")
{

}

CreatureController::~CreatureController()
{

}

void CreatureController::OnDamaged(CreatureController *attacker)
{
	// 방어력만큼 공격자의 데미지 차감
	int totalDamage =  std::max(0, attacker->getAttack() - this->getDefense());

	// 방어력 계산, 이후 데미지 음수여서 회복되는 경우 방지
	int totalHp = this->getHp() - totalDamage;
	if (totalHp < 0)
	{
		totalHp = 0;
	}
	this->setHp(totalHp);

	std::ostringstream oss;
	oss << attacker->getName() << "에게 " << this->getName() << "가 " << totalDamage << "의 피해를 입어 "
		<< "체력이 " << this->getHp() << "남음";
	std::cout << oss.str() << std::endl;

	if (this->IsDead())
	{
		this->OnDead(attacker);
	}
}

void CreatureController::OnDead(CreatureController* attacker)
{
	std::ostringstream oss;
	oss << attacker->getName() << "에게 " << this->getName() << "가 " << "죽음";
	std::cout << oss.str() << std::endl;
}

bool CreatureController::IsDead()
{
	return (_hp <= 0);
}

int CreatureController::getHp()
{
	return _hp;
}

int CreatureController::getAttack()
{
	return _attack;
}

int CreatureController::getDefense()
{
	return std::max(0, _defense);  // 최소 방어력 보장해서 defense로 인한 회복 방지
}

std::string CreatureController::getName()
{
	return _name;
}

void CreatureController::setHp(int hp)
{
	_hp = hp;
}