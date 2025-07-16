#pragma once
#include "vector"
#include "GL/glew.h"

/// <summary>
/// Wrapper around OpenGL’s VAO/VBO/EBO. Every 3D model should have a Model class.
/// </summary>

class Model {
public:
	Model();
	Model(const std::vector<GLfloat>& vertexPos,
		const std::vector<GLfloat>& textureCoord,//coordinates between 0,0 - 1,1
		const std::vector<GLuint>& indices);
	//without texture coordinates
	Model(const std::vector<GLfloat>& vertexPos,
		const std::vector<GLuint>& indices);

	//prevent copy and assignment
	Model(const Model& other) = delete;
	Model& operator=(const Model& other) = delete;

	//should be moveable
	Model(Model&& other) noexcept;
	Model& operator=(Model&& other) noexcept;


	//bind the model for rendering
	void bind() const;
	void unbind() const;

	void addData(const std::vector<GLfloat>& vertexPos,
		const std::vector<GLfloat>& textureCoord,
		const std::vector<GLuint>& indices);

	void addData(const std::vector<GLfloat>& vertexPos,
		const std::vector<GLuint>& indices);

	void addVBO(int dim, const std::vector<GLfloat>& data);
	void addEBO(const std::vector<GLuint>& indices);

	GLuint getVAO() const;
	GLuint getIndicesCount() const;
	

	~Model();

private:

	void deleteBuffers();
	GLuint m_vao{0}; // Vertex Array Object
	GLuint m_vboCount{0}; // Vertex Buffer Object
	GLuint m_indicesCount{0}; // Element Buffer Object
	std::vector<GLuint> m_buffers; // Store VBOs and EBOs for easy cleanup
};