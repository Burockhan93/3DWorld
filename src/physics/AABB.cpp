#include "AABB.h"


AABB::AABB(const Vec3& min, const Vec3& max) : m_min(min), m_max(max) {}
AABB::AABB(const Vec3& size) : m_size(size) {}
// Check if a point is inside the AABB
bool AABB::contains(const Vec3& point) const {
	return (point.x >= m_min.x && point.x <= m_max.x &&
		point.y >= m_min.y && point.y <= m_max.y &&
		point.z >= m_min.z && point.z <= m_max.z);
}
// Check if another AABB collides with this one.
bool AABB::intersects(const AABB& other) const {
	return (m_min.x <= other.m_max.x && m_max.x >= other.m_min.x &&
		m_min.y <= other.m_max.y && m_max.y >= other.m_min.y &&
		m_min.z <= other.m_max.z && m_max.z >= other.m_min.z);
}

void AABB::update_position(const Vec3& position) {
	m_min = position; // Update the minimum corner to the new position
	m_max = m_min + m_size; // Update the maximum corner based on the new position and size
}

Vec3 AABB::get_size() const
{
	return m_size;
}

Vec3 AABB::get_vertex_neg(const Vec3& normal) const
{
	Vec3 res = m_min;

	if (normal.x < 0)
	{
		res.x += m_size.x;
	}
	if (normal.y < 0)
	{
		res.y += m_size.y;
	}
	if (normal.z < 0)
	{
		res.z += m_size.z;
	}

	return res;
}

Vec3 AABB::get_vertex_pos(const Vec3& normal) const
{
	Vec3 res = m_min;

	if (normal.x > 0)
	{
		res.x += m_size.x;
	}
	if (normal.y > 0)
	{
		res.y += m_size.y;
	}
	if (normal.z > 0)
	{
		res.z += m_size.z;
	}

	return res;
}
