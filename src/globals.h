#include <SFML/System/Vector2.hpp>

#include "src/Renderer/Mandelbrot/MandelbrotRenderer.h"
#include "src/Renderer/Raytracer/Raytracer.h"

using CurrentRendererType = Raytracer;

const sf::Vector2u DEFAULT_WINDOW_SIZE{600,600};
constexpr char DEFAULT_WINDOW_TITLE[] = "Rendering"; // SFML doesn't like string_view
