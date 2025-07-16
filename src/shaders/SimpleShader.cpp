#include "SimpleShader.h"
#include <stdexcept>

SimpleShader::SimpleShader() : ShaderProgram(ShaderType::SIMPLE,false) {
	getUniformLocations();
}
SimpleShader::SimpleShader(ShaderType type) : ShaderProgram(type,false) {
	getUniformLocations();
}
void SimpleShader::setProjectionViewMatrix(const Mat4& projection) {
	loadMatrix4(m_projectionViewMatrixLocation, projection);
}
void SimpleShader::setModelMatrix(const Mat4& model) {
	loadMatrix4(m_modelMatrixLocation, model);
}
void SimpleShader::getUniformLocations() {
	m_projectionViewMatrixLocation = glGetUniformLocation(m_programID, "projViewMatrix");
	if (m_projectionViewMatrixLocation == -1) {
		throw std::runtime_error("Could not find uniform location for projectionViewMatrix");
	}
	m_modelMatrixLocation = glGetUniformLocation(m_programID, "modelMatrix");
	if (m_modelMatrixLocation == -1) {
		throw std::runtime_error("Could not find uniform location for modelMatrix");
	}
}