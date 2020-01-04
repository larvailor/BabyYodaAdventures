#include "MainMenuState.hpp"

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

void MainMenuState::initButtons()
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

void MainMenuState::handleInput(const float &frameTime)
{
	checkForClose();
}

void MainMenuState::updateButtons()
{
	m_startGameBtn->update(m_mousePosView);
}



//-----------------------------------------------
//		Render
//

void MainMenuState::renderButtons(std::shared_ptr<sf::RenderTarget>& renderTarget)
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

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: State(renderWindow, supportedKeys)
{
	std::cout << "MainMenuState constructor called" << std::endl;

	initKeyBinds(MAIN_MENU_STATE_KEY_BINDS_PATH);
	initFont(MAIN_MENU_STATE_FONT_PATH);
	initButtons();
}


//-----------------------------------------------
//		Destructors
//

MainMenuState::~MainMenuState()
{
	std::cout << "MainMenuState destructor called" << std::endl;
}

//-----------------------------------------------
//		Update
//

void MainMenuState::update(const float &frameTime)
{
	updateMousePositions();
	handleInput(frameTime);
	updateButtons();
}



//-----------------------------------------------
//		Render
//

void MainMenuState::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{
	if (renderTarget == nullptr)
	{
		renderTarget = m_renderWindow;
	}
	renderButtons(renderTarget);
}



//-----------------------------------------------
//		Managing state
//

void MainMenuState::finalizeState()
{
	std::cout << "MainMenuState finalizeState called" << std::endl;
}
