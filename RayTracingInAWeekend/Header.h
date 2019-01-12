#pragma once

#include "vec3.h"

class ray {
public:
	ray() {}

	// a Ray needs an origin and a direction
	ray(const vec3& a, const vec3& b) {
		A = a;
		B = b;
	}

	// returns the Ray's origin
	vec3 origin() const { return A; }
	// returns the Ray's direction
	vec3 direction() const { return B; }
	// returns a point along the Ray
	vec3 point_at_parameter(float t) const {
		return A + t * B;

	}

private:
	vec3 A; // A is the origin of the Ray
	vec3 B; // B determines the Ray's direction
};