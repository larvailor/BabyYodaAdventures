#include "Scene_MainMenu.hpp"

#include "ConfigHelper.hpp"
#include "Button.hpp"

#include "Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void Scene_MainMenu::handleInput(const float& frameTime)
{
	checkForClose();

	if (m_buttons["START_GAME"]->isPressed())
	{
		auto gameScene = std::make_shared<Scene_Game>(m_renderWindow, m_scenes, m_supportedKeys);
		m_scenes->push(std::move(gameScene));
	}

	if (m_buttons["END_GAME"]->isPressed())
	{
		m_close = true;
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

Scene_MainMenu::Scene_MainMenu(
	shared<sf::RenderWindow>& renderWindow,
	shared_stack<shared<Scene>>& scenes,
	const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
)
	: Scene(renderWindow, scenes, supportedKeys)
{
	std::cout << "Scene_MainMenu constructor called" << std::endl;

	initKeyBinds(SCENE_MAIN_MENU_KEY_BINDS_PATH);
	initFont(SCENE_MAIN_MENU_FONT_PATH);
	initButtons(SCENE_MAIN_MENU_BUTTONS_PATH);
}


//-----------------------------------------------
//		Destructors
//

Scene_MainMenu::~Scene_MainMenu()
{
	std::cout << "Scene_MainMenu destructor called" << std::endl;
}

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
	renderButtons(renderTarget);
}



//-----------------------------------------------
//		Managing scene
//

void Scene_MainMenu::finalizeScene()
{
	std::cout << "Scene_MainMenu finalizeScene called" << std::endl;
}
