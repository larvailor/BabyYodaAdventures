#include "MainMenuState.hpp"

#include "ConfigHelper.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void MainMenuState::handleInput(const float &frameTime)
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

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: State(renderWindow, supportedKeys)
{
	initKeyBinds(MAIN_MENU_STATE_KEY_BINDS_PATH);
	initFont(MAIN_MENU_STATE_FONT_PATH);

	std::cout << "MainMenuState constructor called" << std::endl;
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
}



//-----------------------------------------------
//		Render
//

void MainMenuState::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{
	// TBD
}



//-----------------------------------------------
//		Managing state
//

void MainMenuState::finalizeState()
{
	std::cout << "MainMenuState finalizeState called" << std::endl;
}
