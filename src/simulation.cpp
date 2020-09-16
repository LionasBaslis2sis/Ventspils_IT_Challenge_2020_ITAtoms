#include "simulation.hpp"

Simulation::Simulation(const sf::VideoMode& mode) noexcept {
    map.loadFromFile("res/map.png");
    map_spr = sf::Sprite(map);
    grid = Grid({24, 16}, {32, 32});
    
    grid.setTileCornerColor({1, 1}, 0, {0, 255, 0});
}

void Simulation::iterate(int dt) noexcept {

}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // draw the color grid
    target.draw(grid, states);
    // draw the lithuania map
    target.draw(map_spr, states);
}