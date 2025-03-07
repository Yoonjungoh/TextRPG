
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

// Monster는 이 게임에서는 하나만 존재한다고 가정해서 unique 포인터 사용
std::unique_ptr<MonsterController> MonsterManager::CreateMonster(MonsterType monsterType)
{
    auto it = _monsterTypeMap.find(monsterType);

    return (it != _monsterTypeMap.end()) ? it->second() : nullptr;
}

MonsterController* MonsterManager::GetMonster()
{
    // 소유권 이전이 아니라서 move가 아닌 get써서 유니크 포인터에서 원본 포인터 반환함
    return _monster.get();
}

void MonsterManager::SetMonster(std::unique_ptr<MonsterController> monster)
{
    _monster = std::move(monster);
}