#pragma once

#include <SFML/Graphics.hpp>

#include "Track.hpp"

class Game {
public:
	Game();

	bool Run();
	void QuitGame();

private:
	sf::RenderWindow mWindow;

	Track mBallTrack;

	void Update();
	void Draw();
};