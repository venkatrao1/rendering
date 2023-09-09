#pragma once

#include "src/Renderer/Renderer.h"

#include <execution>

struct Raytracer : Renderer {
	using Policy = std::execution::parallel_unsequenced_policy; // no need for sequencing
	using Renderer::Renderer;
	std::span<const sf::Color> drawFrame() override;
private:
	std::vector<sf::Color> frame;
};