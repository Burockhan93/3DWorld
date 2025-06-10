#pragma once
#include "..\math\MathUtils.h"

struct Plane {
	Vec3 m_normal{}; // Normal vector of the plane
	float m_distance{}; // Distance from the origin
	Plane(const Vec3& normal, float d) : m_normal(normal), m_distance(d) {}
	Plane() : m_normal(Vec3(0.0f, 0.0f, 0.0f)), m_distance(0.0f) {}
	// Function to calculate the distance from a point to the plane
	float distanceToPoint(const Vec3& point) const {
		return glm::dot(m_normal, point) + m_distance;
	}
	// Function to check if a point is above the plane
	bool isPointAbove(const Vec3& point) const {
		return distanceToPoint(point) > 0.0f;
	}
};