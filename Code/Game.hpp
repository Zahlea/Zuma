#pragma once

#include <SFML/Graphics.hpp>

class Game {
public:
	Game();

	bool Run();

private:
	sf::RenderWindow mWindow;

	void Update();
	void Draw();
};