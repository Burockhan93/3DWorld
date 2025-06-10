#pragma once
#include <array>
#include "Plane.h"
#include "..\math\MathUtils.h"
#include "..\physics\AABB.h"

class Frustum {
public:
	std::array<Plane, 6> m_planes;

	Frustum() = default;
	Frustum(const std::array<Plane, 6>& planes);
	
	bool contains_point(const Vec3& point) const;
	bool contains_box(const AABB& box) const;
	void update_frustum(const Mat4& mat);
private:
	enum Planes {
		LEFT = 0,
		RIGHT,
		TOP,
		BOTTOM,
		NEAR,
		FAR
	};
	
};
