#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLfloat>& textureCoordinates,
	const std::vector<GLuint>& indices) : m_indicesCount(vertexPositions.size() / 3) //indices.count?
{
	glGenVertexArrays(1, &m_vao);
	bind();
	addVBO(3, vertexPositions); // 3D positions
	addVBO(2, textureCoordinates); // 2D texture coordinates
	addEBO(indices);
}
Model::Model(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLuint>& indices) : m_indicesCount(indices.size())
{
	glGenVertexArrays(1, &m_vao);
	bind();
	addVBO(3, vertexPositions); // 3D positions
	addEBO(indices);
}
Model::~Model() {
	deleteBuffers(); // Clean up resources
}
// Move constructor
Model::Model(Model&& other) noexcept
	: m_vao(other.m_vao),
	m_vboCount(other.m_vboCount),
	m_indicesCount(other.m_indicesCount),
	m_buffers(std::move(other.m_buffers))
{
	other.deleteBuffers(); // Clean up the moved-from object's resources
	//other.m_vao = 0; // Reset the moved-from object's VAO to avoid double deletion
	//other.m_vboCount = 0;
	//other.m_indicesCount = 0;
}
// Move assignment operator
Model& Model::operator=(Model&& other) noexcept {
	if (this != &other) {
		deleteBuffers(); // Clean up current resources
		m_vao = other.m_vao;
		m_vboCount = other.m_vboCount;
		m_indicesCount = other.m_indicesCount;
		m_buffers = std::move(other.m_buffers);

		other.deleteBuffers(); // Clean up the moved-from object's resources

	//	other.m_vao = 0; // Reset the moved-from object's VAO to avoid double deletion
	//	other.m_vboCount = 0;
	//	other.m_indicesCount = 0;
	//
	}
	return *this;
}
void Model::deleteBuffers() {
	if (m_vao != 0) {
		glDeleteVertexArrays(1, &m_vao);
		m_vao = 0;
	}
	for (GLuint buffer : m_buffers) {
		glDeleteBuffers(1, &buffer);
	}
	m_buffers.clear();
	m_vboCount = 0;
	m_indicesCount = 0;
}
void Model::bind() const {
	glBindVertexArray(m_vao);
}
void Model::unbind() const {
	glBindVertexArray(0);
}

void Model::addData(const std::vector<GLfloat>& vertexPositions,
	const std::vector<GLfloat>& textureCoordinates,
	const std::vector<GLuint>& indices) {

	deleteBuffers(); // Clear previous data
	m_indicesCount = indices.size();

	//Reuse the same model object for new data, thats why we delete the buffers first and dont bind the VAO here.
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	addVBO(3, vertexPositions); // 3D positions
	addVBO(2, textureCoordinates); // 2D texture coordinates
	addEBO(indices);
} 

void Model::addVBO(int dim, const std::vector<GLfloat>& data) {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		data.size() * sizeof(data[0]),
		data.data(),
		GL_STATIC_DRAW);

	glVertexAttribPointer(m_vboCount,
		dim,
		GL_FLOAT,
		GL_FALSE,
		0,
		(GLvoid*)0);

	glEnableVertexAttribArray(m_vboCount++);

	m_buffers.push_back(vbo);
}
void Model::addEBO(const std::vector<GLuint>& indices) {
	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(indices[0]),
		indices.data(),
		GL_STATIC_DRAW);
	m_buffers.push_back(ebo);
	m_indicesCount = indices.size();
}

GLuint Model::getVAO() const {
	return m_vao;
}

GLuint Model::getIndicesCount() const {
	return m_indicesCount;
}
