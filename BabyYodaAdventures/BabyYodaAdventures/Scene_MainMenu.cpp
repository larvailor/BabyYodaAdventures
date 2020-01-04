#include "Scene_MainMenu.hpp"

#include "ConfigHelper.hpp"
#include "Button.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Scene_MainMenu::initButtons()
{
	m_startGameBtn = std::make_unique<Button>(
		100.f, 100.f, 200.f, 50.f,
		m_font, "Start Game",
		sf::Color::White, sf::Color::Cyan, sf::Color::Magenta
		);
}



//-----------------------------------------------
//		Update
//

void Scene_MainMenu::handleInput(const float &frameTime)
{
	checkForClose();
}

void Scene_MainMenu::updateButtons()
{
	m_startGameBtn->update(m_mousePosView);
}



//-----------------------------------------------
//		Render
//

void Scene_MainMenu::renderButtons(std::shared_ptr<sf::RenderTarget>& renderTarget)
{
	m_startGameBtn->render(renderTarget);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Scene_MainMenu::Scene_MainMenu(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: Scene(renderWindow, supportedKeys)
{
	std::cout << "Scene_MainMenu constructor called" << std::endl;

	initKeyBinds(SCENE_MAIN_MENU_KEY_BINDS_PATH);
	initFont(SCENE_MAIN_MENU_FONT_PATH);
	initButtons();
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
	handleInput(frameTime);
	updateButtons();
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
