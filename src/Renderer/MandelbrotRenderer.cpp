#include "src/renderer/MandelbrotRenderer.h"

#include <vector>
#include <span>
#include <type_traits>

const std::span<sf::Color> MandelbrotRenderer::drawFrame() {
	const auto sizePx = window_.getSize();
	frame.resize(sizePx.x * sizePx.y, sf::Color::Magenta);

	// Test pattern to ensure render is dynamic: hash screen size and turn it into colors
	const auto hash = [](const auto& thing){
		std::hash<std::remove_cvref_t<decltype(thing)>> hasher;
		return static_cast<sf::Uint32>(hasher(thing));
	};
	const sf::Color color0(hash(sizePx.x));
	const sf::Color color1(hash(sizePx.y));

	for(size_t i = 0; i<frame.size(); i++){
		if(i&1) frame[i] = color1;
		else frame[i] = color0;
	}
	// std::vector<sf::Color> frame(sizePx.x * sizePx.y, sf::Color::Magenta);
	// TODO: actually render mandelbrot; parallelize?
	return frame;
}