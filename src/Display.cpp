#include "Display.h"
#include "Constants.h"
#include <GL/glew.h>

Display& Display::get() {
	static Display instance;
	return instance;
}

Display::Display() {
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;
    contextSettings.stencilBits = 8;
    contextSettings.antialiasingLevel = 0;//bunu tweakleyeblrz
    contextSettings.majorVersion = 3;
    contextSettings.minorVersion = 3;

    using namespace Constants;
	m_window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Default, contextSettings);

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);//burda 800*600 olarak kullandik, ama desktoptan da degerleri cekeblrz.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}
void Display::close() {
	m_window.close();
}
void Display::update() {
	m_window.display();
}
bool Display::isOpen() {
	return m_window.isOpen();
}
sf::RenderWindow& Display::getWindow() {
	return m_window;
}
void Display::draw(const sf::Drawable& drawable) {
	if (m_window.isOpen()) {
		m_window.draw(drawable);
	}
}
