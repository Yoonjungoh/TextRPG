#pragma once
// 직업 추가될 때마다 헤더랑 factoryMap만 수정하면 됨
#include "PlayerController.h"
#include "KnightController.h"
#include "ArcherController.h"
#include "MageController.h"

#include <unordered_map>
#include <memory>
#include <functional>

class PlayerFactory
{
public:
    static std::unique_ptr<PlayerController> CreatePlayer(PlayerType type);
};