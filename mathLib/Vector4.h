#pragma once
#include <cmath>
#include <cfloat>

struct vec4
{
	float x, y, z, w;

	vec4();
	vec4(float _x, float _y, float _z, float _w);

	vec4 operator+(const vec4 &rhs) const { return vec4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
	vec4 operator-(const vec4 &rhs) const { return vec4(x - rhs.x, y - rhs.y, z + rhs.z, w + rhs.w); }
	vec4 operator*(const float rhs) const { return vec4(x * rhs, y * rhs, z * rhs, w * rhs); }
	friend vec4 operator*(const float lhs, const vec4 &rhs)
	{
		return vec4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
	}
	vec4 operator/(const float rhs) const { return vec4(x / rhs, y / rhs, z / rhs, w / rhs); }

	vec4 &operator+=(const vec4 &rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
	vec4 &operator-=(const vec4 &rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; }
	vec4 &operator*=(const float rhs) { x *= rhs; y *= rhs; z *= rhs; w *= rhs; return *this; }

	bool operator==(const vec4 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON && rhs.z - z < FLT_EPSILON)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const vec4 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON && rhs.z - z < FLT_EPSILON)
		{
			return false;
		}
		return true;
	};

	vec4 operator-() const { return vec4(-x, -y, -z, -w); }

	float magnitude() const;
	float dot(const vec4 &rhs) const;
	vec4 cross(const vec4 &rhs) const;

	vec4 &normalize();
	vec4 getNormalised() const;

	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;

	operator float *()
	{
		return &x;
	}
	operator const float *() const
	{
		return &x;
	}
};

//vec4 operator*(const float lhs, const vec4 &rhs);