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

	shared<sf::RenderWindow> m_renderWindow;
	sf::Event m_event;

	sf::Clock m_frameTimeClock;
	float m_frameTime;

	shared_stack<shared<Scene>> m_scenes;

	shared_map<std::string, sf::Keyboard::Key> m_supportedKeys;

	// Debug
	sf::Clock m_fpsClock;

	sf::Font m_debugFont;
	sf::Text m_debugFrameTime;
	sf::Text m_debugFps;
	int m_fpsCounter;
	int m_fps;



	/////////////////////
	// Methods
	//

	// Initialization

	void initWindow();
	void initSupportedKeys();
	void initScenes();
	void initDebugVars();

	// Update

	void update();
	void pollEvents();
	void updateScenes();
	void calculateFrameTime();
	void calculateFps();

	// Render

	void render();
	void renderScenes();
	void renderDebugInfo();

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
