#include "grid.hpp"

Grid::Grid(const sf::Vector2i grid_size, const sf::Vector2f& tile_size) noexcept :
width(grid_size.x), height(grid_size.y), count(grid_size.x * grid_size.y), tile_size(tile_size) {
    vertices = sf::VertexArray(sf::Quads, 4 * count);
    for(unsigned int i = 0; i < count; i++) {
        sf::Vector2i ind{i % width, i / width};
        sf::Vector2f pos{ind.x * tile_size.x, ind.y * tile_size.y};
        sf::Vector2f size =  tile_size;
        setQuad(&vertices[4 * i], {pos.x, pos.y, size.x, size.y});
        setQuadColor(&vertices[4 * i], {0, 0, 255});
    }
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(vertices, states);
}

std::array<sf::Vector3i, 3> Grid::getNearbyCornerData(const sf::Vector2i& p, unsigned int corner) const {
    // this function returns an array of vectors
    // each one holds the index of some adjacent tile and the corner index
    // this function is used to calclulate what tile and which one of it's
    // corners should be colored some color
    
    // we don't need to check for valid position indices and corner index
    // because we will check each data vector outside this function
    // handling everything here would be too tedious

    // instead of using vec3 for the data I should just make a 
    // struct for better readability but I'm too lazy
    std::array<sf::Vector3i, 3> result;
    switch(corner) {
        case 0: result = {{{p.x - 1, p.y, 1}, {p.x - 1, p.y - 1, 2}, {p.x, p.y - 1, 3}}};
        case 1: result = {{{p.x, p.y - 1, 2}, {p.x + 1, p.y - 1, 3}, {p.x + 1, p.y, 0}}};
        case 2: result = {{{p.x + 1, p.y, 3}, {p.x + 1, p.y + 1, 0}, {p.x, p.y + 1, 1}}};
        case 3: result = {{{p.x, p.y + 1, 0}, {p.x - 1, p.y + 1, 1}, {p.x - 1, p.y, 2}}};
    }
    return result;
}

void Grid::setTileCornerColor(const sf::Vector2i& position, unsigned int corner, const sf::Color& color) {
    // corner - the index of the quad corner
    // 0 -- 1
    // |    |
    // 3 -- 2
    unsigned int t_index = position.x + position.y * width;
    if(t_index > count ||  {
        std::cerr << "index out of range or "
        throw std::out_of_range;
    }
    if(corner > 3) {
        std::cerr << "index out of range or "
        throw std::out_of_range;
    }
    auto nearby = getNearbyCornerData(position, corner);
    for(unsigned int i = 0; i < 3; i++) {
        auto data = nearby[i];
        int index = 4 * (data.x + data.y * width) + data.z;
        if(vertexExists(index)) vertices[index].color = color;
    }
}