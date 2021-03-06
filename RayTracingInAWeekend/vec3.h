#pragma once

class vec3 {
public:
	// default constructor disabled
	vec3();
	// accept 3 floats for a default value
	vec3(float e0, float e1, float e2);

	// return the respective components
	inline float x() const { return e[0]; }
	// note: const promises not to modify values in this function
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	// alternate syntax if being used for RGB
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	// OVERLOAD OPERATORS
	// arithmetic operators
	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	// brackets
	inline float operator[] (int i) const { return e[i]; }
	//inline float& operator[] (int i) const { return e[i]; }

	inline vec3& operator+=(const vec3 &v2);
	inline vec3& operator-=(const vec3 &v2);
	inline vec3& operator*=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);
	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);

	inline float length() const {
		return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}
	inline float squared_length() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}
	inline void make_unit_vector();

	// i/ostream needs to be a nonmember function, but also access
	// the internals of vec3, hence friend
	friend inline std::istream& operator>> (std::istream& is, vec3& t);
	friend inline std::ostream& operator<<(std::ostream& os, const vec3 &t);

private:
	// holds the vector values
	float e[3];
};

std::istream& operator>> (std::istream& is, vec3& t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

std::ostream& operator<<(std::ostream& os, const vec3 &t) {
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void vec3::make_unit_vector() {
	float k = 1.0 / std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
	return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
	return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
	return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

inline vec3 operator/(const vec3& v1, const vec3& v2) {
	return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline vec3 operator*(float t, const vec3& v) {
	return vec3(t*v[0], t*v[1], t*v[2]);
}

inline vec3 operator/(float t, const vec3& v) {
	return vec3(t/v[0], t/v[1], t/v[2]);
}

inline vec3 operator*(const vec3& v, float t) {
	return vec3(t*v[0], t*v[1], t*v[2]);
}

inline vec3 operator/(const vec3& v, float t) {
	return vec3(t / v[0], t / v[1], t / v[2]);
}

inline float dot(const vec3& v1, const vec3& v2) {
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3((v1[1] * v2[2] - v1[2] * v2[1]),
		(v1[0] * v2[2] - v1[2] * v2[0]),
		(v1[0] * v2[1] - v1[1] * v2[0]));
}

inline vec3& vec3::operator+=(const vec3& v) {
	e[0] += v[0];
	e[1] += v[1];
	e[2] += v[2];

	return *this;
}

inline vec3& vec3::operator-=(const vec3& v) {
	e[0] -= v[0];
	e[1] -= v[1];
	e[2] -= v[2];

	return *this;
}

inline vec3& vec3::operator*=(const vec3& v) {
	e[0] *= v[0];
	e[1] *= v[1];
	e[2] *= v[2];

	return *this;
}

inline vec3& vec3::operator/=(const vec3& v) {
	e[0] /= v[0];
	e[1] /= v[1];
	e[2] /= v[2];

	return *this;
}

inline vec3& vec3::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;

	return *this;
}

inline vec3& vec3::operator/=(const float t) {
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;

	return *this;
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}