#include "Track.hpp"

Track::Track()
	: mStartPoint(30.f, 30.f), mEndPoint(360.f, 60.f)
{}

void Track::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape startPoint(6.f);
	sf::CircleShape endPoint(6.f);

	startPoint.setPosition(mStartPoint);
	endPoint.setPosition(mEndPoint);

	target.draw(startPoint);
	target.draw(endPoint);
}