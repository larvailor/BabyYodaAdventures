#ifndef GAME_HPP
#define GAME_HPP

#include "Scene_Game.hpp"
#include "Scene_MainMenu.hpp"

class Game
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	/* The main render taregt of the game. All stuff should be drawn here */
	shared<sf::RenderWindow> m_renderWindow;

	sf::Event m_event;

	/* Used for calculating a one frame duration */
	sf::Clock m_frameTimeClock;

	/* Shows how much time in milliseconds is needed to update and render one frame */
	float m_frameTime;

	/* A shared stack of scenes. Used for managing current scene update and render logic */
	shared_stack<shared<Scene>> m_scenes;

	/* A shared map of all supported keys */
	shared_map<std::string, sf::Keyboard::Key> m_supportedKeys;

	//-----------------------------------------------
	//		Debug
	//

	sf::Clock m_fpsClock;
	sf::Font m_debugFont;
	sf::Text m_debugFrameTime;
	sf::Text m_debugFps;
	int m_fpsCounter;
	int m_fps;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	/**
		Loads window configuration from window.ini file.
		Sets up default if failed to load
	*/
	void initWindow();

	/**
		Loads all supported keys from SupportedKeys.ini file
		and creates an std::map of supported keys and their codes
	*/
	void initSupportedKeys();

	/**
		Pushes the first game scene into the stack of scenes.
		Should be called only when all supported keys were loaded!
	*/
	void initScenes();
	void initDebugVars();

	//-----------------------------------------------
	//		Update
	//

	/**
		Main game update method. Calls to all other update methods
	*/
	void update();
	void pollEvents();

	/**
		Tooks the top item on the stack of scenes and calls its update method.
		If the scene should be closed, then calls its finalize method and pops from stack.
		If there are no scenes, then calls to close method on render window
	*/
	void updateScenes();

	/**
		Calculates how much time is needed to update and render one frame
		and stores the result in private m_frameTime member
	*/
	void calculateFrameTime();

	/**
		Calculates how much times the scene was redrawn in one second
	*/
	void calculateFps();

	//-----------------------------------------------
	//		Render
	//

	/**
		Main game render method.
		1. Clears the main window
		2. Calls to all render methods
		3. Displays the result
	*/
	void render();

	/**
		Tooks the top item on the stack of scenes and calls its render method
	*/
	void renderScenes();
	void renderDebugInfo();

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//
	
	Game();

	//-----------------------------------------------
	//		Destructors
	//

	~Game();

	//-----------------------------------------------
	//		Else
	//

	/*
		Game loop. Calls to the main update and render methods and
		calculates the real frame time
	*/
	void run();
};

#endif
