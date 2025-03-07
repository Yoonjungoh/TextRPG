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

	// 사용자에게 공격 타입을 입력 받아 바꿈
	void ChooseAttackTypeByUser(const std::unordered_map<int, AttackType>& optionMap);

	// 서로 한 턴씩 공격 실행 (플레이어 먼저 공격 진행하고 이후에 몬스터가 공격 진행)
	// attackType은 플레이어만 적용됨 (몬스터는 Common만 적용)
	void ProcessAttack(AttackType attackType);

private:
	std::ostringstream _oss;	// stream 재사용
};