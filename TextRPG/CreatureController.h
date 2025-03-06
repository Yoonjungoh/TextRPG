#pragma once
#include <string>

enum class CreatureType
{
	None,
	Player,
	Monster,
};

class CreatureController
{
public:
	virtual void OnDamaged(CreatureController *attacker);
	virtual void OnDead(CreatureController* attacker);
	virtual bool IsDead();

	int getHp();
	int getAttack();
	int getDefense();
	std::string getName();

protected:
	CreatureController(CreatureType creatureType);  // 직접 생성되는 거 막음
	~CreatureController();

	void setHp(int hp);

	int _hp;
	int _attack;
	int _defense;
	std::string _name;
	CreatureType _creatureType;
};