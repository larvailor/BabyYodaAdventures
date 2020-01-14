#include "BabyYodaGUI.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void BabyYodaGUI::initHp()
{
	while (m_hearts.size() < m_babyYoda->m_hp)
	{
		float posX = m_hearts.empty() ? 60 : m_hearts.back()->m_heart.getGlobalBounds().left + m_hearts.back()->m_heart.getGlobalBounds().width + 10;
		float posY = m_hearts.empty() ? 60 : m_hearts.back()->m_heart.getGlobalBounds().top;
		auto heart = std::make_unique<Heart>(posX, posY);
		m_hearts.push_back(std::move(heart));
	}
}



//-----------------------------------------------
//		Update
//

void BabyYodaGUI::updateHp(const float& frameTime)
{
	while (m_hearts.size() > m_babyYoda->m_hp)
	{
		m_hearts.pop_back();
	}

	while (m_hearts.size() < m_babyYoda->m_hp)
	{
		float posX = m_hearts.back()->m_heart.getGlobalBounds().left + m_hearts.back()->m_heart.getGlobalBounds().width + 10;
		float posY = m_hearts.back()->m_heart.getGlobalBounds().top;
		auto heart = std::make_unique<Heart>(posX, posY);
		m_hearts.push_back(std::move(heart));
	}
}



//-----------------------------------------------
//		Render
//

void BabyYodaGUI::renderHp(shared<sf::RenderTarget>& renderTarget)
{
	for (auto& heart : m_hearts)
	{
		renderTarget->draw(heart->m_heart);
	}
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

BabyYodaGUI::BabyYodaGUI(shared<BabyYoda>& babyYoda) :
	m_babyYoda(babyYoda)
{
	initHp();
}



//-----------------------------------------------
//		Destructors
//

BabyYodaGUI::~BabyYodaGUI()
= default;



//-----------------------------------------------
//		Update
//

void BabyYodaGUI::update(const float& frameTime)
{
	updateHp(frameTime);
}



//-----------------------------------------------
//		Render
//

void BabyYodaGUI::render(shared<sf::RenderTarget>& renderTarget)
{
	renderHp(renderTarget);
}
