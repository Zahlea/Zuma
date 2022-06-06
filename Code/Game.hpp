#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
	Game();

	bool Run();

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mShape;

	void Update();
	void Draw();
};