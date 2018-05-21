#include "engine/game.h"

int main(int argc, char const *argv[])
{
	MainWindow window;
	Game game(window);

	game.go();

	return 0;
}
