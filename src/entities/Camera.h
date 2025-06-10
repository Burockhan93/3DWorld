#pragma once
#include "Entity.h"
#include "..\geometry\Frustum.h"
#include "glm/gtc/matrix_transform.hpp"
class Camera : public Entity {

public:
	Camera();
	Camera(float FOV, float nearPlane, float farPlane);
	void set_entity(const Entity& entity);
	void unset_entity();
	void set_fov(float fov);
	float get_fov() const; 

	void set_projection_matrix(const Mat4& projection_matrix);
	void set_view_matrix(const Mat4& view_matrix);
	void set_view_projection_matrix(const Mat4& view_projection_matrix);

	Mat4 create_projection_matrix(float FOV, float nearPlane, float farPlane, bool defaultAspectratio=true) const;
	Mat4 create_view_matrix(const Camera& camera) const;
	Mat4 create_view_projection_matrix() const;

	const Mat4& get_projection_matrix() const;
	const Mat4& get_view_matrix() const;
	const Mat4& get_view_projection_matrix() const;
	const Frustum& getFrustum() const;

	void set_position(const Vec3& pos) override;
	void set_rotation(const Vec3& pos) override;
	//scale not needed


private:
	const Entity* m_entity = nullptr;
	Frustum m_frustum; // Frustum for visibility checks

	float m_fov = 45.0f;
	float m_near_plane = 0.1f; // Near clipping plane
	float m_far_plane = 100.0f; // Far clipping plane
	Mat4 m_projection_matrix = Mat4(1.0f); // Projection matrix
	Mat4 m_view_matrix = Mat4(1.0f); // View matrix
	Mat4 m_view_projection_matrix = Mat4(1.0f); // View-Projection matrix


};
