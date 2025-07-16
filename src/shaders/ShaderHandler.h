#pragma once

#include <string>
#include "GL/glew.h"

enum ShaderType {
	GRASS,
	SKYBOX,
	WATER,
	EARTH,
	SIMPLE,
	SOLID,
	BLOCK
};
std::string getShaderFileName(ShaderType type) {
	switch (type) {
	case GRASS: return "grass";
	case SKYBOX: return "skybox";
	case WATER: return "water";
	case EARTH: return "earth";
	case SIMPLE: return "simple";
	case SOLID: return "solid";
	case BLOCK: return "block";
	default: return "unknown_shader";
	}
}

GLuint loadShaders(ShaderType type, bool useBlock);
GLuint compileShader(const GLchar* source, GLenum type);
GLuint createShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
std::string readShaderFile(const std::string& shaderType);