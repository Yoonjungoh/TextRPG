#include "PlayerFactory.h"
#include "GameController.h"
#include <sstream>
#include <iostream>

GameController::GameController()
{
	std::ostringstream oss;
	oss << "-------------------------���� ����---------------------------";
	std::cout << std::endl << oss.str() << std::endl;
}

GameController::~GameController()
{
	std::ostringstream oss;
	oss << "-------------------------���� ����-------------------------";
	std::cout << std::endl << oss.str() << std::endl;
}

void GameController::Init()
{
	int characterType;
	std::ostringstream oss;

	oss << "\n---------------------ĳ���� ����-------------------------\n";
	oss << "\n[1] ����\n";
	oss << "\n[2] �ü�\n";
	oss << "\n[3] ������\n";

	std::cout << oss.str();

	std::cin >> characterType;

	// ���ڷ� �ص� ������ ����� ������ ���ؼ� ĳ���� �� �� ����
	PlayerType playerType = static_cast<PlayerType>(characterType);
	_player = PlayerFactory::CreatePlayer(playerType);
}

void GameController::Update()
{

}

