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
	std::unique_ptr<PlayerController> _player;  // Player�� �����ϴٰ� �Ǵ�
};