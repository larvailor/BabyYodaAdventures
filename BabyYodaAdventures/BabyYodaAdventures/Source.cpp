#include "Game.hpp"

int main()
{
	auto game = std::make_unique<Game>();

	game->run();

	return 0;
}