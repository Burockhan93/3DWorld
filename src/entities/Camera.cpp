#include "Camera.h"

Camera::Camera() : Entity() {

	m_projection_matrix = create_projection_matrix(m_fov, m_near_plane, m_far_plane);
	
}

Camera::Camera(float FOV, float nearPlane, float farPlane) : Entity(), m_fov{ FOV }, m_near_plane{ nearPlane }, m_far_plane{farPlane} {
	//create projection matrix
	m_projection_matrix = create_projection_matrix(m_fov,m_near_plane,m_far_plane);
}

Mat4 Camera::create_projection_matrix(float m_fov, float m_near_plane, float m_far_plane, bool default_aspect_ratio) const {

	if(default_aspect_ratio)
		return glm::perspective(glm::radians(m_fov), 16.0f / 9.0f, m_near_plane, m_far_plane);//gtc/matrx_transform.hpp
	else
		return glm::perspective(glm::radians(m_fov), 1.0f, m_near_plane, m_far_plane);
}
Mat4 Camera::create_view_matrix(const Camera& camera) const{

	Mat4 view_matrix = Mat4(1.0f);

	//negate the angles
	view_matrix = glm::rotate(view_matrix, glm::radians(-camera.rotation.x), Vec3(1.0f, 0.0f, 0.0f));
	view_matrix = glm::rotate(view_matrix, glm::radians(-camera.rotation.y), Vec3(0.0f, 1.0f, 0.0f));
	view_matrix = glm::rotate(view_matrix, glm::radians(-camera.rotation.z), Vec3(0.0f, 0.0f, 1.0f));

	view_matrix = glm::translate(view_matrix, -camera.position);
	return view_matrix;

}
Mat4 Camera::create_view_projection_matrix() const {
	return m_projection_matrix * m_view_matrix;
}
const Mat4& Camera::get_projection_matrix() const {
	return m_projection_matrix;
}
const Mat4& Camera::get_view_matrix() const {
	return m_view_matrix;
}
const Mat4& Camera::get_view_projection_matrix() const {
	return m_view_projection_matrix;
}
const Frustum& Camera::getFrustum() const {
	return m_frustum;
}
void Camera::set_entity(const Entity& entity) {
	m_entity = &entity;
}
void Camera::unset_entity() {
	m_entity = nullptr;
}
void Camera::set_fov(float fov) {
	m_fov = fov;
	m_projection_matrix = create_projection_matrix(m_fov, m_near_plane, m_far_plane);
}
float Camera::get_fov() const {
	return m_fov;
}
void Camera::set_projection_matrix(const Mat4& projection_matrix) {
	m_projection_matrix = projection_matrix;
}
void Camera::set_view_matrix(const Mat4& view_matrix) {
	m_view_matrix = view_matrix;
}
void Camera::set_view_projection_matrix(const Mat4& view_projection_matrix) {
	m_view_projection_matrix = view_projection_matrix;
}
void Camera::set_position(const Vec3& pos) {
	Entity::set_position(pos);
	m_view_matrix = create_view_matrix(*this);
	m_view_projection_matrix = create_view_projection_matrix();
}
void Camera::set_rotation(const Vec3& rot) {
	Entity::set_rotation(rot);
	m_view_matrix = create_view_matrix(*this);
	m_view_projection_matrix = create_view_projection_matrix();
}
