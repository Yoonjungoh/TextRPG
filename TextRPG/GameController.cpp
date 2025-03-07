#include "GameController.h"

#include "PlayerManager.h"
#include "MonsterManager.h"
#include "FieldManager.h"
#include <iostream>

GameController::GameController()
{
	_oss << "-------------------------게임 시작---------------------------";
	std::cout << std::endl << _oss.str() << std::endl;

	_oss.clear();
	_oss.str("");
}

GameController::~GameController()
{
	_oss << "-------------------------게임 종료-------------------------";
	std::cout << std::endl << _oss.str() << std::endl;

	_oss.clear();
	_oss.str("");
}

void GameController::Init()
{
	FieldManager::GetInstance().SetFieldType(FieldType::Lobby);
}

void GameController::Update()
{
	switch (FieldManager::GetInstance().GetFieldType())
	{
		case FieldType::Lobby:
			UpdateLobby();
			break;
		case FieldType::Village:
			UpdateVillage();
			break;
		case FieldType::Forest:
			UpdateForest();
			break;
		case FieldType::Battle:
			UpdateBattle();
			break;
		default:
			std::cout << "에러 필드 타입 발생\n";
			exit(0);
	}
}

void GameController::UpdateLobby()
{
	int playerTypeInt;

	_oss << "\n---------------------캐릭터 선택-------------------------\n";
	_oss << "\n[1] 전사\n";
	_oss << "\n[2] 궁수\n";
	_oss << "\n[3] 마법사\n";

	std::cout << _oss.str();

	ChoosePlayerTypeByUser
	({
		{1, PlayerType::Knight},
		{2, PlayerType::Archer},
		{3, PlayerType::Mage}
	});

	// 마을로 이동
	FieldManager::GetInstance().SetFieldType(FieldType::Village);

	_oss.clear();
	_oss.str("");
}

void GameController::UpdateVillage()
{
	int fieldTypeInt;

	_oss << "\n---------------------필드 선택-------------------------\n";
	_oss << "\n[1] 로비 (직업 재선택)\n";
	_oss << "\n[2] 숲 (몬스터와 전투)\n";

	std::cout << _oss.str();

	ChooseFieldTypeByUser
	({
		{1, FieldType::Lobby},
		{2, FieldType::Forest}
	});

	_oss.clear();
	_oss.str("");
}

void GameController::UpdateForest()
{
	// 랜덤 몬스터 생성
	std::unique_ptr<MonsterController> randomMonster = MonsterManager::GetInstance().CreateRandomMonster();
	MonsterManager::GetInstance().SetMonster(std::move(randomMonster));

	// 유저 선택 창
	int fieldTypeInt;

	_oss << "\n---------------------전투 선택-------------------------\n";
	_oss << "\n[1] 전투 (배틀 진입)\n";
	_oss << "\n[2] 도망 (마을로 도망)\n";

	std::cout << _oss.str();

	ChooseFieldTypeByUser
	({
		{1, FieldType::Battle},
		{2, FieldType::Village}
	});


	_oss.clear();
	_oss.str("");
}

void GameController::UpdateBattle()
{

}


void GameController::ChoosePlayerTypeByUser(const std::unordered_map<int, PlayerType>& optionMap)
{
	int playerTypeInt;
	std::cin >> playerTypeInt;

	auto it = optionMap.find(playerTypeInt);
	if (it != optionMap.end())
	{
		// 숫자로 해도 되지만 명시적 가독성 위해서 캐스팅 한 번 해줌
		PlayerType playerType = static_cast<PlayerType>(playerTypeInt);
		std::unique_ptr<PlayerController> player = PlayerManager::GetInstance().CreatePlayer(playerType);
		if (player == nullptr)
		{
			std::cout << "에러 직업 타입 발생\n프로그램 종료\n";
			exit(0);
		}

		PlayerManager::GetInstance().SetPlayer(std::move(player));
	}
	else
	{
		std::cout << "잘못된 입력입니다\n게임을 종료합니다\n";
		exit(0);
	}
}

void GameController::ChooseFieldTypeByUser(const std::unordered_map<int, FieldType>& optionMap)
{
	int fieldTypeInt;
	std::cin >> fieldTypeInt;

	auto it = optionMap.find(fieldTypeInt);
	if (it != optionMap.end())
	{
		FieldType fieldType = it->second;
		FieldManager::GetInstance().SetFieldType(fieldType);
	}
	else
	{
		std::cout << "잘못된 입력입니다\n게임을 종료합니다\n";
		exit(0);
	}
}

