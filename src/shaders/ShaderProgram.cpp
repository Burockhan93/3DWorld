#include "ShaderProgram.h"
#include <stdexcept>

ShaderProgram::ShaderProgram(ShaderType type, bool useBlock) {
	m_programID = loadShaders(type,useBlock);
	if (m_programID == 0) {
		throw std::runtime_error("Failed to load shader program.");
	}
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(m_programID);
}
void ShaderProgram::bind() {
	glUseProgram(m_programID);
}
void ShaderProgram::unbind() {
	glUseProgram(0);
}

void ShaderProgram::loadInt(GLuint location, int value) {
	glUniform1i(location, value);
}
void ShaderProgram::loadFloat(GLuint location, float value) {
	glUniform1f(location, value);
}
//glUniform2fv expects a pointer, whereas glUniform2f a value.
// thats why we use &value[0] to get the pointer to the first element of the Vec2 array.
// also on matrices the same
void ShaderProgram::loadVec2(GLuint location, const Vec2& value) {
	glUniform2fv(location, 1, &value[0]);
}
void ShaderProgram::loadVec3(GLuint location, const Vec3& value) {
	glUniform3fv(location, 1, &value[0]);
}
void ShaderProgram::loadMatrix4(GLuint location, const Mat4& value) {
	glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}
void ShaderProgram::checkCompileErrors(GLuint shader, const std::string& type) {
	GLint isSuccess;
	GLchar infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isSuccess);
	if (!isSuccess) {
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		throw std::runtime_error("Error compiling " + type + ": " + std::string(infoLog));
	}
}