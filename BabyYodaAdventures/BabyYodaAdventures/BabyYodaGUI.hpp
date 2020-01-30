#ifndef BABY_YODA_GUI_HPP
#define BABY_YODA_GUI_HPP

#include "BabyYoda.hpp"

class BabyYodaGUI
{
private:
	/////////////////////////////////////////////////
	// 
	//		VARIABLES
	//
	/////////////////////////////////////////////////

	shared<BabyYoda> m_babyYoda;
	shared<sf::RenderWindow> m_renderWindow;

	sf::Text m_killsCountText;

	//-----------------------------------------------
	//		Inner classes
	//

	class Heart
	{
	public:
		/////////////////////////////////////////////////
		// 
		//		VARIABLES
		//
		/////////////////////////////////////////////////

		shared<sf::Texture> m_heartTexture; 
		sf::Sprite m_heart;

		/////////////////////////////////////////////////
		// 
		//		Methods
		//
		/////////////////////////////////////////////////

		//-----------------------------------------------
		//		Constructors
		//

		Heart(float posX, float posY, shared<sf::Texture>& heartTexture) :
			m_heartTexture(heartTexture)
		{
			m_heart.setTexture(*m_heartTexture);
			m_heart.setPosition(sf::Vector2f(posX, posY));
		}
	};

	//-----------------------------------------------
	//		Attributes
	//

	/* A vector of hearts that is used for rendering hp status */
	std::vector<unique<Heart>> m_hearts;

	//-----------------------------------------------
	//		Sprites
	//

	sf::Sprite m_killedShtormtrooper;

	//-----------------------------------------------
	//		Resources
	//

		// Textures

	shared<sf::Texture> m_heartTexture;
	shared<sf::Texture> m_killedShtormtrooperTexture;

		// Fonts

	shared<sf::Font> m_font;

	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	void initHp();
	void initKillsCounter();

	//-----------------------------------------------
	//		Update
	//

	void updateHp(const float& frameTime);
	void updateKillsCounter();

	//-----------------------------------------------
	//		Render
	//

	void renderHp(shared<sf::RenderTarget>& renderTarget);
	void renderKillsCounter(shared<sf::RenderTarget>& renderTarget);

public:
	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	BabyYodaGUI(
		shared<sf::RenderWindow>& renderWindow,
		shared<BabyYoda>& babyYoda,
		shared<sf::Texture>& heartTexture,
		shared<sf::Texture>& killedShtormtrooperTexture,
		shared<sf::Font>& font
	);

	//-----------------------------------------------
	//		Destructors
	//

	~BabyYodaGUI();

	//-----------------------------------------------
	//		Update
	//

	void update(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void render(shared<sf::RenderTarget>& renderTarget);
};

#endif
