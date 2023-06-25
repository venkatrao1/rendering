#include "src/Renderer/MandelbrotRenderer.h"

#include <SFML/Window.hpp>

using CurrentRendererType = MandelbrotRenderer;

const sf::Vector2u DEFAULT_WINDOW_SIZE{800,600};
constexpr char DEFAULT_WINDOW_TITLE[] = "Rendering"; // SFML doesn't like string_view
