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
	}
}



