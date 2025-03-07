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
	int totalDamage =  std::max(0, attacker->GetAttack() - this->GetDefense());

	// 방어력 계산, 이후 데미지 음수여서 회복되는 경우 방지
	int totalHp = this->GetHp() - totalDamage;
	if (totalHp < 0)
	{
		totalHp = 0;
	}
	this->SetHp(totalHp);

	std::ostringstream oss;
	oss << attacker->GetName() << "에게 " << this->GetName() << "가 " << totalDamage << "의 피해를 입어 "
		<< "체력이 " << this->GetHp() << "남음";
	std::cout << oss.str() << std::endl;

	if (this->IsDead())
	{
		this->OnDead(attacker);
	}
}

void CreatureController::OnDead(CreatureController* attacker)
{
	std::ostringstream oss;
	oss << attacker->GetName() << "에게 " << this->GetName() << "가 " << "죽음";
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
	return std::max(0, _defense);  // 최소 방어력 보장해서 defense로 인한 회복 방지
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
	oss << "\n================정보 출력===============\n";
	oss << "이름: " << this->GetName() << '\n';
	oss << "체력: " << this->GetHp() << '\n';
	oss << "공격력: " << this->GetAttack() << '\n';
	oss << "방어력: " << this->GetDefense() << '\n';
	std::cout << oss.str() << std::endl;
}