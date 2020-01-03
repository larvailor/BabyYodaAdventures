#include "Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

/**
	Loads configuration from window.ini file.
	Sets up default if failed to load
*/
void Game::initWindow()
{
	// Setting default values

	std::string title = "Baby Yoda Adventures";
	sf::VideoMode video_mode(1000, 800);
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;

	// Reading config from file

	std::ifstream ifs;
	ifs.open("Config/window.ini");
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> video_mode.width >> video_mode.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}
	ifs.close();

	// Setting up window

	m_renderWindow = std::make_unique<sf::RenderWindow>(video_mode, title, sf::Style::Titlebar | sf::Style::Close);
	m_renderWindow->setFramerateLimit(framerate_limit);
	m_renderWindow->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initEvent()
{
	m_event = std::make_unique<sf::Event>();
}



//-----------------------------------------------
//		Update
//

void Game::update()
{
	pollEvents();
}

void Game::pollEvents()
{
	while (m_renderWindow->pollEvent(*m_event))
	{
		switch (m_event->type)
		{
		case sf::Event::Closed:
			this->m_renderWindow->close();
			break;
		}
	}
}

/**
	Calculates how much time is needed to update and render one frame
	and stores the result in private m_frameTime member
*/
void Game::calculateFrameTime()
{
	m_frameTime = m_frameTimeClock.restart().asSeconds();

	system("cls");
	std::cout << "Frame time: " << m_frameTime << std::endl;
}



//-----------------------------------------------
//		Render
//

void Game::render()
{
	m_renderWindow->clear();

	// draw all stuff hers

	m_renderWindow->display();
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
	initEvent();
}



//-----------------------------------------------
//		Destructors
//

Game::~Game()
= default;



//-----------------------------------------------
//		Else methods
//

void Game::run()
{
	while (m_renderWindow->isOpen())
	{
		update();
		render();

		calculateFrameTime();
	}
}



