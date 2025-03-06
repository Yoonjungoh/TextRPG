
#include "PlayerFactory.h"

std::unique_ptr<PlayerController> PlayerFactory::CreatePlayer(PlayerType type)
{
    static const std::unordered_map<PlayerType, std::function<std::unique_ptr<PlayerController>()>> factoryMap =
    {
        {PlayerType::Knight, []() { return std::make_unique<KnightController>(); }},
        {PlayerType::Archer, []() { return std::make_unique<ArcherController>(); }},
        {PlayerType::Mage,   []() { return std::make_unique<MageController>(); }}
    };

    auto it = factoryMap.find(type);
    return (it != factoryMap.end()) ? it->second() : nullptr;
}