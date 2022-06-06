#pragma once

#include <SFML/Graphics.hpp>

class Track : public sf::Drawable
{
public:
	Track();

private:
	sf::Vector2f mStartPoint;
	sf::Vector2f mEndPoint;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
