#include "src/renderer/MandelbrotRenderer.h"

#include <vector>
#include <span>
#include <type_traits>
#include <complex>
#include <array>
#include <ranges>
#include <execution>

const std::span<sf::Color> MandelbrotRenderer::drawFrame() {
	using real = float; // for speed (can change to double if needed)
	using parallelization = std::execution::parallel_unsequenced_policy; // no need for sequencing

	// compute palette beforehand (TODO: nicer colors?)
	const static std::array<sf::Color, MandelbrotRenderer::MAX_ITER+1> palette = [](){
		std::array<sf::Color, MandelbrotRenderer::MAX_ITER+1> ret;
		for(size_t i = 0; i<=MandelbrotRenderer::MAX_ITER; i++){
			double lerpFrac = i / float(MandelbrotRenderer::MAX_ITER);
			lerpFrac = 1 - std::pow(1-lerpFrac, 15);
			sf::Uint8 iByte = static_cast<sf::Uint8>(lerpFrac*255);
			ret[i] = sf::Color(iByte,iByte,iByte);
		}
		return ret;
	}();

	const auto sizePx = window_.getSize();
	frame.resize(sizePx.x * sizePx.y, sf::Color::Magenta);

	// Okay, let's say the window is from -2 to 2 in the smaller dimension (fit whole image).
	// then each pixel is half a pixel + its coord from the edge.
	const real pixelSize = real(4.0) / std::min(sizePx.x, sizePx.y);
	const real halfScreenX = sizePx.x / real(2.0);
	const real halfScreenY = sizePx.y / real(2.0);

	// parallelize rows (parallelizing columns seems less useful because then you have to manually compute x with a division?)
	const size_t halfScreenInclusiveOfCenter = (sizePx.y+1) >> 1;
	const std::ranges::iota_view<size_t, size_t> rowNums(0, halfScreenInclusiveOfCenter);
	std::for_each(parallelization(), rowNums.begin(), rowNums.end(), [&](const size_t y){
		auto* const beginIter =  &frame[y*sizePx.x];
		auto* iter = beginIter;
		for(size_t x = 0; x < sizePx.x; x++) {
			const std::complex<real> z{
				((x + real(0.5)) - halfScreenX) * pixelSize,
				((y + real(0.5)) - halfScreenY) * pixelSize
			};
			unsigned i = 0;
			for(auto coords = z; i < MAX_ITER && std::abs(coords) < real(2); i++){
				coords *= coords;
				coords += z;
			}
			static_assert(MAX_ITER == 255); // otherwise below is invalid
			*iter = palette[i];
			++iter;
		}
		// if not center row, use a memcpy to just mirror (saves half the work because of bilateral symmetry)
		if((y << 1) != sizePx.y - 1) {
			memcpy(&frame[(sizePx.y - 1 - y)*sizePx.x], beginIter, sizeof(sf::Color)*sizePx.x);
		}
	});

	return frame;
}