#ifndef SCENE_MAIN_MENU_HPP
#define SCENE_MAIN_MENU_HPP

#include "Scene.hpp"
#include "Button.hpp"

class Scene_MainMenu : public Scene
{
private:
	/////////////////////
	// Variables
	//

	std::unique_ptr<Button> m_startGameBtn;


	/////////////////////
	// Methods
	//

	// Initialization

	void initButtons();

	// Udate

	void handleInput(const float &frameTime);
	void updateButtons();

	// Render

	void renderButtons(std::shared_ptr<sf::RenderTarget> &renderTarget);

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Scene_MainMenu(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys);

	// Destructors

	~Scene_MainMenu();

	// Update

	void update(const float &frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing scene

	void finalizeScene();
};

#endif
