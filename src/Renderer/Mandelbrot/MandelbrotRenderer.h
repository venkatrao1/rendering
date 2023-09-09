#pragma once

#include "src/Renderer/Renderer.h"

#include <execution>

struct MandelbrotRenderer : Renderer {
	using Real = float; // for speed (can change to double if needed)
	using Policy = std::execution::parallel_unsequenced_policy; // no need for sequencing
	static constexpr unsigned MAX_ITER = 255; // max iters of mandelbrot algo

	using Renderer::Renderer;
	std::span<const sf::Color> drawFrame() override;
private:
	std::vector<sf::Color> frame;
};