#include <iostream>

#include "vec3.h"
#include "ray.h"

// returns a color in a vec3
 
//vec3 color(const ray& r) {
//	// get a unit vector from y component
//	vec3 unit_direction = unit_vector(r.direction());
//	// scale the unit vector to 0.0 < t 1.0
//	float t = 0.5 * (unit_direction.y() + 1.0);
//	// in this example, we use right hand rule
//	// so y is going up parallel to screen
//	//    +y |
//	//       |__ +x
//	//      /
//	//   +z
//	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
//	// this returns a lerp: linear interpolation
//	// a blend of values
//	// blended value = (1-t) * start_val + t * end_val, where 0 <= t <= 1
//}

// returns true if this is in the sphere's radius
bool hit_sphere(const vec3& center, float radius, const ray& r) {
	vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2.0 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a*c;
	return (discriminant > 0);
}

// color returns red
vec3 color(const ray& r) {
	// return red if in the circle
	if (hit_sphere(vec3(0, 0, -1), 0.5, r))
		return vec3(1, 0, 0);
	// otherwise, return a blue gradient
	vec3 unit_direction = unit_vector(r.direction());
	// get the y unit vec
	float t = 0.5 * (unit_direction.y() + 1.0);
	// set t between 0.0 and 1.0
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	// create a white/blue gradient
}

int main() {
	int nx = 200;
	int ny = 100;

	vec3 lower_left_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

	// PPM file header
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	// generate file body
	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);

			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			
			vec3 col = color(r);

			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}