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

	void handleInput(const float& frameTime);

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Scene_Game(
		shared<sf::RenderWindow>& renderWindow,
		shared_stack<shared<Scene>>& scenes,
		const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
	);

	// Destructors

	virtual ~Scene_Game();

	// Update

	void update(const float& frameTime);

	// Render

	void render(shared<sf::RenderTarget> renderTarget = nullptr);

	// Managing scene

	void finalizeScene();
};

#endif
