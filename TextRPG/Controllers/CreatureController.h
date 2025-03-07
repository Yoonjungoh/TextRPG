#pragma once
#include <string>

enum class CreatureType
{
	None,
	Player,
	Monster,
}; 

enum class AttackType  // 후에 필요하면 플레이어, 몬스터 타입 나누면 될듯
{
	None,
	Common,
	Special,
};

class CreatureController
{
public:
	virtual void OnDamaged(CreatureController* attacker, AttackType attackType);
	virtual int CalculateDamageByAttackType(CreatureController* attacker, AttackType attackType);
	virtual void OnDead(CreatureController* attacker);
	virtual bool IsDead();

	int GetMaxHp();
	int GetHp();
	int GetAttack();
	int GetSpecialAttackSuccessProbability();
	int GetDefense();
	std::string GetName();

	void PrintInfo();

protected:
	CreatureController(CreatureType creatureType);  // 직접 생성되는 거 막음
	virtual ~CreatureController();

	void SetHp(int hp);

	int _maxHp;
	int _hp;
	int _attack;
	int _specialAttackSuccessProbability;	// 10이면 특수공격 성공 확률 10%로 설정
	int _defense;
	std::string _name;
	CreatureType _creatureType;
};