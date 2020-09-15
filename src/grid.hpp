#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "util.hpp"

class Grid : public sf::Drawable, public sf::Transformable {
public:
    Grid() noexcept : width(0), height(0), count(0), tile_size(0, 0) { }
    Grid(const sf::Vector2i grid_size, const sf::Vector2f& tile_size) noexcept;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::array<sf::Vector3i, 3> getNearbyCornerData(const sf::Vector2i& p, unsigned int corner) const;
    void setTileCornerColor(const sf::Vector2i& position, unsigned int corner, const sf::Color& color);
    constexpr bool vertexExists(unsigned int i) const noexcept { return i < 4 * count; }

public:
    int width, height;
    unsigned int count;
    sf::VertexArray vertices;
    sf::Vector2f tile_size;
};