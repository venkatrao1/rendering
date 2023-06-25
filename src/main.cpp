#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

#include "src/Renderer/MandelbrotRenderer.h"
#include "src/globals.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y), DEFAULT_WINDOW_TITLE);
    window.setVerticalSyncEnabled(true);

    CurrentRendererType renderer(window);

    sf::Texture rendererTex;
    rendererTex.create(DEFAULT_WINDOW_SIZE.x, DEFAULT_WINDOW_SIZE.y);
    sf::Sprite rendererSprite(rendererTex);
    rendererSprite.setOrigin(0,0);

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                using sf::Event;
                case Event::Closed:
                    // "close requested" event: we close the window and exit
                    window.close();
                    std::cout << "Window close requested\n";
                    return 0;
                case Event::Resized:
                    rendererTex.create(event.size.width, event.size.height);
                    sf::FloatRect screenBoxf(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                    sf::IntRect screenBoxi(0, 0, static_cast<int>(event.size.width), static_cast<int>(event.size.height));

                    window.setView(sf::View(screenBoxf));
                    rendererSprite.setTextureRect(screenBoxi);

                    std::cout << "Window resize to (" << event.size.width << ", " << event.size.height << ") requested\n";
                    // std::cout << "View is now (" << window.getView().getSize().x << ", " << window.getView().getSize().y << ")\n";
                    break;
            }
        }
        std::cout << "Poll time: " << clock.getElapsedTime().asMicroseconds() / 1000.0f << " ms\n";

        // call renderer to get data, then update texture
        const auto frame = renderer.drawFrame();

        std::cout << "Render time: " << clock.getElapsedTime().asMicroseconds() / 1000.0f << " ms\n";

        const auto frameSize = window.getSize();
        if(frame.size() != frameSize.x*frameSize.y){
            std::cout << "Incorrect frame size! Probably the renderer's fault?\n";
            continue; // don't update texture
        }

        rendererTex.update(reinterpret_cast<const sf::Uint8*>(frame.data())); // color byte layout should be correct
        window.draw(rendererSprite);

        std::cout << "Frame time: " << clock.getElapsedTime().asMicroseconds() / 1000.0f << " ms\n"; // TODO: display onscreen?

        window.display();
    }

    return 0;
}