#include "GameController.h"

#include "PlayerManager.h"
#include "MonsterManager.h"
#include "FieldManager.h"
#include <iostream>

GameController::GameController()
{
	_oss << "-------------------------���� ����---------------------------";
	std::cout << std::endl << _oss.str() << std::endl;

	_oss.clear();
	_oss.str("");
}

GameController::~GameController()
{
	_oss << "-------------------------���� ����-------------------------";
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
			std::cout << "���� �ʵ� Ÿ�� �߻�\n";
			exit(0);
	}
}

void GameController::UpdateLobby()
{
	int playerTypeInt;

	_oss << "\n---------------------ĳ���� ����-------------------------\n";
	_oss << "\n[1] ����\n";
	_oss << "\n[2] �ü�\n";
	_oss << "\n[3] ������\n";

	std::cout << _oss.str();

	ChoosePlayerTypeByUser
	({
		{1, PlayerType::Knight},
		{2, PlayerType::Archer},
		{3, PlayerType::Mage}
	});

	// ������ �̵�
	FieldManager::GetInstance().SetFieldType(FieldType::Village);

	_oss.clear();
	_oss.str("");
}

void GameController::UpdateVillage()
{
	int fieldTypeInt;

	_oss << "\n---------------------�ʵ� ����-------------------------\n";
	_oss << "\n[1] �κ� (���� �缱��)\n";
	_oss << "\n[2] �� (���Ϳ� ����)\n";

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
	// ���� ���� ����
	std::unique_ptr<MonsterController> randomMonster = MonsterManager::GetInstance().CreateRandomMonster();
	MonsterManager::GetInstance().SetMonster(std::move(randomMonster));

	// ���� ���� â
	int fieldTypeInt;

	_oss << "\n---------------------���� ����-------------------------\n";
	_oss << "\n[1] ���� (��Ʋ ����)\n";
	_oss << "\n[2] ���� (������ ����)\n";

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
		// ���ڷ� �ص� ������ ����� ������ ���ؼ� ĳ���� �� �� ����
		PlayerType playerType = static_cast<PlayerType>(playerTypeInt);
		std::unique_ptr<PlayerController> player = PlayerManager::GetInstance().CreatePlayer(playerType);
		if (player == nullptr)
		{
			std::cout << "���� ���� Ÿ�� �߻�\n���α׷� ����\n";
			exit(0);
		}

		PlayerManager::GetInstance().SetPlayer(std::move(player));
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�\n������ �����մϴ�\n";
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
		std::cout << "�߸��� �Է��Դϴ�\n������ �����մϴ�\n";
		exit(0);
	}
}

