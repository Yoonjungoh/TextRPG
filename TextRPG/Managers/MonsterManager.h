#pragma once

// ���� �߰��� ������ ��� �߰��� _monsterTypeMap�� �����ϸ� ��
#include "MonsterController.h"
#include "SlimeController.h"
#include "SkeletonController.h"
#include "DragonController.h"

#include "Singleton.h"

#include <unordered_map>
#include <memory>
#include <functional>

class MonsterManager : public Singleton<MonsterManager>
{
public:
    std::unique_ptr<MonsterController> CreateRandomMonster();  // ���� ���� ��ȯ�� �̰͸� ���
    std::unique_ptr<MonsterController> CreateMonster(MonsterType monsterType);  // �Ŀ� ���� ���� ��ȯ ���� �� ������ public���� ����
    MonsterController* GetMonster();

    // ������ ���� �� ���� ���� ����
    // �����ָ� ����ũ ������ ��ü�� ������
    void SetMonster(std::unique_ptr<MonsterController>&& monster);

private:
    friend class Singleton<MonsterManager>;

    MonsterManager();
    ~MonsterManager();

    // Monser�� �� ���ӿ����� �ϳ��� �����Ѵٰ� �����ؼ� unique ������ ���
    std::unique_ptr<MonsterController> _monster;

    const std::unordered_map<MonsterType, std::function<std::unique_ptr<MonsterController>()>>
        _monsterTypeMap;  // Monster Ÿ�Կ� ���� Controller ����

    std::vector<MonsterType> _monsterTypeVector; // _monsterTypeMap�� Ű���� ���� (���� ���� ���� �뵵)
};