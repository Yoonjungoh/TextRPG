#include "CreatureController.h"
#include <sstream>
#include <iostream>
#include "RandomUtil.h"

CreatureController::CreatureController(CreatureType creatureType)
	:_creatureType(creatureType), _maxHp(0), _hp(0), _attack(0), _specialAttackSuccessProbability(0),
	_defense(0), _name("")
{

}

CreatureController::~CreatureController()
{

}

void CreatureController::OnDamaged(CreatureController *attacker, AttackType attackType)
{
	// 방어력만큼 공격자의 데미지 차감
	int totalDamage = CalculateDamageByAttackType(attacker, attackType);

	// 방어력 계산, 이후 데미지 음수여서 회복되는 경우 방지
	int totalHp = this->GetHp() - totalDamage;
	if (totalHp < 0)
	{
		totalHp = 0;
	}
	this->SetHp(totalHp);

	std::ostringstream oss;
	oss << "\n======================================\n";
	oss << attacker->GetName() << "에게 " << this->GetName() << "(이)가 " << totalDamage << "의 피해를 입어 "
		<< "체력이 " << this->GetHp() << "남음";
	std::cout << oss.str() << std::endl;

	if (this->IsDead())
	{
		this->OnDead(attacker);
	}
}

int CreatureController::CalculateDamageByAttackType(CreatureController* attacker, AttackType attackType)
{
	int totalDamage = 0;

	switch (attackType)
	{
		case AttackType::Common:
			totalDamage = std::max(0, attacker->GetAttack() - this->GetDefense());
			break;
		case AttackType::Special:
			// 즉사 공격이 성공했는지 우선 판단
			// 즉사 공격 데미지는 맞는 생명체의 최대 체력 + 방어력으로 상정
			if (RandomUtil::IsSuccess(attacker->GetSpecialAttackSuccessProbability()))
			{
				totalDamage = this->GetMaxHp() + this->GetDefense();
			}
			break;
	}

	return totalDamage;
}

void CreatureController::OnDead(CreatureController* attacker)
{
	std::ostringstream oss;
	oss << attacker->GetName() << "에게 " << this->GetName() << "(이)가 " << "죽음";
	std::cout << oss.str() << std::endl;
}

bool CreatureController::IsDead()
{
	return (_hp <= 0);
}

int CreatureController::GetMaxHp()
{
	return _hp;
}

int CreatureController::GetHp()
{
	return _hp;
}

int CreatureController::GetAttack()
{
	return _attack;
}

int CreatureController::GetSpecialAttackSuccessProbability()
{
	return _specialAttackSuccessProbability;
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