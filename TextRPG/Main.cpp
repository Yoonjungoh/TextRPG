
#include "GameController.h"
#include <chrono>
#include <thread>

int main()
{
	GameController gameController;
	gameController.Init();

	while (true)
	{
		gameController.Update();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}