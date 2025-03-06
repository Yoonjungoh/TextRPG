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
	// ���¸�ŭ �������� ������ ����
	int totalDamage =  std::max(0, attacker->getAttack() - this->getDefense());

	// ���� ���, ���� ������ �������� ȸ���Ǵ� ��� ����
	int totalHp = this->getHp() - totalDamage;
	if (totalHp < 0)
	{
		totalHp = 0;
	}
	this->setHp(totalHp);

	std::ostringstream oss;
	oss << attacker->getName() << "���� " << this->getName() << "�� " << totalDamage << "�� ���ظ� �Ծ� "
		<< "ü���� " << this->getHp() << "����";
	std::cout << oss.str() << std::endl;

	if (this->IsDead())
	{
		this->OnDead(attacker);
	}
}

void CreatureController::OnDead(CreatureController* attacker)
{
	std::ostringstream oss;
	oss << attacker->getName() << "���� " << this->getName() << "�� " << "����";
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
	return std::max(0, _defense);  // �ּ� ���� �����ؼ� defense�� ���� ȸ�� ����
}

std::string CreatureController::getName()
{
	return _name;
}

void CreatureController::setHp(int hp)
{
	_hp = hp;
}