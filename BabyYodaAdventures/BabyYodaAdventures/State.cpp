#include "State.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////


// Initialization

/**
	Loads all key binds for specific state
	and creates an std::map of supported keys and their codes
*/
void State::initKeyBinds(std::string pathToConfig)
{
	std::ifstream ifs;
	ifs.open(pathToConfig);
	if (ifs.is_open())
	{
		std::string key_name;
		std::string supported_key;
		while (ifs >> key_name >> supported_key)
		{
			m_keyBinds[key_name] = m_supportedKeys->at(supported_key);
		}

	}
	ifs.close();
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

State::State(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: m_renderWindow(renderWindow), m_supportedKeys(supportedKeys)
{
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
	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("Escape")))
	{
		m_close = true;
	}
}
