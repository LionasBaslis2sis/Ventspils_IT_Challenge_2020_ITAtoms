#pragma once

#include <SFML/Graphics.hpp>

class Simulation : public sf::Drawable, public sf::Transformable {
public:
    Simulation() noexcept { };
    Simulation(const sf::VideoMode& mode) noexcept;
    void iterate(int dt, long t) noexcept;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    sf::Texture texture, overlay;
    sf::Shader shader;
    sf::Sprite sprite;
};