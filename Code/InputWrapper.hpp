#pragma once

#include <memory>

namespace sf
{
	class RenderWindow;

	template<typename T>
	class Vector2;

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
}

class InputWrapper
{
public:
	static void SetRenderWindow(std::shared_ptr<sf::RenderWindow> window);

	// Mouse input functions
	static sf::Vector2i GetMousePosition();

private:
	static std::shared_ptr<sf::RenderWindow> sRenderWindow;
};
