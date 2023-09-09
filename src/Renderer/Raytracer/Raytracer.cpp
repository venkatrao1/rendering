#include "Raytracer.h"

#include <Eigen/Core>

#include <vector>
#include <type_traits>
#include <complex>
#include <array>
#include <ranges>
#include <execution>

std::span<const sf::Color> Raytracer::drawFrame() {
	using real = float; // for speed (can change to double if needed)
	using parallelization = std::execution::parallel_unsequenced_policy; // no need for sequencing

	const auto sizePx = window_.getSize();
	frame.resize(sizePx.x * sizePx.y, sf::Color::Magenta);

	// TODO

	return frame;
}