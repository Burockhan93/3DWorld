#pragma once

#include <string>
#include "GL\glew.h"
#include "..\math\MathUtils.h"
#include "ShaderHandler.h"
class ShaderProgram {
public:
	ShaderProgram(ShaderType type);
	virtual ~ShaderProgram();
	virtual void bind();
	virtual void unbind();

protected:
	//members
	GLuint m_programID;
	void loadInt(GLuint location, int value);
	void loadFloat(GLuint location, float value);
	void loadVec2(GLuint location, const Vec2& value);
	void loadVec3(GLuint location, const Vec3& value);
	void loadMatrix4(GLuint location, const Mat4& value);
	void checkCompileErrors(GLuint shader, const std::string& type);
	virtual void getUniformLocations() = 0;

};