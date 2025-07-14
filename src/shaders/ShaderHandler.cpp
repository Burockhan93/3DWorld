#include "ShaderHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

GLuint loadShaders(ShaderType type) {

	//Shader folder is hard coded, may change
	std::string shaderFolder = "resources/shaders/";
	std::string vertexShader = shaderFolder + getShaderFileName(type) + "_" + "vertex.glsl";
	std::string fragmentShader = shaderFolder + getShaderFileName(type) + "_" + "fragment.glsl";

	std::string vertexShaderCode = readShaderFile(vertexShader);
	std::string fragmentShaderCode = readShaderFile(fragmentShader);
	if (vertexShaderCode.empty() || fragmentShaderCode.empty()) {
		std::cerr << "Failed to read shader files: " << std::endl;
		return 0;
	}
	const char* vertexShaderSource = vertexShaderCode.c_str();
	const char* fragmentShaderSource = fragmentShaderCode.c_str();

	GLuint vertexShaderID = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
	GLuint fragmentShaderID = compileShader(vertexShaderSource, GL_FRAGMENT_SHADER);

	if (vertexShaderID == 0 || fragmentShaderID == 0) {
		std::cerr << "Failed to compile shaders." << std::endl;
		return 0;
	}
	GLuint shaderID = createShaderProgram(vertexShaderID,fragmentShaderID);

	// Check if the shader program was created successfully, then delete the individual shaders
	if (shaderID == 0) {
		std::cerr << "Failed to create shader program." << std::endl;
		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);
		return 0;
	}
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return shaderID;
}
GLuint compileShader(const GLchar* source, GLenum type) {
	
	auto shaderID = glCreateShader(type);

	glShaderSource(shaderID, 1, &source, nullptr);
	glCompileShader(shaderID);

	GLint isSuccess;
	GLchar infoLog[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);

	if (!isSuccess)
	{
		glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
		throw std::runtime_error("Error compiling shader: " + std::string(infoLog));
	}

	return shaderID;
}
GLuint createShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID) {
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	return programID;
}
std::string readShaderFile(const std::string& filePath) {
	std::ifstream shaderFile(filePath);
	if (!shaderFile.is_open()) {
		std::cerr << "Could not open shader file: " << filePath << std::endl;
		return "";
	}
	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();
	shaderFile.close();
	return shaderStream.str();
}