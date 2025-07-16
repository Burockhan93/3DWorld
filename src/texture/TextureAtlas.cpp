#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(const std::string& textureName, GLuint size, GLuint textureSize)
	: m_size(size), m_textureSize(textureSize) {
	loadFile(textureName, size, textureSize);
}
bool TextureAtlas::loadFile(const std::string& fileName, GLuint size, GLuint textureSize) {
	m_size = size;
	m_textureSize = textureSize;
	return Texture::loadFile(fileName);
}
std::vector<GLfloat> TextureAtlas::getTextureCoordinates(const Vec2& loc) const
{
    static float texturesPerRow = m_size / m_textureSize;
    static float unitSize = 1.0f / (float)texturesPerRow;
    static float pixelSize = 1.0f / (float)m_size;

    float xMin = (loc.x * unitSize) + 0.5 * pixelSize;
    float yMin = (loc.y * unitSize) + 0.5 * pixelSize;

    float xMax = (xMin + unitSize) - 0.5 * pixelSize;
    float yMax = (yMin + unitSize) - 0.5 * pixelSize;

    return
    {
        xMax, yMax,
        xMin, yMax,
        xMin, yMin,
        xMax, yMin
    };
}