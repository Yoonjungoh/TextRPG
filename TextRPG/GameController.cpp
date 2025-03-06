#include "PlayerFactory.h"
#include "GameController.h"
#include <sstream>
#include <iostream>

GameController::GameController()
{
	std::ostringstream oss;
	oss << "-------------------------게임 시작---------------------------";
	std::cout << std::endl << oss.str() << std::endl;
}

GameController::~GameController()
{
	std::ostringstream oss;
	oss << "-------------------------게임 종료-------------------------";
	std::cout << std::endl << oss.str() << std::endl;
}

void GameController::Init()
{
	int characterType;
	std::ostringstream oss;

	oss << "\n---------------------캐릭터 선택-------------------------\n";
	oss << "\n[1] 전사\n";
	oss << "\n[2] 궁수\n";
	oss << "\n[3] 마법사\n";

	std::cout << oss.str();

	std::cin >> characterType;

	// 숫자로 해도 되지만 명시적 가독성 위해서 캐스팅 한 번 해줌
	PlayerType playerType = static_cast<PlayerType>(characterType);
	_player = PlayerFactory::CreatePlayer(playerType);
}

void GameController::Update()
{

}

