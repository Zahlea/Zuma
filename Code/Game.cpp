#include "Game.hpp"

#include <iostream>

Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "Zuma")
{}

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

void Game::QuitGame()
{
	mWindow.close();
}

void Game::Update()
{
}

void Game::Draw()
{
	mWindow.clear({ 100, 149, 237, 255 });
	mWindow.draw(mBallTrack);
	mWindow.display();
}