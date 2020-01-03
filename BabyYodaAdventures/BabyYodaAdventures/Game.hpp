#ifndef GAME_HPP
#define GAME_HPP

#include "States/GameState.hpp"

class Game
{
private:
	/////////////////////
	// Variables
	//

	std::shared_ptr<sf::RenderWindow> m_renderWindow;
	std::shared_ptr<sf::Event> m_event;

	sf::Clock m_frameTimeClock;
	float m_frameTime;

	std::stack<std::shared_ptr<State>> m_states;



	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initEvent();
	void initStates();

	// Update

	void update();
	void pollEvents();
	void updateStates();
	void calculateFrameTime();

	// Render

	void render();
	void renderStates();

public:
	/////////////////////
	// Methods
	//

	// Constructors
	
	Game();

	// Destructors

	~Game();

	// Else methods

	void run();
};

#endif
