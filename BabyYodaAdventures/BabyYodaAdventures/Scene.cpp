#include "Scene.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

/**
	Loads all key binds for specific scene
	and creates an std::map of supported keys and their codes
*/
void Scene::initKeyBinds(std::string pathToConfig)
{
	std::ifstream ifs;
	ifs.open(pathToConfig);
	if (ifs.is_open())
	{
		std::string key_name;
		std::string supported_key;
		while (ifs >> key_name >> supported_key)
		{
			m_keyBinds[key_name] = m_supportedKeys->at(supported_key);
		}

	}
	else
	{
		std::cout << "ERROR::Scene::initKeyBinds failed to load key binds " << pathToConfig << std::endl;
	}
	ifs.close();
}

void Scene::initFont(std::string pathToFont)
{
	m_font = std::make_shared<sf::Font>();
	if (!m_font->loadFromFile(pathToFont))
	{
		std::cout << "ERROR::Scene::initFont failed to load font " << pathToFont << std::endl;
	}
}



//-----------------------------------------------
//		Update
//

void Scene::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition(*m_renderWindow);
	m_mousePosView = m_renderWindow->mapPixelToCoords(sf::Mouse::getPosition(*m_renderWindow));
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Scene::Scene(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: m_renderWindow(renderWindow), m_supportedKeys(supportedKeys)
{
	std::cout << "Scene constructor called" << std::endl;

	m_close = false;
}



//-----------------------------------------------
//		Destructors
//

Scene::~Scene()
{
	std::cout << "Scene destructor called" << std::endl;
}



//-----------------------------------------------
//		Accessors
//

//		Getters

bool Scene::needToBeClosed() const
{
	return m_close;
}



//-----------------------------------------------
//		Managing scene
//

void Scene::checkForClose()
{
	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("Escape")))
	{
		m_close = true;
	}
}
