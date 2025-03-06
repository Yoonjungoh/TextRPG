#pragma once
#include <memory>
class PlayerController;

class GameController
{
public:
	GameController();
	~GameController();
	void Init();
	void Update();

private:
	std::unique_ptr<PlayerController> _player;  // Player가 유일하다고 판단
};