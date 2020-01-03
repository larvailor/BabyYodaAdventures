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

}


//-----------------------------------------------
//		Destructors
//

GameState::~GameState()
{

}



//-----------------------------------------------
//		Update
//

void GameState::update(const float& frameTime)
{

}



//-----------------------------------------------
//		Render
//

void GameState::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{

}



//-----------------------------------------------
//		Managing state
//

void GameState::endState()
{
}
