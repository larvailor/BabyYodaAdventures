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
}



//-----------------------------------------------
//		Destructors
//

State::~State()
= default;
