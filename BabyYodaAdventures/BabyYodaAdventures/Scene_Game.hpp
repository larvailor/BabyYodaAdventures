#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "Scene.hpp"
#include "BabyYodaGUI.hpp"
#include "MagmaBall.hpp"
#include "Shtormtrooper.hpp"

class Scene_Game : public Scene
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	shared<BabyYoda> m_babyYoda;
	unique<BabyYodaGUI> m_babyYodaGUI;

	std::vector<unique<MagmaBall>> m_magmaBalls;
	sf::Clock m_magmaBallTimer;

	std::vector<unique<Shtormtrooper>> m_shtormtroopers;
	sf::Clock m_shtormtrooperClock;

	sf::RectangleShape m_background;
	sf::RectangleShape m_smokeTop;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	void initTextures();
	void initBackground();
	void initEntities();
	void initSmoke();
	void initGUI();

	//-----------------------------------------------
	//		Update
	//

	void handleKeyInput(const float& frameTime);
	
	void updateEntities(const float& frameTime);
	void updateBabyYoda(const float& frameTime);
	void updateMagmaBalls(const float& frameTime);
	void updateShtormtroopers(const float& frameTime);

	void updateGUI(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void renderBackground(shared<sf::RenderTarget>& renderTarget);

	void renderEntities(shared<sf::RenderTarget>& renderTarget);
	void renderBabyYoda(shared<sf::RenderTarget>& renderTarget);
	void renderMagmaBalls(shared<sf::RenderTarget>& renderTarget);
	void renderShtormtroopers(shared<sf::RenderTarget>& renderTarget);

	void renderSmoke(shared<sf::RenderTarget>& renderTarget);
	void renderGUI(shared<sf::RenderTarget>& renderTarget);

	//-----------------------------------------------
	//		Else
	//

	void createMagmaBall();
	void spawnShtormtrooper();

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Scene_Game(
		shared<sf::RenderWindow>& renderWindow,
		shared_stack<shared<Scene>>& scenes,
		const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
	);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Scene_Game();

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget> renderTarget = nullptr);
};

#endif
