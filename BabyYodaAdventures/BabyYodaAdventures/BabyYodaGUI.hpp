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

		sf::RectangleShape m_heart; // TODO: use heart texture instead

		/////////////////////////////////////////////////
		// 
		//		Methods
		//
		/////////////////////////////////////////////////

		//-----------------------------------------------
		//		Constructors
		//

		Heart(float posX, float posY)
		{
			m_heart.setPosition(sf::Vector2f(posX, posY));
			m_heart.setSize(sf::Vector2f(60, 60));
			m_heart.setFillColor(sf::Color::Red);
		}
	};

	//-----------------------------------------------
	//		Attributes
	//

	/* A vector of hearts that is used for rendering hp status */
	std::vector<unique<Heart>> m_hearts;

	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Initialization
	//

	void initHp();

	//-----------------------------------------------
	//		Update
	//

	void updateHp(const float& frameTime);

	//-----------------------------------------------
	//		Render
	//

	void renderHp(shared<sf::RenderTarget>& renderTarget);

public:
	/////////////////////////////////////////////////
	// 
	//		Methods
	//
	/////////////////////////////////////////////////

	//-----------------------------------------------
	//		Constructors
	//

	BabyYodaGUI(shared<BabyYoda>& babyYoda);

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
