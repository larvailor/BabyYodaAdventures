#include "Scene_MainMenu.hpp"

#include "ConfigHelper.hpp"
#include "Button.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void Scene_MainMenu::handleInput(const float &frameTime)
{
	checkForClose();
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Scene_MainMenu::Scene_MainMenu(std::shared_ptr<sf::RenderWindow> &renderWindow, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys)
	: Scene(renderWindow, supportedKeys)
{
	std::cout << "Scene_MainMenu constructor called" << std::endl;

	initKeyBinds(SCENE_MAIN_MENU_KEY_BINDS_PATH, supportedKeys);
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

void Scene_MainMenu::update(const float &frameTime)
{
	updateMousePositions();
	updateButtons();
	handleInput(frameTime);
}



//-----------------------------------------------
//		Render
//

void Scene_MainMenu::render(std::shared_ptr<sf::RenderTarget> renderTarget)
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
