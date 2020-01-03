#include "GameState.hpp"

/////////////////////////////////////////////////
// 
//		PROTECTED METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void GameState::initKeyBinds()
{
	m_keyBinds.emplace("MOVE_UP", m_supportedKeys->at("W"));
	m_keyBinds.emplace("MOVE_LEFT", m_supportedKeys->at("A"));
	m_keyBinds.emplace("MOVE_DOWN", m_supportedKeys->at("S"));
	m_keyBinds.emplace("MOVE_RIGHT", m_supportedKeys->at("D"));
}



//-----------------------------------------------
//		Update
//

void GameState::handleInput(const float& frameTime)
{
	checkForClose();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_keyBinds.at("MOVE_UP"))))
		m_player.move(frameTime, 0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_keyBinds.at("MOVE_LEFT"))))
		m_player.move(frameTime, -1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_keyBinds.at("MOVE_DOWN"))))
		m_player.move(frameTime, 0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(m_keyBinds.at("MOVE_RIGHT"))))
		m_player.move(frameTime, 1.f, 0.f);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

GameState::GameState(std::shared_ptr<sf::RenderWindow> renderWindow, std::map<std::string, int>* supportedKeys)
	: State(renderWindow, supportedKeys)
{
	initKeyBinds();

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



//-----------------------------------------------
//		Render
//

void GameState::render(std::shared_ptr<sf::RenderTarget> renderTarget)
{
	if (renderTarget == nullptr)
	{
		renderTarget = m_renderWindow;
	}

	m_player.render(renderTarget);
}



//-----------------------------------------------
//		Managing state
//

void GameState::finalizeState()
{
	std::cout << "GameState finalizeState called" << std::endl;
}
