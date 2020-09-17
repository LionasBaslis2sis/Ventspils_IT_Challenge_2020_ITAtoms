#include <SFML/Graphics.hpp>

typedef sf::Vector2<float> vec2;

struct ray {
	ray() noexcept : orig(0, 0), dir(0, 0) { }
	ray(const vec2& orig, const vec2& dir) noexcept : orig(orig), dir(dir) { }
	vec2 orig;
	vec2 dir;
};

/* vec2 interpolate(const vec2& point, const ray &R1, const ray &R2, const ray &R3, const ray &R4, float scale) noexcept {
	return {0, 0};
	//float dx1 = 
} */

constexpr void setQuadColor(sf::Vertex* vertices, const sf::Color& color) noexcept {
	if(!vertices) return;
	vertices[0].color = color;
	vertices[1].color = color;
	vertices[2].color = color;
	vertices[3].color = color;
}

constexpr void setQuad(sf::Vertex* vertices, const sf::FloatRect& rect) noexcept {
	if(!vertices) return;
	vertices[0].position = {rect.left, rect.top};
	vertices[1].position = {rect.left + rect.width, rect.top};
	vertices[2].position = {rect.left + rect.width, rect.top + rect.height};
	vertices[3].position = {rect.left, rect.top + rect.height};
}