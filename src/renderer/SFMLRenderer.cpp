#include "SFMLRenderer.h"
#include "..\Display.h"
#include <GL/glew.h>


void SFMLRenderer::draw(const sf::Drawable& drawable) {
	m_drawables.push_back(const_cast<sf::Drawable*>(&drawable));
}

void SFMLRenderer::update() {

	//Disable all openGL states that might interfere with SFML rendering
    glDisable(GL_DEPTH_TEST);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    glUseProgram(0);

	// Reset OpenGL states to ensure SFML can render correctly
    Display::get().getWindow().pushGLStates();
    Display::get().getWindow().resetGLStates();

	// Draw all the drawables(SFML) stored in the vector
	for (const auto& drawable : m_drawables) {
		Display::get().draw(*drawable);
	}
	m_drawables.clear(); // Clear the drawables after drawing
}