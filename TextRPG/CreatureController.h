#pragma once
#include <string>

enum class CreatureType
{
	None,
	Player,
	Monster,
}; 

enum class AttackType  // �Ŀ� �ʿ��ϸ� �÷��̾�, ���� Ÿ�� ������ �ɵ�
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
	CreatureController(CreatureType creatureType);  // ���� �����Ǵ� �� ����
	virtual ~CreatureController();

	void SetHp(int hp);

	int _maxHp;
	int _hp;
	int _attack;
	int _specialAttackSuccessProbability;	// 10�̸� Ư������ ���� Ȯ�� 10%�� ����
	int _defense;
	std::string _name;
	CreatureType _creatureType;
};