#include "stdafx.hpp"
#include "Scene_MainMenu.hpp"

#include "Config_Scene_MainMenu.hpp"

#include "Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Scene_MainMenu::initSmoke(std::string pathToBackground)
{
	m_background.setSize(
		sf::Vector2f(
			static_cast<float>(m_renderWindow->getSize().x),
			static_cast<float>(m_renderWindow->getSize().y)
		)
	);

	if (!m_backgroundTexture.loadFromFile(pathToBackground))
	{
		std::cout << "ERROR::Scene_MainMenu::initBackground could not load background " << pathToBackground << std::endl;
		m_background.setFillColor(sf::Color::Black);
	}
	else
	{
		m_background.setTexture(&m_backgroundTexture);
	}

}



//-----------------------------------------------
//		Update
//

void Scene_MainMenu::handleInput(const float& frameTime)
{
	if (m_buttons["START_GAME"]->isPressed())
	{
		auto gameScene = std::make_shared<Scene_Game>(m_renderWindow, m_scenes, m_supportedKeys);
		m_scenes->push(std::move(gameScene));
	}

	if (m_buttons["END_GAME"]->isPressed())
	{
		quitScene();
	}
}



//-----------------------------------------------
//		Update
//

void Scene_MainMenu::renderBackground()
{
	m_renderWindow->draw(m_background);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Scene_MainMenu::Scene_MainMenu(
	shared<sf::RenderWindow>& renderWindow,
	shared_stack<shared<Scene>>& scenes,
	const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
)
	: Scene(renderWindow, scenes, supportedKeys)
{
	initSmoke(SCENE_MAIN_MENU_BACKGROUND_PATH);
	initKeyBinds(SCENE_MAIN_MENU_KEY_BINDS_PATH);
	initFont(SCENE_MAIN_MENU_FONT_PATH);
	initButtons(SCENE_MAIN_MENU_BUTTONS_PATH);
}



//-----------------------------------------------
//		Destructors
//

Scene_MainMenu::~Scene_MainMenu()
= default;



//-----------------------------------------------
//		Update
//

void Scene_MainMenu::update(const float& frameTime)
{
	updateMousePositions();
	updateButtons();
	handleInput(frameTime);
}



//-----------------------------------------------
//		Render
//

void Scene_MainMenu::render(shared<sf::RenderTarget> renderTarget)
{
	if (renderTarget == nullptr)
	{
		renderTarget = m_renderWindow;
	}
	renderBackground();
	renderButtons(renderTarget);
}
