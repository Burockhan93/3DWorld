#pragma once

#include "ShaderProgram.h"

class SimpleShader : public ShaderProgram {

public:
	SimpleShader();
	SimpleShader(ShaderType type);
	~SimpleShader() override=default;

	void setProjectionViewMatrix(const Mat4& projection);
	void setModelMatrix(const Mat4& model);
protected:
	virtual void getUniformLocations() override;
	GLuint m_projectionViewMatrixLocation;
	GLuint m_modelMatrixLocation;
};