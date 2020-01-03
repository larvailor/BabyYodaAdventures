#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"

class GameState : public State
{
private:

public:
	/////////////////////
	// Methods
	//

	// Constructors

	GameState(std::shared_ptr<sf::RenderWindow> renderWindow);

	// Destructors

	virtual ~GameState();

	// Udate

	void update(const float& frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing state

	void endState();
};

#endif
