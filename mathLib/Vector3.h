#pragma once
#include <cfloat>

struct vec3
{
	float x, y, z;

	vec3();
	vec3(float _x, float _y, float _z);

	vec3 operator+(const vec3 &rhs) const { return vec3(x + rhs.x, y + rhs.y, z + rhs.z); }
	vec3 operator-(const vec3 &rhs) const { return vec3(x - rhs.x, y - rhs.y, z + rhs.z); }
	vec3 operator*(const float rhs) const { return vec3(x * rhs, y * rhs, z * rhs); }
	friend vec3 operator*(const float lhs, const vec3 &rhs)
	{
		return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
	}
	vec3 operator/(const float rhs) const { return vec3(x / rhs, y / rhs, z / rhs); }


	vec3 &operator+=(const vec3 &rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	vec3 &operator-=(const vec3 &rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
	vec3 &operator*=(const float rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
	vec3 &operator/=(const float rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }

	float magnitude() const;
	float dot(const vec3 &rhs) const;
	vec3 cross(const vec3 &rhs) const;

	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;

	vec3 &normalize();
	vec3 getNormalized() const;

	bool operator==(const vec3 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON && rhs.z - z < FLT_EPSILON)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const vec3 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON && rhs.z - z < FLT_EPSILON)
		{
			return false;
		}
		return true;
	};

	vec3 operator-() const { return vec3(-x, -y, -z); }

	operator float *()
	{
		return *this;
	}
	operator const float *() const
	{
		return *this;
	}
};

//vec3 operator*(const float lhs, const vec3 &rhs);