
#include "PlayerManager.h"

PlayerManager::PlayerManager()
    : _player(nullptr),
    _playerTypeMap 
    {
        {PlayerType::Knight, []() { return std::make_unique<KnightController>(); }},
        {PlayerType::Archer, []() { return std::make_unique<ArcherController>(); }},
        {PlayerType::Mage,   []() { return std::make_unique<MageController>(); }}
    }
{

}

PlayerManager::~PlayerManager()
{

}

// Player는 이 게임에서는 하나만 존재한다고 가정해서 unique 포인터 사용
std::unique_ptr<PlayerController> PlayerManager::CreatePlayer(PlayerType playerType)
{
    auto it = _playerTypeMap.find(playerType);

    return (it != _playerTypeMap.end()) ? it->second() : nullptr;
}

PlayerController* PlayerManager::GetPlayer()
{
    // 소유권 이전이 아니라서 move가 아닌 get써서 유니크 포인터에서 원본 포인터 반환함
    return _player.get();
}

void PlayerManager::SetPlayer(std::unique_ptr<PlayerController> player)
{
    _player = std::move(player);
}