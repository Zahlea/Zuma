#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Track : public sf::Drawable
{
public:
	Track();

	void Update(float deltaTime);

private:
	std::vector<sf::Vector2f> mPoints;
	int mSelectedPointIndex{ -1 };

	bool mWasMouseClicked{ false };

	sf::Vector2f GetPointOnSpline(float t) const;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::RectangleShape CreateControlPoint(const int index) const;
	sf::CircleShape CreateCircle(const float radius, const sf::Vector2f& position, const sf::Color& colour = sf::Color::White) const;
};
