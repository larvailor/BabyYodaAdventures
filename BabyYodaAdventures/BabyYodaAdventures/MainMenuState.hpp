#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "State.hpp"

class MainMenuState : public State
{
private:
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

	MainMenuState(std::shared_ptr<sf::RenderWindow> renderWindow, std::map<std::string, sf::Keyboard::Key>* supportedKeys);

	// Destructors

	~MainMenuState();

	// Update

	void update(const float& frameTime);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> renderTarget = nullptr);

	// Managing state

	void finalizeState();
};

#endif
