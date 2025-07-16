#include "ChunkShader.h"
#include "..\Constants.h"
#include <stdexcept>

ChunkShader::ChunkShader(ShaderType type) : ShaderProgram(type,true) {
	getUniformLocations();
	bind();
	ShaderProgram::loadInt(m_locationMaxLight, Constants::MAX_LIGHT);
	unbind();
}
void ChunkShader::getUniformLocations() {
	m_locationTimer = glGetUniformLocation(m_programID, "timer");
	if (m_locationTimer == -1) {
		throw std::runtime_error("Could not find uniform location for timer");
	}
	m_locationMaxLight = glGetUniformLocation(m_programID, "maxLightValue");
	if (m_locationMaxLight == -1) {
		throw std::runtime_error("Could not find uniform location for maxLight");
	}
}
void ChunkShader::loadTimer(float timer) {
	// no need to bind the shader program here, as it is already bound in the constructor
	ShaderProgram::loadFloat(m_locationTimer, timer);
}