#pragma once

#include "src/Renderer/Renderer.h"

struct MandelbrotRenderer : Renderer {
	static constexpr unsigned MAX_ITER = 255; // max iters of mandelbrot algo

	using Renderer::Renderer;
	const std::span<sf::Color> drawFrame() override;
private:
	std::vector<sf::Color> frame;
};