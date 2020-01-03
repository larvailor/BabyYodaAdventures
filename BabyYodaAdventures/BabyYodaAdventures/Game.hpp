#ifndef GAME_HPP
#define GAME_HPP

#include "GameState.hpp"
#include "MainMenuState.hpp"

class Game
{
private:
	/////////////////////
	// Variables
	//

	std::shared_ptr<sf::RenderWindow> m_renderWindow;
	sf::Event m_event;

	sf::Clock m_frameTimeClock;
	float m_frameTime;

	std::stack<std::shared_ptr<State>> m_states;

	std::map<std::string, sf::Keyboard::Key> m_supportedKeys;



	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initKeys();
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
