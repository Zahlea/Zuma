#include "Track.hpp"

#include <iostream>

#include "InputWrapper.hpp"

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

void Track::Update(float deltaTime)
{
	bool isMouseClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	if (isMouseClicked)
	{
		if (!mWasMouseClicked) {
			mSelectedPointIndex = -1;
			float thicknessSqr = cControlPointThickness * cControlPointThickness;
			for (int i = 0; i < static_cast<int>(mPoints.size()); ++i)
			{
				sf::Vector2f mousePosition = static_cast<sf::Vector2f>(InputWrapper::GetMousePosition());
				sf::Vector2f mouseDelta = mousePosition - mPoints[i];
				float distanceFromPointSqr = mouseDelta.x * mouseDelta.x + mouseDelta.y * mouseDelta.y;

				if (std::abs(distanceFromPointSqr) < thicknessSqr) {
					mSelectedPointIndex = i;
					std::cout << "Selected index: " << i << std::endl;
					break;
				}
			}
		}
		else if(mSelectedPointIndex >= 0) {
			mPoints[mSelectedPointIndex] = static_cast<sf::Vector2f>(InputWrapper::GetMousePosition());
		}
	}
	mWasMouseClicked = isMouseClicked;
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
		target.draw(CreateCircle(cLineThickness, GetPointOnSpline(t), cLineColour));
	}

	target.draw(CreateCircle(cGuidePointThickness, mPoints[0], (mSelectedPointIndex == 0 ? cSelectedPointColour : cGuidePointColour)));

	int endGuideIndex = static_cast<int>(mPoints.size()) - 1;
	target.draw(CreateCircle(cGuidePointThickness, mPoints[endGuideIndex], (mSelectedPointIndex == endGuideIndex ? cSelectedPointColour : cGuidePointColour)));;

	for (int i = 1; i <= static_cast<int>(mPoints.size()) - 2; ++i)
	{
		target.draw(CreateControlPoint(i));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		target.draw(CreateCircle(6.f, static_cast<sf::Vector2f>(InputWrapper::GetMousePosition())));
	}
}

sf::RectangleShape Track::CreateControlPoint(const int index) const
{
	sf::RectangleShape splineControlPoint({ cControlPointThickness, cControlPointThickness });
	splineControlPoint.setPosition(mPoints[index]);
	splineControlPoint.setFillColor(mSelectedPointIndex == index ? cSelectedPointColour : cControlPointColour);
	splineControlPoint.setOrigin({ cControlPointThickness * 0.5f, cControlPointThickness * 0.5f });

	return splineControlPoint;
}

sf::CircleShape Track::CreateCircle(const float radius, const sf::Vector2f& position, const sf::Color& colour) const
{
	sf::CircleShape shape(radius);
	shape.setOrigin({ radius, radius });
	shape.setPosition(position);
	shape.setFillColor(colour);

	return shape;
}
