#include "stdafx.hpp"
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
		auto heart = std::make_unique<Heart>(posX, posY, m_heartTexture);
		m_hearts.push_back(std::move(heart));
	}
}

void BabyYodaGUI::initKillsCounter()
{
	m_killedShtormtrooper.setTexture(*m_killedShtormtrooperTexture);
	m_killedShtormtrooper.setPosition(
		sf::Vector2f(
			static_cast<float>(m_renderWindow->getSize().x - m_killedShtormtrooper.getLocalBounds().width * 2),
			50.f
		)
	);

	m_killsCountText.setFont(*m_font);
	m_killsCountText.setCharacterSize(64);
	m_killsCountText.setFillColor(sf::Color::Black);
	m_killsCountText.setPosition(
		sf::Vector2f(
			m_killedShtormtrooper.getGlobalBounds().left - 120,
			60.f
		)
	);
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
		auto heart = std::make_unique<Heart>(posX, posY, m_heartTexture);
		m_hearts.push_back(std::move(heart));
	}
}

void BabyYodaGUI::updateKillsCounter()
{
	 m_killsCountText.setString(std::to_string(m_babyYoda->m_killsCounter));
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

void BabyYodaGUI::renderKillsCounter(shared<sf::RenderTarget>& renderTarget)
{
	renderTarget->draw(m_killedShtormtrooper);
	renderTarget->draw(m_killsCountText);
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

BabyYodaGUI::BabyYodaGUI(
	shared<sf::RenderWindow>& renderWindow,
	shared<BabyYoda>& babyYoda,
	shared<sf::Texture>& heartTexture,
	shared<sf::Texture>& killedShtormtrooperTexture,
	shared<sf::Font>& font
) :
	m_renderWindow(renderWindow),
	m_babyYoda(babyYoda),
	m_heartTexture(heartTexture),
	m_killedShtormtrooperTexture(killedShtormtrooperTexture),
	m_font(font)
{
	initHp();
	initKillsCounter();
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
	updateKillsCounter();
}



//-----------------------------------------------
//		Render
//

void BabyYodaGUI::render(shared<sf::RenderTarget>& renderTarget)
{
	renderHp(renderTarget);
	renderKillsCounter(renderTarget);
}
