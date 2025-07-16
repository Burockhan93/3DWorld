#pragma once
#include "ShaderProgram.h"

class ChunkShader : public ShaderProgram {

public:
	ChunkShader(ShaderType type);
	~ChunkShader() override = default;
	void getUniformLocations() override;
	void loadTimer(float timer);
protected:
	GLuint m_locationTimer;
	GLuint m_locationMaxLight;


};