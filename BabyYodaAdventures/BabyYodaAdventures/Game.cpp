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
	sf::VideoMode video_mode(1000, 800);
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;

	// Reading config from file

	std::ifstream ifs;
	ifs.open(WINDOW_CONFIG_PATH);
	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> video_mode.width >> video_mode.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}
	ifs.close();

	// Setting up window

	m_renderWindow = std::make_shared<sf::RenderWindow>(video_mode, title, sf::Style::Titlebar | sf::Style::Close);
	m_renderWindow->setFramerateLimit(framerate_limit);
	m_renderWindow->setVerticalSyncEnabled(vertical_sync_enabled);
}

/**
	Loads all supported keys from SupportedKeys.ini file 
	and creates an std::map of supported keys and their codes
*/
void Game::initSupportedKeys()
{
	std::ifstream ifs;
	ifs.open(SUPPORTED_KEYS_CONFIG_PATH);
	if (ifs.is_open())
	{
		std::string key_name;
		int key_code;
		while (ifs >> key_name >> key_code)
		{
			m_supportedKeys[key_name] = static_cast<sf::Keyboard::Key>(key_code);
		}

	}
	ifs.close();
}

/**
	Pushes the first game state into the stack of states.
	Should be called only when all supported keys were loaded!
*/
void Game::initStates()
{
	auto state = std::make_shared<GameState>(m_renderWindow, &m_supportedKeys);
	m_states.push(std::move(state));
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
	updateStates();
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
	Tooks the top item on the stack of states and calls its update method.
	If the state should be closed, then calls its finalize method and pops from stack.
	If there are no states, then calls to close method on render window
*/
void Game::updateStates()
{
	if (!m_states.empty())
	{
		m_states.top()->update(m_frameTime);

		if (m_states.top()->needToBeClosed())
		{
			m_states.top()->finalizeState();
			m_states.pop();
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
	renderStates();

	m_renderWindow->display();
}

/**
	Tooks the top item on the stack of states and calls its render method
*/
void Game::renderStates()
{
	if (!m_states.empty())
	{
		m_states.top()->render(m_renderWindow);
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
	initStates();
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
