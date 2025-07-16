#pragma once

#include <string>

class Texture {
public:
	bool loadFile(const std::string& fileName);
	~Texture() = default;
	void bind() const;
	void unbind() const;
	void clear();
private:
	unsigned int m_textureID{ 0 }; // OpenGL texture ID
	int m_width{ 0 }, m_height{ 0 }, m_channels{ 0 }; // Texture dimensions and channels
	std::string m_filepath; // Path to the texture file
	bool m_loaded{ false }; // Flag to check if the texture is loaded successfully
};