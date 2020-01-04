#ifndef GAME_HPP
#define GAME_HPP

#include "Scene_Game.hpp"
#include "Scene_MainMenu.hpp"

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

	std::stack<std::shared_ptr<Scene>> m_scenes;

	std::map<std::string, sf::Keyboard::Key> m_supportedKeys;



	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initSupportedKeys();
	void initScenes();

	// Update

	void update();
	void pollEvents();
	void updateScenes();
	void calculateFrameTime();

	// Render

	void render();
	void renderScenes();

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
