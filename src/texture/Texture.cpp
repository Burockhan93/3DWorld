#include "Texture.h"
#include "SFML\Graphics\Image.hpp"
#include "GL\glew.h"
#include "../Constants.h"
#include <stdexcept>

Texture::~Texture() {
	clear(); // Ensure resources are cleaned up
}
bool Texture::loadFile(const std::string& fileName) {

	clear();


	std::string filePath = Constants::RESOURCES + "textures/" + fileName + ".png";
	sf::Image img;
	if (!img.loadFromFile(filePath))
	{
		return false; // Failed to load image
	}

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());

	//set wrapping modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//set filtering modes, nearest no mipmap
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
void Texture::clear()
{
	if (m_textureID != 0)
		glDeleteTextures(1, &m_textureID);
}
void Texture::bind()const {
	if (m_textureID != 0) {
		glBindTexture(GL_TEXTURE_2D, m_textureID);
	}
	else {
		throw std::runtime_error("Texture not loaded or invalid texture ID.");
	}
}
void Texture::unbind() const {
	glBindTexture(GL_TEXTURE_2D, 0);
}