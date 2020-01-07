#include "Scene.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//


void Scene::initKeyBinds(std::string pathToKeyBinsIni)
{
	std::ifstream ifs;
	ifs.open(pathToKeyBinsIni);
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
		std::string buttonKeyName, text;
		float x, y, width, height;
		int r, g, b, a;
		sf::Color colorIdle, colorHover, colorActive;
		int fontSize;

		while (!ifs.eof())
		{
			std::getline(ifs, buttonKeyName);

			// an empty line used as a delimiter between buttons
			if (buttonKeyName.empty()) { continue; }

			std::getline(ifs, text);

			ifs >> x >> y >> width >> height;
			
			ifs >> r >> g >> b >> a;
			colorIdle = sf::Color(r, g, b, a);

			ifs >> r >> g >> b >> a;
			colorHover = sf::Color(r, g, b, a);

			ifs >> r >> g >> b >> a;
			colorActive = sf::Color(r, g, b, a);

			ifs >> fontSize;

			auto button = std::make_shared<Button>(x, y, width, height, m_font, fontSize, text, colorIdle, colorHover, colorActive);
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

void Scene::updateButtons()
{
	for (auto button = m_buttons.begin(); button != m_buttons.end(); button++)
	{
		(*button).second->update(m_mousePosView);
	}
}



//-----------------------------------------------
//		Render
//

void Scene::renderButtons(shared<sf::RenderTarget>& renderTarget)
{
	for (auto button = m_buttons.begin(); button != m_buttons.end(); button++)
	{
		(*button).second->render(renderTarget);
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

Scene::Scene(
	shared<sf::RenderWindow>& renderWindow,
	shared_stack<shared<Scene>>& scenes,
	const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
)
	: m_renderWindow(renderWindow), m_scenes(scenes), m_supportedKeys(supportedKeys)
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
