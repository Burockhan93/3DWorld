#include "SimpleRenderer.h"	

std::vector<GLfloat> textureCoords;

void insertTextureCoords(const std::vector<GLfloat>& coords) {
	textureCoords.insert(textureCoords.end(), coords.begin(), coords.end());
}

SimpleRenderer::SimpleRenderer() {

}

void SimpleRenderer::draw(const Cube& cube) {
	m_cubes.push_back(&cube);
}
void SimpleRenderer::update(const Camera& camera) {
	m_shader.bind();
	m_shader.setProjectionViewMatrix(camera.get_view_matrix());
	m_cubeModel.bind();
	for (const Cube* cube : m_cubes) {
		prepare(*cube);
		glDrawElements(GL_TRIANGLES, m_cubeModel.getIndicesCount(), GL_UNSIGNED_INT, 0);
	}
	m_cubes.clear(); // Clear the cubes after drawing
}

void SimpleRenderer::prepare(const Cube& cube) {
	m_shader.setModelMatrix(createModelMatrix(cube));
}