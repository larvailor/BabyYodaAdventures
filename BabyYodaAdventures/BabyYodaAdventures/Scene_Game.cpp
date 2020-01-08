#include "Scene_Game.hpp"

#include "ConfigHelper.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Update
//

void Scene_Game::handleInput(const float& frameTime)
{
	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_UP")))
		m_player.move(frameTime, 0.f, -1.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_LEFT")))
		m_player.move(frameTime, -1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_DOWN")))
		m_player.move(frameTime, 0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_RIGHT")))
		m_player.move(frameTime, 1.f, 0.f);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("ESCAPE")))
		quitScene();
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Scene_Game::Scene_Game(
	shared<sf::RenderWindow>& renderWindow,
	shared_stack<shared<Scene>>& scenes,
	const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
)
	: Scene(renderWindow, scenes, supportedKeys)
{
	std::cout << "Scene_Game constructor called" << std::endl;

	initKeyBinds(SCENE_GAME_KEY_BINDS_PATH);
}


//-----------------------------------------------
//		Destructors
//

Scene_Game::~Scene_Game()
{
	std::cout << "Scene_Game destructor called" << std::endl;
}



//-----------------------------------------------
//		Update
//

void Scene_Game::update(const float& frameTime)
{
	updateMousePositions();
	handleInput(frameTime);

	m_player.update(frameTime);
}



//-----------------------------------------------
//		Render
//

void Scene_Game::render(shared<sf::RenderTarget> renderTarget)
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
//		Managing scene
//

void Scene_Game::finalizeScene()
{
	std::cout << "Scene_Game finalizeScene called" << std::endl;
}
