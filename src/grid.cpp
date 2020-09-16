#include "grid.hpp"

Grid::Grid(const sf::Vector2i grid_size, const sf::Vector2f& ts) noexcept :
width(grid_size.x), height(grid_size.y), count(grid_size.x * grid_size.y), tile_size(ts) {
    shader.loadFromFile("shaders/grid.vert", "shaders/grid.frag"));
    vertices = sf::VertexArray(sf::Quads, 4 * count);
    for(unsigned int i = 0; i < count; i++) {
        // position indices
        int indx = i % width;
        int indy = i / width;
        sf::FloatRect rect = {indx * ts.x, indy * ts.y, ts.x, ts.y};
        setQuad(&vertices[4 * i], rect);
        setQuadColor(&vertices[4 * i], {0, 0, 255});
    }
    
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.shader = &shader;
    target.draw(vertices, states);
}

std::array<sf::Vector3i, 4> Grid::getNearbyCornerData(const sf::Vector2i& p, unsigned int corner) const {
    // this function returns an array of vectors
    // each one holds the index of some adjacent tile and the corner index
    // this function is used to calclulate what tile and which one of it's
    // corners should be colored some color
    
    // we don't need to check for valid position indices and corner index
    // because we will check each data vector outside this function
    // handling everything here would be too tedious

    // instead of using vec3 for the data I should just make a 
    // struct for better readability but I'm too lazy
    std::array<sf::Vector3i, 4> result;
    switch(corner) {
        case 0: result = {{{p.x, p.y, 0}, {p.x - 1, p.y, 1}, {p.x - 1, p.y - 1, 2}, {p.x, p.y - 1, 3}}};

        case 1: result = {{{p.x, p.y, 1}, {p.x, p.y - 1, 2}, {p.x + 1, p.y - 1, 3}, {p.x + 1, p.y, 0}}};

        case 2: result = {{{p.x, p.y, 2}, {p.x + 1, p.y, 3}, {p.x + 1, p.y + 1, 0}, {p.x, p.y + 1, 1}}};

        case 3: result = {{{p.x, p.y, 3}, {p.x, p.y + 1, 0}, {p.x - 1, p.y + 1, 1}, {p.x - 1, p.y, 2}}};
    }
    return result;
}

void Grid::setTileCornerColor(const sf::Vector2i& position, unsigned int corner, const sf::Color& color) {
    // corner - the index of the quad corner
    // 0 -- 1
    // |    |
    // 3 -- 2
    unsigned int t_index = position.x + position.y * width;
    if(t_index > count) throw std::out_of_range("in Grid::setTileCornerColor() invalid tile position");
    if(corner > 3) throw std::out_of_range("in Grid::setTileCornerColor() corner index is out of bounds");
    auto nearby = getNearbyCornerData(position, corner);
    // color other 3 vertices arround so the color "bleeds" to other tiles
    for(auto& n : nearby) {
        int index = 4 * (n.x + n.y * width) + n.z;
        if(vertexExists(index)) vertices[index].color = color;
    }
}