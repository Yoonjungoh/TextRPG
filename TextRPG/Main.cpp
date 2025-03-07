
#include "GameController.h"

int main()
{
	GameController gameController;
	gameController.Init();

	while (true)
	{
		gameController.Update();
	}
}