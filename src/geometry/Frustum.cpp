#include "Frustum.h"

Frustum::Frustum(const std::array<Plane, 6>& planes) : m_planes(planes) {}

bool Frustum::contains_point(const Vec3& point) const {
	for (const auto& plane : m_planes) {
		if (plane.isPointAbove(point)) {
			return false; // If the point is above any plane, it's outside the frustum
		}
	}
	return true;
}
bool Frustum::contains_box(const AABB& box) const { //burda implementation farki vaar. bakacaz sonra
	for (const auto& plane : m_planes) {
		// Check if the box is outside the plane
		Vec3 vertex_neg = box.get_vertex_neg(plane.m_normal);
		Vec3 vertex_pos = box.get_vertex_pos(plane.m_normal);
		if (plane.isPointAbove(vertex_neg) && plane.isPointAbove(vertex_pos)) {
			return false; // If both vertices are above the plane, the box is outside the frustum
		}
	}
	return true; // The box is inside or intersects with the frustum
}
void Frustum::update_frustum(const Mat4& mat) {
	// Implementation for updating the frustum planes based on the camera's view and projection matrices
	// This function would typically be called after the camera's position or orientation changes
	
     // left
    m_planes[Planes::LEFT].m_normal.x = mat[0][3] + mat[0][0];
    m_planes[Planes::LEFT].m_normal.y = mat[1][3] + mat[1][0];
    m_planes[Planes::LEFT].m_normal.z = mat[2][3] + mat[2][0];
    m_planes[Planes::LEFT].m_distance = mat[3][3] + mat[3][0];

    // right
    m_planes[Planes::RIGHT].m_normal.x = mat[0][3] - mat[0][0];
    m_planes[Planes::RIGHT].m_normal.y = mat[1][3] - mat[1][0];
    m_planes[Planes::RIGHT].m_normal.z = mat[2][3] - mat[2][0];
    m_planes[Planes::RIGHT].m_distance = mat[3][3] - mat[3][0];

    // bottom
    m_planes[Planes::BOTTOM].m_normal.x = mat[0][3] + mat[0][1];
    m_planes[Planes::BOTTOM].m_normal.y = mat[1][3] + mat[1][1];
    m_planes[Planes::BOTTOM].m_normal.z = mat[2][3] + mat[2][1];
    m_planes[Planes::BOTTOM].m_distance = mat[3][3] + mat[3][1];

    // top
    m_planes[Planes::TOP].m_normal.x = mat[0][3] - mat[0][1];
    m_planes[Planes::TOP].m_normal.y = mat[1][3] - mat[1][1];
    m_planes[Planes::TOP].m_normal.z = mat[2][3] - mat[2][1];
    m_planes[Planes::TOP].m_distance = mat[3][3] - mat[3][1];

    // near
    m_planes[Planes::NEAR].m_normal.x = mat[0][3] + mat[0][2];
    m_planes[Planes::NEAR].m_normal.y = mat[1][3] + mat[1][2];
    m_planes[Planes::NEAR].m_normal.z = mat[2][3] + mat[2][2];
    m_planes[Planes::NEAR].m_distance = mat[3][3] + mat[3][2];

    // far
    m_planes[Planes::FAR].m_normal.x = mat[0][3] - mat[0][2];
    m_planes[Planes::FAR].m_normal.y = mat[1][3] - mat[1][2];
    m_planes[Planes::FAR].m_normal.z = mat[2][3] - mat[2][2];
    m_planes[Planes::FAR].m_distance = mat[3][3] - mat[3][2];

    for (auto& plane : m_planes) {
		// Normalize the plane normals
		float length = glm::length(plane.m_normal);
		if (length > 0.0f) {
			plane.m_normal /= length;
			plane.m_distance /= length;
		}
    }


}