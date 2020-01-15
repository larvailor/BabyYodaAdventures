#ifndef SCENE_MAIN_MENU_HPP
#define SCENE_MAIN_MENU_HPP

#include "Scene.hpp"

class Scene_MainMenu : public Scene
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	sf::RectangleShape m_background;
	sf::Texture m_backgroundTexture;

	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	void initSmoke(std::string pathToBackground);

	//-----------------------------------------------
	//		Update
	//

	void handleInput(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void renderBackground();

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Scene_MainMenu(
		shared<sf::RenderWindow>& renderWindow,
		shared_stack<shared<Scene>>& scenes,
		const shared_map<std::string, sf::Keyboard::Key>& supportedKeys
	);

	//-----------------------------------------------
	//		Destructors
	//

	~Scene_MainMenu();

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
