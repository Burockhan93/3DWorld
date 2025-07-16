#pragma once
#include "GL\glew.h"
#include "Texture.h"
#include <vector>
#include "../math/MathUtils.h"

class TextureAtlas: public Texture {

public:
	TextureAtlas(const std::string& textureName, GLuint size, GLuint textureSize);
	virtual ~TextureAtlas()=default;
	bool loadFile(const std::string& fileName, GLuint size, GLuint textureSize);
	std::vector<GLfloat> getTextureCoordinates(const Vec2& loc) const;
private:
	GLuint m_size; // Size of the atlas (number of textures in one row/column)
	GLuint m_textureSize; // Size of each texture in the atlas
};
