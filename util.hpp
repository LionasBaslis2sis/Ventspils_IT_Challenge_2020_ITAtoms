#include <SFML/System/Vector2.hpp>

typedef sf::Vector2<float> vec2;

struct ray {
	constexpr ray() noexcept : orig(0, 0), dir(0, 0) { }
	constexpr ray(const vec2& orig, const vec2& dir) noexcept : orig(orig), dir(dir) { }
	vec2 orig;
	vec2 dir;
};

constexpr vec2 interpolate(const vec2& point, const ray &R1, const ray &R2, const ray &R3, const ray &R4, float scale) noexcept {
	vec2 result{0, 0};
	float dx1 = 
}