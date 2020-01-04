#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <memory>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

enum ButtonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
protected:
	/////////////////////
	// Variables
	//

	unsigned char m_buttonState;

	sf::RectangleShape m_button;
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

	sf::Text m_text;

	// Resources
		// fonts

	std::shared_ptr<sf::Font> m_font;

public:
	/////////////////////
	// Methods
	//

	// Constructors

	Button(float x, float y, float width, float height,
		std::shared_ptr<sf::Font> &font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

	// Destructors

	virtual ~Button();

	// Accessors
		// getters

	bool isPressed() const;

	// Update

	void update(const sf::Vector2f &mousePosition);

	// Render

	void render(std::shared_ptr<sf::RenderTarget> &renderTarget);
};

#endif
