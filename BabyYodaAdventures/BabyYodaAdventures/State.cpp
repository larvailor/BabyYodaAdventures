#include "State.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

State::State(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	m_renderWindow = renderWindow;
	m_close = false;

	std::cout << "State constructor called" << std::endl;
}



//-----------------------------------------------
//		Destructors
//

State::~State()
{
	std::cout << "State destructor called" << std::endl;
}



//-----------------------------------------------
//		Accessors
//

//		Getters

bool State::needToBeClosed() const
{
	return m_close;
}



//-----------------------------------------------
//		Managing state
//

void State::checkForClose()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_close = true;
	}
}
