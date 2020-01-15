#ifndef BUTTON_HPP
#define BUTTON_HPP

enum ButtonStates { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
protected:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	unsigned char m_buttonState;

	sf::RectangleShape m_button;
	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

	sf::Text m_text;

	//-----------------------------------------------
	//		Resources
	//

		// Fonts

	shared<sf::Font> m_font;

public:
	/////////////////////////////////////////////////
	// 
	//		METHODS
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	Button(float x, float y, float width, float height,
		shared<sf::Font>& font, int fontSize, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor
	);

	//-----------------------------------------------
	//		Destructors
	//

	virtual ~Button();

	//-----------------------------------------------
	//		Accessors
	//
		
		// Getters

	bool isPressed() const;

	//-----------------------------------------------
	//		Update
	//

	void update(const sf::Vector2f& mousePosition);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget>& renderTarget);
};

#endif
