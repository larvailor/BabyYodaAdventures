#include "Scene_Game.hpp"

#include "ConfigHelper.hpp"
#include "Config_Scene_Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//


void Scene_Game::initTextures()
{
	auto babyYoda = std::make_shared<sf::Texture>();
	if (!babyYoda->loadFromFile(SCENE_GAME_BABY_YODA_TEXTURESHEET_PATH))
	{
		std::cout << "ERROR::Scene_Game::initTextures could not load textures " << SCENE_GAME_BABY_YODA_TEXTURESHEET_PATH << std::endl;
	}
	m_textures["BabyYoda"] = std::move(babyYoda);
}

void Scene_Game::initEntities()
{
	m_babyYoda = std::make_unique<BabyYoda>(
		m_renderWindow->getSize().x / 2.f,
		m_renderWindow->getSize().y / 2.f,
		m_textures.at("BabyYoda")
		);
}



//-----------------------------------------------
//		Update
//

void Scene_Game::handleInput(const float& frameTime)
{
	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_UP")))
		m_babyYoda->move(DirectionX::NONE, DirectionY::UP, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_LEFT")))
		m_babyYoda->move(DirectionX::LEFT, DirectionY::NONE, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_DOWN")))
		m_babyYoda->move(DirectionX::NONE, DirectionY::DOWN, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_RIGHT")))
		m_babyYoda->move(DirectionX::RIGHT, DirectionY::NONE, frameTime);

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
	initTextures();
	initEntities();
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

	m_babyYoda->update(frameTime);
}



//-----------------------------------------------
//		Render
//

void Scene_Game::render(shared<sf::RenderTarget> renderTarget)
{
	if (renderTarget == nullptr)
	{
		renderTarget = m_renderWindow;
	}
	m_babyYoda->render(renderTarget);
}
