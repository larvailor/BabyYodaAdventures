#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "State.hpp"
#include "Button.hpp"

class MainMenuState : public State
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

	MainMenuState(std::shared_ptr<sf::RenderWindow> &renderWindow, std::map<std::string, sf::Keyboard::Key> *supportedKeys);

	// Destructors

	~MainMenuState();

	// Update

	void update(const float &frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing state

	void finalizeState();
};

#endif
