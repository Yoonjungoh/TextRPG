
#include "MonsterManager.h"
#include <random>

MonsterManager::MonsterManager()
    : _monster(nullptr),
    _monsterTypeMap
    {
        {MonsterType::Slime, []() { return std::make_unique<SlimeController>(); }},
        {MonsterType::Skeleton, []() { return std::make_unique<SkeletonController>(); }},
        {MonsterType::Dragon,   []() { return std::make_unique<DragoneController>(); }}
    }
{
    for (const auto& pair : _monsterTypeMap)
    {
        _monsterTypeVector.push_back(pair.first);
    }
}

MonsterManager::~MonsterManager()
{

}

std::unique_ptr<MonsterController> MonsterManager::CreateRandomMonster()
{
    int randomIndex = rand() % _monsterTypeVector.size();
    MonsterType randomMonsterType = _monsterTypeVector[randomIndex];

    return CreateMonster(randomMonsterType);
}

// Monster�� �� ���ӿ����� �ϳ��� �����Ѵٰ� �����ؼ� unique ������ ���
std::unique_ptr<MonsterController> MonsterManager::CreateMonster(MonsterType monsterType)
{
    auto it = _monsterTypeMap.find(monsterType);

    return (it != _monsterTypeMap.end()) ? it->second() : nullptr;
}

MonsterController* MonsterManager::GetMonster()
{
    // ������ ������ �ƴ϶� move�� �ƴ� get�Ἥ ����ũ �����Ϳ��� ���� ������ ��ȯ��
    return _monster.get();
}

void MonsterManager::SetMonster(std::unique_ptr<MonsterController> monster)
{
    _monster = std::move(monster);
}