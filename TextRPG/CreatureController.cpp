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
	int totalDamage =  std::max(0, attacker->GetAttack() - this->GetDefense());

	// ���� ���, ���� ������ �������� ȸ���Ǵ� ��� ����
	int totalHp = this->GetHp() - totalDamage;
	if (totalHp < 0)
	{
		totalHp = 0;
	}
	this->SetHp(totalHp);

	std::ostringstream oss;
	oss << attacker->GetName() << "���� " << this->GetName() << "�� " << totalDamage << "�� ���ظ� �Ծ� "
		<< "ü���� " << this->GetHp() << "����";
	std::cout << oss.str() << std::endl;

	if (this->IsDead())
	{
		this->OnDead(attacker);
	}
}

void CreatureController::OnDead(CreatureController* attacker)
{
	std::ostringstream oss;
	oss << attacker->GetName() << "���� " << this->GetName() << "�� " << "����";
	std::cout << oss.str() << std::endl;
}

bool CreatureController::IsDead()
{
	return (_hp <= 0);
}

int CreatureController::GetHp()
{
	return _hp;
}

int CreatureController::GetAttack()
{
	return _attack;
}

int CreatureController::GetDefense()
{
	return std::max(0, _defense);  // �ּ� ���� �����ؼ� defense�� ���� ȸ�� ����
}

std::string CreatureController::GetName()
{
	return _name;
}

void CreatureController::SetHp(int hp)
{
	_hp = hp;
}

void CreatureController::PrintInfo()
{
	std::ostringstream oss;
	oss << "\n================���� ���===============\n";
	oss << "�̸�: " << this->GetName() << '\n';
	oss << "ü��: " << this->GetHp() << '\n';
	oss << "���ݷ�: " << this->GetAttack() << '\n';
	oss << "����: " << this->GetDefense() << '\n';
	std::cout << oss.str() << std::endl;
}