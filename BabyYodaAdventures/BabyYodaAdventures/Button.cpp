#include "Button.hpp"

/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Button::Button(
	float x,
	float y,
	float width,
	float height,
	std::shared_ptr<sf::Font> &font,
	std::string text,
	sf::Color idleColor,
	sf::Color hoverColor,
	sf::Color activeColor
) : m_font(font), m_idleColor(idleColor), m_hoverColor(hoverColor), m_activeColor(activeColor)
{
	std::cout << "Button constructor called" << std::endl;

	// Button
	m_button.setPosition(sf::Vector2f(x, y));
	m_button.setSize(sf::Vector2f(width, height));

	// Button state
	m_buttonState = BTN_IDLE;

	// Text on button
	m_text.setFont(*m_font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(64);
	m_text.setPosition(
		m_button.getPosition().x + (m_button.getGlobalBounds().width / 2.f) - (m_text.getGlobalBounds().width / 2.f),
		m_button.getPosition().y + (m_button.getGlobalBounds().height / 2.f) - m_text.getGlobalBounds().height / 2.f
	);

}



//-----------------------------------------------
//		Destructors
//


Button::~Button()
{
	std::cout << "Button destructor called" << std::endl;
}



//-----------------------------------------------
//		Accessors
//

//		getters

bool Button::isPressed() const
{
	return m_buttonState == BTN_ACTIVE ? true : false;
}



//-----------------------------------------------
//		Update
//

void Button::update(const sf::Vector2f &mousePosition)
{
	// Idle
	m_buttonState = BTN_IDLE;

	// Hover
	if (m_text.getGlobalBounds().contains(mousePosition))
	{
		m_buttonState = BTN_HOVER;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_buttonState = BTN_ACTIVE;
		}
	}

	switch (m_buttonState)
	{
	case BTN_IDLE:
		m_text.setFillColor(m_idleColor);
		m_text.setScale(sf::Vector2f(1.f, 1.f));
		break;
	case BTN_HOVER:
		m_text.setFillColor(m_hoverColor);
		m_text.setScale(sf::Vector2f(1.2f, 1.2f));
		break;
	case BTN_ACTIVE:
		m_text.setFillColor(m_activeColor);
		break;
	}
}



//-----------------------------------------------
//		Render
//

void Button::render(std::shared_ptr<sf::RenderTarget> &renderTarget)
{
	//renderTarget->draw(m_button);
	renderTarget->draw(m_text);
}
