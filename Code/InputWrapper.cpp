#include "InputWrapper.hpp"

#include <cassert>

#include <SFML/Graphics.hpp>

std::shared_ptr<sf::RenderWindow> InputWrapper::sRenderWindow = nullptr;

void InputWrapper::SetRenderWindow(std::shared_ptr<sf::RenderWindow> window)
{
	sRenderWindow = window;
}


sf::Vector2i InputWrapper::GetMousePosition()
{
	assert(sRenderWindow, "RenderWindow has not been set");
	return sf::Mouse::getPosition(*sRenderWindow);
}
