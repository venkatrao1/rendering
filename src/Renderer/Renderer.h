#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window.hpp>

#include <span>

// Interface class that can take in user input as well as change in time, and render a framebuffer. 
class Renderer {
public:
	Renderer(sf::Window& window): window_(window) {};
	virtual ~Renderer() = default;

	// called once per frame with an AppState. Returns a row-major framebuffer of window.width * window.height.
	virtual const std::span<sf::Color> drawFrame() = 0;

protected:
	const sf::Window& window_;
};