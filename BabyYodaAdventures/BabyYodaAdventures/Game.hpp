#ifndef GAME_HPP
#define GAME_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Game
{
private:
	/////////////////////
	// Variables
	//

	std::unique_ptr<sf::RenderWindow> m_renderWindow;
	std::unique_ptr<sf::Event> m_event;



	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initEvent();

	// Update

	void update();

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
