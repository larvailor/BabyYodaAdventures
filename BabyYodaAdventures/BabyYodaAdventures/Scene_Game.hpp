#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "Scene.hpp"

class Scene_Game : public Scene
{
private:
	/////////////////////
	// Variables
	//

	Entity m_player;



	/////////////////////
	// Methods
	//

	// Udate

	void handleInput(const float &frameTime);

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Scene_Game(std::shared_ptr<sf::RenderWindow> &renderWindow, const std::map<std::string, sf::Keyboard::Key> *const supportedKeys);

	// Destructors

	virtual ~Scene_Game();

	// Update

	void update(const float &frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing scene

	void finalizeScene();
};

#endif
