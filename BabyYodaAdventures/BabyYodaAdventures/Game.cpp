#include "Game.hpp"

#include "ConfigHelper.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

/**
	Loads window configuration from window.ini file.
	Sets up default if failed to load
*/
void Game::initWindow()
{
	// Setting default values

	std::string title = "Baby Yoda Adventures";
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	unsigned fps = 60;
	bool verticalSync = false;
	bool fullScreen = false;
	sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;

	// Reading config from file

	std::ifstream ifs;
	ifs.open(WINDOW_CONFIG_PATH);
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> videoMode.width >> videoMode.height;
		ifs >> fps;
		ifs >> verticalSync;
		ifs >> fullScreen;
	}
	ifs.close();

	if (fullScreen) { style = sf::Style::Fullscreen; }

	// Setting up window

	m_renderWindow = std::make_shared<sf::RenderWindow>(videoMode, title, style);
	m_renderWindow->setFramerateLimit(fps);
	m_renderWindow->setVerticalSyncEnabled(verticalSync);
}

/**
	Loads all supported keys from SupportedKeys.ini file 
	and creates an std::map of supported keys and their codes
*/
void Game::initSupportedKeys()
{
	m_supportedKeys = std::make_shared<std::map<std::string, sf::Keyboard::Key>>();

	std::ifstream ifs;
	ifs.open(SUPPORTED_KEYS_CONFIG_PATH);
	if (ifs.is_open())
	{
		std::string key_name;
		int key_code;
		while (ifs >> key_name >> key_code)
		{
			m_supportedKeys.get()->emplace(key_name, static_cast<sf::Keyboard::Key>(key_code));
		}

	}
	else
	{
		std::cout << "ERROR::Game::initSupportedKeys failed to load supported keys" << std::endl;
	}
	ifs.close();
}

/**
	Pushes the first game scene into the stack of scenes.
	Should be called only when all supported keys were loaded!
*/
void Game::initScenes()
{
	m_scenes = std::make_shared<std::stack<shared<Scene>>>();

	auto scene = std::make_shared<Scene_MainMenu>(m_renderWindow, m_scenes, m_supportedKeys);
	m_scenes.get()->push(std::move(scene));
}



//-----------------------------------------------
//		Update
//

/*
	Main game update method. Calls to all other update methods
*/
void Game::update()
{
	pollEvents();
	updateScenes();
}

void Game::pollEvents()
{
	while (m_renderWindow->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			this->m_renderWindow->close();
			break;
		}
	}
}

/**
	Tooks the top item on the stack of scenes and calls its update method.
	If the scene should be closed, then calls its finalize method and pops from stack.
	If there are no scenes, then calls to close method on render window
*/
void Game::updateScenes()
{
	if (!m_scenes.get()->empty())
	{
		m_scenes.get()->top()->update(m_frameTime);

		if (m_scenes.get()->top()->needToBeClosed())
		{
			m_scenes.get()->top()->finalizeScene();
			m_scenes.get()->pop();
		}
	}
	else
	{
		m_renderWindow->close();
	}
}

/**
	Calculates how much time is needed to update and render one frame
	and stores the result in private m_frameTime member
*/
void Game::calculateFrameTime()
{
	m_frameTime = m_frameTimeClock.restart().asSeconds();

	//system("cls");
	//std::cout << "Frame time: " << m_frameTime << std::endl;
}



//-----------------------------------------------
//		Render
//

/**
	Main game render method.
	1. Clears the main window
	2. Calls to all render methods
	3. Displays the result
*/
void Game::render()
{
	m_renderWindow->clear();

	// render all stuff here
	renderScenes();

	m_renderWindow->display();
}

/**
	Tooks the top item on the stack of scenes and calls its render method
*/
void Game::renderScenes()
{
	if (!m_scenes.get()->empty())
	{
		m_scenes.get()->top()->render();
	}
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Game::Game()
{
	initWindow();
	initSupportedKeys();
	initScenes();
}



//-----------------------------------------------
//		Destructors
//

Game::~Game()
= default;



//-----------------------------------------------
//		Else methods
//

/*
	Game loop. Calls to the main update and render methods and
	calculates the real frame time
*/
void Game::run()
{
	while (m_renderWindow->isOpen())
	{
		update();
		render();

		calculateFrameTime();
	}
}
