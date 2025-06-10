#pragma once

#include "../math/MathUtils.h"

//box based collision detetction
class AABB {
public:
    Vec3 m_min{}; // Minimum corner 
    Vec3 m_max{}; // Max corner 
    Vec3 m_size{}; //size-dimensions
    AABB(const Vec3& min, const Vec3& max);
    AABB(const Vec3& size);
	// Check if a point is inside the AABB
    bool contains(const Vec3& point) const;
	// Check if another AABB collides with this one.
    bool intersects(const AABB& other) const;
    void update_position(const Vec3& position);

    Vec3 get_size() const;
    Vec3 get_vertex_neg(const Vec3& normal) const;
    Vec3 get_vertex_pos(const Vec3& normal) const;
};
