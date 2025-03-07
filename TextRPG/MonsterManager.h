#pragma once

// 몬스터 추가될 때마다 헤더 추가랑 _monsterTypeMap만 수정하면 됨
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
    std::unique_ptr<MonsterController> CreateRandomMonster();  // 현재 몬스터 소환은 이것만 사용
    std::unique_ptr<MonsterController> CreateMonster(MonsterType monsterType);  // 후에 지정 몬스터 소환 원할 수 있으니 public으로 빼기
    MonsterController* GetMonster();

    // 참조를 통해 값 복사 없이 전달
    // 안해주면 유니크 포인터 객체를 생성함
    void SetMonster(std::unique_ptr<MonsterController>&& monster);

private:
    friend class Singleton<MonsterManager>;

    MonsterManager();
    ~MonsterManager();

    // Monser는 이 게임에서는 하나만 존재한다고 가정해서 unique 포인터 사용
    std::unique_ptr<MonsterController> _monster;

    const std::unordered_map<MonsterType, std::function<std::unique_ptr<MonsterController>()>>
        _monsterTypeMap;  // Monster 타입에 따른 Controller 생성

    std::vector<MonsterType> _monsterTypeVector; // _monsterTypeMap의 키값만 저장 (랜덤 몬스터 생성 용도)
};