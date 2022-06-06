#include "Track.hpp"

sf::Color cLineColour(sf::Color::Black);
sf::Color cGuidePointColour(sf::Color::Blue);
sf::Color cControlPointColour(sf::Color::Red);
sf::Color cSelectedPointColour(sf::Color::Yellow);
float cLineThickness(6.f);
float cGuidePointThickness(6.f);
float cControlPointThickness(12.f);

Track::Track()
{
	mPoints.push_back({ 150.f, 450.f });		// Guide point 0
	mPoints.push_back({ 180.f, 300.f });		// Spline point 0
	mPoints.push_back({ 450.f, 210.f });		// Spline point 1
	mPoints.push_back({ 600.f, 360.f });		// Spline point 2
	mPoints.push_back({ 960.f, 60.f });			// Spline point 3
	mPoints.push_back({ 660.f, 600.f });		// Spline point 4
	mPoints.push_back({ 300.f, 420.f });		// Spline point 5
	mPoints.push_back({ 270.f, 300.f });		// Guide point 1
}

sf::Vector2f Track::GetPointOnSpline(float t) const
{
	int p0, p1, p2, p3;
	p1 = static_cast<int>(t) + 1;
	p2 = p1 + 1;
	p3 = p2 + 1;
	p0 = p1 - 1;

	t = t - static_cast<int>(t);

	float tSqr = t * t;
	float tCube = tSqr * t;

	float weight0 = -tCube + 2.f * tSqr - t;
	float weight1 = 3.f * tCube - 5.f * tSqr + 2.f;
	float weight2 = -3.f * tCube + 4.f * tSqr + t;
	float weight3 = tCube - tSqr;

	float x = 0.5f * ((mPoints[p0].x * weight0) + (mPoints[p1].x * weight1) + (mPoints[p2].x * weight2) + (mPoints[p3].x * weight3));
	float y = 0.5f * ((mPoints[p0].y * weight0) + (mPoints[p1].y * weight1) + (mPoints[p2].y * weight2) + (mPoints[p3].y * weight3));

	return sf::Vector2f(x, y);
}

void Track::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	float splinePointCount = static_cast<float>(mPoints.size() - 3);
	for (float t = 0.f; t < splinePointCount; t += 0.01f)
	{
		sf::CircleShape splinePoint(cLineThickness);
		splinePoint.setPosition(GetPointOnSpline(t));
		splinePoint.setFillColor(cLineColour);
		target.draw(splinePoint);
	}

	sf::CircleShape startGuide(cGuidePointThickness);
	sf::CircleShape endGuide(cGuidePointThickness);

	startGuide.setPosition(mPoints[0]);
	endGuide.setPosition(mPoints[mPoints.size() - 1]);

	startGuide.setFillColor(cGuidePointColour);
	endGuide.setFillColor(cGuidePointColour);

	target.draw(startGuide);
	target.draw(endGuide);

	for (int i = 1; i <= static_cast<int>(mPoints.size()) - 2; ++i)
	{
		sf::RectangleShape splineControlPoint({ cControlPointThickness, cControlPointThickness });
		splineControlPoint.setPosition(mPoints[i]);
		splineControlPoint.setFillColor(cControlPointColour);
		target.draw(splineControlPoint);
	}
}