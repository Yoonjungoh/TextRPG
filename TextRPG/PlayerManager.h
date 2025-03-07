#pragma once
// 직업 추가될 때마다 헤더 추가랑 _playerTypeMap만 수정하면 됨
#include "PlayerController.h"
#include "KnightController.h"
#include "ArcherController.h"
#include "MageController.h"

#include "Singleton.h"

#include <unordered_map>
#include <memory>
#include <functional>

class PlayerManager : public Singleton<PlayerManager>
{
public:
    // Player는 이 게임에서는 하나만 존재한다고 가정해서 unique 포인터 사용
    std::unique_ptr<PlayerController> CreatePlayer(PlayerType playerType);

    void SetPlayer(std::unique_ptr<PlayerController> player);

private:
    friend class Singleton<PlayerManager>;

    PlayerManager();
    ~PlayerManager();

    std::unique_ptr<PlayerController> _player;  // Player가 유일하다고 판단

    const std::unordered_map<PlayerType, std::function<std::unique_ptr<PlayerController>()>>
        _playerTypeMap;
};