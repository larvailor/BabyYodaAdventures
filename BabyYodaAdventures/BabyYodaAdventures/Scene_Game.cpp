#include "stdafx.hpp"
#include "Scene_Game.hpp"

#include "ConfigHelper.hpp"
#include "Config_Scene_Game.hpp"

#include "TexturesLoader.hpp"

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
	TexturesLoader::loadTexture(SCENE_GAME_BABY_YODA_TEXTURESHEET_PATH, "BabyYoda", m_textures);
	TexturesLoader::loadTexture(SCENE_GAME_MAGMABALL_TEXTURESHEET_PATH, "MagmaBall", m_textures);
	TexturesLoader::loadTexture(SCENE_GAME_STORMTROOPER_TEXTURESHEET_PATH, "Shtormtrooper", m_textures);
	TexturesLoader::loadTexture(SCENE_GAME_GUI_HEART_PATH, "Heart", m_textures);
	TexturesLoader::loadTexture(SCENE_GAME_SMOKE_PATH, "Smoke", m_textures);
}

void Scene_Game::initBackground()
{
	m_background.setSize(
		sf::Vector2f(
			static_cast<float>(m_renderWindow->getSize().x),
			static_cast<float>(m_renderWindow->getSize().y)
		)
	);

	m_background.setFillColor(sf::Color::White);
}

void Scene_Game::initEntities()
{
	m_babyYoda = std::make_shared<BabyYoda>(
		m_renderWindow->getSize().x / 2.f,
		m_renderWindow->getSize().y / 2.f,
		m_textures.at("BabyYoda")
		);
}

void Scene_Game::initSmoke()
{
	m_smokeTop.setSize(
		sf::Vector2f(
			static_cast<float>(m_renderWindow->getSize().x),
			static_cast<float>(m_renderWindow->getSize().y)
		)
	);

	m_smokeTop.setTexture(m_textures["Smoke"].get());
}

void Scene_Game::initGUI()
{
	m_babyYodaGUI = std::make_unique<BabyYodaGUI>(m_babyYoda, m_textures.at("Heart"));
}



//-----------------------------------------------
//		Update
//

void Scene_Game::handleKeyInput(const float& frameTime)
{
	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_UP")))
		m_babyYoda->move(DirectionX::NONE, DirectionY::UP, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_LEFT")))
		m_babyYoda->move(DirectionX::LEFT, DirectionY::NONE, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_DOWN")))
		m_babyYoda->move(DirectionX::NONE, DirectionY::DOWN, frameTime);

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("MOVE_RIGHT")))
		m_babyYoda->move(DirectionX::RIGHT, DirectionY::NONE, frameTime);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		createMagmaBall();

	if (sf::Keyboard::isKeyPressed(m_keyBinds.at("ESCAPE")))
		quitScene();
}

void Scene_Game::updateEntities(const float& frameTime)
{
	updateBabyYoda(frameTime);
	updateMagmaBalls(frameTime);
	updateShtormtroopers(frameTime);
}

void Scene_Game::updateBabyYoda(const float& frameTime)
{
	m_babyYoda->update(frameTime);
}

void Scene_Game::updateMagmaBalls(const float& frameTime)
{
	auto magmaBallItr = m_magmaBalls.begin();
	while (magmaBallItr != m_magmaBalls.end())
	{
		magmaBallItr->get()->update(frameTime);
		if (!magmaBallItr->get()->intersects(sf::FloatRect(m_background.getPosition(), m_background.getSize())))
			magmaBallItr = m_magmaBalls.erase(magmaBallItr);
		else
			magmaBallItr++;
	}
}

void Scene_Game::updateShtormtroopers(const float& frameTime)
{
	auto shtormtrooperItr = m_shtormtroopers.begin();
	while (shtormtrooperItr != m_shtormtroopers.end())
	{
		if (shtormtrooperItr->get()->m_hp <= 0)
		{
			shtormtrooperItr = m_shtormtroopers.erase(shtormtrooperItr);
		}
		else
		{
			shtormtrooperItr->get()->update(frameTime);
			shtormtrooperItr++;
		}
	}

	spawnShtormtrooper();
}

void Scene_Game::updateGUI(const float& frameTime)
{
	m_babyYodaGUI->update(frameTime);
}



//-----------------------------------------------
//		Render
//

void Scene_Game::renderBackground(shared<sf::RenderTarget>& renderTarget)
{
	m_renderWindow->draw(m_background);
}

void Scene_Game::renderEntities(shared<sf::RenderTarget>& renderTarget)
{
	renderBabyYoda(renderTarget);
	renderMagmaBalls(renderTarget);
	renderShtormtroopers(renderTarget);
}

void Scene_Game::renderBabyYoda(shared<sf::RenderTarget>& renderTarget)
{
	m_babyYoda->render(renderTarget);
}

void Scene_Game::renderMagmaBalls(shared<sf::RenderTarget>& renderTarget)
{
	for (auto& magmaBall : m_magmaBalls)
	{
		magmaBall->render(renderTarget);
	}
}

void Scene_Game::renderShtormtroopers(shared<sf::RenderTarget>& renderTarget)
{
	for (auto& shtormtrooper : m_shtormtroopers)
	{
		shtormtrooper->render(renderTarget);
	}
}

void Scene_Game::renderSmoke(shared<sf::RenderTarget>& renderTarget)
{
	m_renderWindow->draw(m_smokeTop);
}

void Scene_Game::renderGUI(shared<sf::RenderTarget>& renderTarget)
{
	m_babyYodaGUI->render(renderTarget);
}



//-----------------------------------------------
//		Else
//

void Scene_Game::createMagmaBall()
{
	if (m_magmaBallTimer.getElapsedTime().asSeconds() > 0.2)
	{
		auto magmaBall = std::make_unique<MagmaBall>(m_babyYoda->getPos(), m_mousePosView, m_textures.at("MagmaBall"));
		m_magmaBalls.push_back(std::move(magmaBall));

		m_magmaBallTimer.restart().asSeconds();
	}
}

void Scene_Game::spawnShtormtrooper()
{
	//auto x = std::dynamic_pointer_cast<Entity>(m_babyYoda);

	//auto s = new Shtormtrooper(
	//	sf::Vector2f(300.f, 300.f),
	//	m_textures.at("Shtormtrooper"),
	//	x
	//	);
	if (m_shtormtrooperClock.getElapsedTime().asSeconds() > 2)
	{
		auto castedPtr = std::dynamic_pointer_cast<Entity>(m_babyYoda);
		auto shtormtrooper = std::make_unique<Shtormtrooper>(
			sf::Vector2f(300.f, 300.f),
			m_textures.at("Shtormtrooper"),
			castedPtr
			);
		m_shtormtroopers.push_back(std::move(shtormtrooper));

		m_shtormtrooperClock.restart().asSeconds();
	}
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
	initKeyBinds(SCENE_GAME_KEY_BINDS_PATH);
	initTextures();
	initBackground();
	initEntities();
	initSmoke();
	initGUI();
}


//-----------------------------------------------
//		Destructors
//

Scene_Game::~Scene_Game()
= default;



//-----------------------------------------------
//		Update
//

void Scene_Game::update(const float& frameTime)
{
	updateMousePositions();
	handleKeyInput(frameTime);
	updateEntities(frameTime);
	updateGUI(frameTime);
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

	renderBackground(renderTarget);
	renderEntities(renderTarget);
	renderSmoke(renderTarget);
	renderGUI(renderTarget);
}
