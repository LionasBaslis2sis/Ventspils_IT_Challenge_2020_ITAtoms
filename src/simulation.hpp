#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "grid.hpp"

class Simulation : public sf::Drawable, public sf::Transformable {
public:
    Simulation() noexcept { };
    Simulation(const sf::VideoMode& mode) noexcept;
    void iterate(int dt) noexcept;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    sf::Sprite map_spr;
    sf::Texture map;

    Grid grid;
};