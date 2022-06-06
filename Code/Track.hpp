#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Track : public sf::Drawable
{
public:
	Track();

private:
	std::vector<sf::Vector2f> mPoints;

	sf::Vector2f GetPointOnSpline(float t) const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
