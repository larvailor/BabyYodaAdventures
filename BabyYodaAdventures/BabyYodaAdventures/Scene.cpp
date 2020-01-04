#include "Scene.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//


void Scene::initKeyBinds(std::string pathToKeyBinsIni, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys)
{
	std::ifstream ifs;
	ifs.open(pathToKeyBinsIni);
	if (ifs.is_open())
	{
		std::string key_name;
		std::string supported_key;
		while (ifs >> key_name >> supported_key)
		{
			m_keyBinds[key_name] = supportedKeys->at(supported_key);
		}
	}
	else
	{
		std::cout << "ERROR::Scene::initKeyBinds failed to load key binds " << pathToKeyBinsIni << std::endl;
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

void Scene::initButtons(std::string pathToButtonsIni)
{
	std::ifstream ifs;
	ifs.open(pathToButtonsIni);
	if (ifs.is_open())
	{
		std::string buttonKeyName;
		std::string text;
		float x, y, width, height;
		while (!ifs.eof())
		{
			std::getline(ifs, buttonKeyName);
			if (buttonKeyName.empty()) // an empty line used as a delimiter between buttons
			{
				continue;
			}

			std::getline(ifs, text);
			ifs >> x >> y >> width >> height;

			auto button = std::make_shared<Button>(x, y, width, height, m_font, text, sf::Color::White, sf::Color::Cyan, sf::Color::Magenta);
			m_buttons[buttonKeyName] = std::move(button);
		}
	}
	else
	{
		std::cout << "ERROR::Scene::initButtons failed to load buttons " << pathToButtonsIni << std::endl;
	}
	ifs.close();
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

Scene::Scene(std::shared_ptr<sf::RenderWindow> &renderWindow, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys)
	: m_renderWindow(renderWindow)
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
