#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"

class GameState : public State
{
private:
	/////////////////////
	// Variables
	//

	Entity m_player;



	/////////////////////
	// Methods
	//

	// Initialization

	void initKeyBinds();

	// Udate

	void handleInput(const float& frameTime);

public:
	/////////////////////
	// Methods
	//

	// Constructors

	GameState(std::shared_ptr<sf::RenderWindow> renderWindow, std::map<std::string, int>* supportedKeys);

	// Destructors

	virtual ~GameState();

	// Update

	void update(const float& frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing state

	void finalizeState();
};

#endif
