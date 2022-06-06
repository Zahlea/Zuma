#include "Game.hpp"

#include <iostream>

Game::Game()
	: mWindow(sf::VideoMode(200, 200), "SFML works!")
	, mShape(100.f)
{
	mShape.setFillColor(sf::Color::Green);
}

bool Game::Run()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}

	Update();
	Draw();

	return mWindow.isOpen();
}

void Game::Update()
{
}

void Game::Draw()
{
	mWindow.clear();
	mWindow.draw(mShape);
	mWindow.display();
}