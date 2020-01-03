#ifndef GAME_HPP
#define GAME_HPP

#include "State.hpp"

class Game
{
private:
	/////////////////////
	// Variables
	//

	std::unique_ptr<sf::RenderWindow> m_renderWindow;
	std::unique_ptr<sf::Event> m_event;

	sf::Clock m_frameTimeClock;
	float m_frameTime;


	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initEvent();

	// Update

	void update();
	void pollEvents();
	void calculateFrameTime();

	// Render

	void render();


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
