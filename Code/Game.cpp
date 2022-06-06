#include "Game.hpp"

#include <iostream>

Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "Zuma")
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
	mWindow.clear({ 100, 149, 237, 255 });
	mWindow.draw(mShape);
	mWindow.display();
}