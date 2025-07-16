#pragma once
#include <vector>
#include "..\entities\Cube.h"
#include "..\entities\Camera.h"
#include "..\shaders\SimpleShader.h"
#include "..\Model.h"
class SimpleRenderer {
public:
	SimpleRenderer();
	~SimpleRenderer() = default;
	void draw(const Cube& cube);
	void prepare(const Cube& cube);
	void update(const Camera& camera);
private:

	std::vector<const Cube*> m_cubes;
	SimpleShader m_shader;
	Model m_cubeModel; // Model to render cubes

};
