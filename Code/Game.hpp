#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Track.hpp"

class Game {
public:
	Game();

	bool RunFrame();
	void QuitGame();

private:
	std::shared_ptr<sf::RenderWindow> mWindow;
	sf::Clock mGameTime;

	Track mBallTrack;

	void Update(float deltaTime);
	void Draw();
};
