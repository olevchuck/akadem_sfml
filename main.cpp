#include "game.h"

void gameRunning() {
	if (startGame()) { gameRunning(); }
}

int main()
{
	gameRunning();

	return 0;
}