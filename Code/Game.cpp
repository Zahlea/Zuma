#include "Game.hpp"

#include <iostream>

#include "InputWrapper.hpp"

Game::Game()
	: mWindow(std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Zuma"))
{
	mGameTime.restart();
	InputWrapper::SetRenderWindow(mWindow);
}

bool Game::RunFrame()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mWindow->close();
		}
	}

	Update(mGameTime.restart().asSeconds());
	Draw();

	return mWindow->isOpen();
}

void Game::QuitGame()
{
	mWindow->close();
}

void Game::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		QuitGame();
	}

	mBallTrack.Update(deltaTime);
}

void Game::Draw()
{
	mWindow->clear({ 100, 149, 237, 255 });
	mWindow->draw(mBallTrack);
	mWindow->display();
}