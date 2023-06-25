#pragma once

#include "src/Renderer/Renderer.h"

struct MandelbrotRenderer : Renderer {
	using Renderer::Renderer;
	const std::span<sf::Color> drawFrame() override;
private:
	std::vector<sf::Color> frame;
};