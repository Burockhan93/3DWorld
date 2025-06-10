#pragma once
#include "../math/MathUtils.h"
struct Entity
{
	Vec3 position = { 0.0f, 0.0f,0.0f };
	Vec3 rotation = { 0.0f, 0.0f,0.0f };
	Vec3 scale = { 1.0f, 1.0f, 1.0f };

	virtual void set_position(const Vec3& pos) {
		position = pos;
	}
	virtual void set_rotation(const Vec3& rot) {
		rotation = rot;
	}
	virtual void set_scale(const Vec3& scl) {
		scale = scl;
	}
};