
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

// Player�� �� ���ӿ����� �ϳ��� �����Ѵٰ� �����ؼ� unique ������ ���
std::unique_ptr<PlayerController> PlayerManager::CreatePlayer(PlayerType playerType)
{
    auto it = _playerTypeMap.find(playerType);

    return (it != _playerTypeMap.end()) ? it->second() : nullptr;
}

void PlayerManager::SetPlayer(std::unique_ptr<PlayerController> player)
{
    _player = std::move(player);
}