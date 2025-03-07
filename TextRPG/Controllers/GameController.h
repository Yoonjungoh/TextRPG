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

	// ����ڿ��� ���� Ÿ���� �Է� �޾� �ٲ�
	void ChoosePlayerTypeByUser(const std::unordered_map<int, PlayerType>& optionMap);

	// ����ڿ��� �ʵ� Ÿ���� �Է� �޾� �ٲ�
	void ChooseFieldTypeByUser(const std::unordered_map<int, FieldType>& optionMap);

	// ����ڿ��� ���� Ÿ���� �Է� �޾� �ٲ�
	void ChooseAttackTypeByUser(const std::unordered_map<int, AttackType>& optionMap);

	// ���� �� �Ͼ� ���� ���� (�÷��̾� ���� ���� �����ϰ� ���Ŀ� ���Ͱ� ���� ����)
	// attackType�� �÷��̾ ����� (���ʹ� Common�� ����)
	void ProcessAttack(AttackType attackType);

private:
	std::ostringstream _oss;	// stream ����
};