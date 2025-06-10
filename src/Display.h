#pragma once

#include "utils\Singleton.h"
#include <SFML/Graphics.hpp>


class Display :Singleton{

public:

	void close();
	void update();
	bool isOpen();
	static Display& get();
	sf::RenderWindow& getWindow();
	void draw(const sf::Drawable& drawable);
private:
	// Private constructor to prevent instantiation
	Display();
	~Display() = default;
	sf::RenderWindow m_window;
	
};