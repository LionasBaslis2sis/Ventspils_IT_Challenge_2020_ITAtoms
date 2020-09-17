#include "simulation.hpp"

Simulation::Simulation(const sf::VideoMode& mode) noexcept {
    overlay.loadFromFile("res/map.png");
    shader.loadFromFile("sim.frag", sf::Shader::Fragment);

    shader.setUniform("overlay", overlay);
    texture.create(mode.width, mode.height);
    sprite = sf::Sprite(texture);
}

void Simulation::iterate(int dt, long t) noexcept {
    shader.setUniform("t", t / 1000.f);
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.shader = &shader;
    target.draw(sprite, states);
}