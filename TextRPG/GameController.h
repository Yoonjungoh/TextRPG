#pragma once

#include <memory>
#include <sstream>
#include <unordered_map>
#include "PlayerController.h"
#include "FieldManager.h"

class GameController
{
public:
	GameController();
	~GameController();

	void Init();

	void Update();
	void UpdateLobby();
	void UpdateVillage();
	void UpdateForest();
	void UpdateBattle();

	// 사용자에게 직업 타입을 입력 받아 바꿈
	void ChoosePlayerTypeByUser(const std::unordered_map<int, PlayerType>& optionMap);

	// 사용자에게 필드 타입을 입력 받아 바꿈
	void ChooseFieldTypeByUser(const std::unordered_map<int, FieldType>& optionMap);

private:
	std::ostringstream _oss;	// stream 재사용
};