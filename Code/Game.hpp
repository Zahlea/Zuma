#pragma once

#include <SFML/Graphics.hpp>

#include "Track.hpp"

class Game {
public:
	Game();

	bool RunFrame();
	void QuitGame();

private:
	sf::RenderWindow mWindow;
	sf::Clock mGameTime;

	Track mBallTrack;

	void Update(float deltaTime);
	void Draw();
};