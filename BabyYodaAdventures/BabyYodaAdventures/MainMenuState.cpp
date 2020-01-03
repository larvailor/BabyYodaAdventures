#include "MainMenuState.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void MainMenuState::handleInput(const float& frameTime)
{
	
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> renderWindow, std::map<std::string, sf::Keyboard::Key>* supportedKeys)
	: State(renderWindow, supportedKeys)
{
	initKeyBinds("MainMenuState_KeyBinds.ini");

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

void MainMenuState::update(const float& frameTime)
{

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
}



//-----------------------------------------------
//		Managing state
//

void MainMenuState::finalizeState()
{
	std::cout << "MainMenuState finalizeState called" << std::endl;
}
