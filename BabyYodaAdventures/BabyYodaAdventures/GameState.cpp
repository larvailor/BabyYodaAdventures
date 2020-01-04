#include "GameState.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void GameState::handleInput(const float &frameTime)
{
	checkForClose();

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_UP")))
		m_player.move(frameTime, 0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_LEFT")))
		m_player.move(frameTime, -1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_DOWN")))
		m_player.move(frameTime, 0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_RIGHT")))
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

GameState::GameState(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys)
	: State(renderWindow, supportedKeys)
{
	std::cout << "GameState constructor called" << std::endl;

	initKeyBinds("Config/GameState_KeyBinds.ini");
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

void GameState::update(const float &frameTime)
{
	updateMousePositions();
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
		m_player.render(m_renderWindow);
	}
	else
	{
		m_player.render(renderTarget);
	}
}



//-----------------------------------------------
//		Managing state
//

void GameState::finalizeState()
{
	std::cout << "GameState finalizeState called" << std::endl;
}
