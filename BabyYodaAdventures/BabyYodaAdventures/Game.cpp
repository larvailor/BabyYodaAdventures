#include "Game.hpp"

#include <fstream>

#include "ConfigHelper.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

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

void Game::initScenes()
{
	m_scenes = std::make_shared<std::stack<shared<Scene>>>();

	auto scene = std::make_shared<Scene_MainMenu>(m_renderWindow, m_scenes, m_supportedKeys);
	m_scenes.get()->push(std::move(scene));
}

void Game::initDebugVars()
{
	// Frame time
	m_debugFont.loadFromFile("Resources/Fonts/star_wars.otf");
	m_debugFrameTime = sf::Text();
	m_debugFrameTime.setFont(m_debugFont);
	m_debugFrameTime.setCharacterSize(16);
	m_debugFrameTime.setFillColor(sf::Color::White);
	m_debugFrameTime.setPosition(5, 5);

	// Fps
	m_fps = 0;

	m_debugFps = sf::Text();
	m_debugFps.setFont(m_debugFont);
	m_debugFps.setCharacterSize(16);
	m_debugFps.setFillColor(sf::Color::White);
	m_debugFps.setPosition(5, 20);

}



//-----------------------------------------------
//		Update
//

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

void Game::updateScenes()
{
	if (!m_scenes.get()->empty())
	{
		m_scenes.get()->top()->update(m_frameTime);

		if (m_scenes.get()->top()->needToBeClosed())
		{
			m_scenes.get()->pop();
		}
	}
	else
	{
		m_renderWindow->close();
	}
}

void Game::calculateFrameTime()
{
	m_debugFrameTime.setString("FT: " + std::to_string(m_frameTime));
	m_frameTime = m_frameTimeClock.restart().asSeconds();
}

void Game::calculateFps()
{
	m_fpsCounter++;
	if (m_fpsClock.getElapsedTime().asSeconds() > 1)
	{
		m_fps = m_fpsCounter;
		m_fpsCounter = 0;
		m_debugFps.setString("FPS: " + std::to_string(m_fps));
		m_fpsClock.restart();
	}
}



//-----------------------------------------------
//		Render
//

void Game::render()
{
	m_renderWindow->clear();

	// render all stuff here
	renderScenes();

	renderDebugInfo();

	m_renderWindow->display();
}

void Game::renderScenes()
{
	if (!m_scenes.get()->empty())
	{
		m_scenes.get()->top()->render();
	}
}

void Game::renderDebugInfo()
{
	// Frame time
	m_renderWindow->draw(m_debugFrameTime);

	// Fps
	m_renderWindow->draw(m_debugFps);
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

	initDebugVars();
}



//-----------------------------------------------
//		Destructors
//

Game::~Game()
= default;



//-----------------------------------------------
//		Else
//

void Game::run()
{
	while (m_renderWindow->isOpen())
	{
		update();
		render();

		calculateFrameTime();
		calculateFps();
	}
}
