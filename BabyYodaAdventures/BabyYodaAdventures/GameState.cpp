#include "GameState.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

GameState::GameState(std::shared_ptr<sf::RenderWindow> renderWindow)
	: State(renderWindow)
{
	std::cout << "GameState constructor called" << std::endl;
}


//-----------------------------------------------
//		Destructors
//

GameState::~GameState()
{
	std::cout << "GameState destructor called" << std::endl;
}



//-----------------------------------------------
//		Update
//

void GameState::update(const float& frameTime)
{
	handleInput(frameTime);

	m_player.update(frameTime);
}

void GameState::handleInput(const float& frameTime)
{
	checkForClose();
}



//-----------------------------------------------
//		Render
//

void GameState::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{
	m_player.render(renderTarget);
}



//-----------------------------------------------
//		Managing state
//

void GameState::finalizeState()
{
	std::cout << "GameState finalizeState called" << std::endl;
}
