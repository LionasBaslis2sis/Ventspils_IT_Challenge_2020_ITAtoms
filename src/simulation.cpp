#include "simulation.hpp"

Simulation::Simulation(const sf::VideoMode& mode) noexcept {
    map.loadFromFile("res/map.png");
    map_spr = sf::Sprite(map);
    grid = Grid({24, 16}, {32, 32});
    // color random vertices green
    for(unsigned int i = 0; i < grid.count; i++) {
        if(rand() % 2 == 1) grid.setTileCornerColor({i % grid.width, i / grid.height}, rand() % 4, {0, 255, 0});
    }
}

void Simulation::iterate(int dt) noexcept {

}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // draw the color grid
    target.draw(grid, states);
    // draw the lithuania map
    target.draw(map_spr, states);
}