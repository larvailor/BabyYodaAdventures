#include <iostream>

#include "Game.hpp"

/////////////////////////////////////////////////
// 
//		PRIVATE METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Initialization
//

void Game::initWindow()
{
	m_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 800), "Baby Yoda Adventures", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initEvent()
{
	m_event = std::make_unique<sf::Event>();
}



//-----------------------------------------------
//		Update
//

void Game::update()
{
	pollEvents();
}

void Game::pollEvents()
{
	while (m_renderWindow->pollEvent(*m_event))
	{
		switch (m_event->type)
		{
		case sf::Event::Closed:
			this->m_renderWindow->close();
			break;
		}
	}
}

/**
	Calculates how much time is needed to update and render one frame
	and stores the result in private m_frameTime member
*/
void Game::calculateFrameTime()
{
	m_frameTime = m_frameTimeClock.restart().asSeconds();

	system("cls");
	std::cout << "Frame time: " << m_frameTime << std::endl;
}



//-----------------------------------------------
//		Render
//

void Game::render()
{
	m_renderWindow->clear();

	// draw all stuff hers

	m_renderWindow->display();
}



/////////////////////////////////////////////////
// 
//		PUBLIC METHODS
//
/////////////////////////////////////////////////

//-----------------------------------------------
//		Constructors
//

Game::Game()
{
	initWindow();
	initEvent();
}



//-----------------------------------------------
//		Destructors
//

Game::~Game()
= default;



//-----------------------------------------------
//		Else methods
//

void Game::run()
{
	while (m_renderWindow->isOpen())
	{
		update();
		render();

		calculateFrameTime();
	}
}



