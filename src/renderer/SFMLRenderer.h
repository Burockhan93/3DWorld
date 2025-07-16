#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class SFMLRenderer {
public:
	SFMLRenderer() = default;
	~SFMLRenderer() = default;
	// Initialize the renderer
	void draw(const sf::Drawable& drawable);
	void update();
private:
	std::vector<sf::Drawable*> m_drawables; // Store drawable objects

};
