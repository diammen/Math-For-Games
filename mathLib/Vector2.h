#pragma once
#include <cmath>
#include <cfloat>

struct vec2
{
#ifdef RAYLIB_H
	operator Vector2() {};
#endif

	float x, y;

	vec2();
	vec2(float _x, float _y);

	float magnitude() const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 operator*(const float rhs) const
	{
		return { x * rhs, y * rhs };
	}
	friend vec2 operator*(const float lhs, const vec2 &rhs)
	{
		return { lhs * rhs.x, lhs * rhs.y };
	}

	vec2 &operator*=(const float rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}
	vec2 &operator/=(const float rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	vec2 operator+(const vec2 &rhs) const { return vec2(x + rhs.x, y + rhs.y); }
	vec2 operator-(const vec2 &rhs) const { return vec2(x - rhs.x, y - rhs.y); }

	vec2 &operator+=(const vec2 &rhs) { x += rhs.x; y += rhs.y; return *this; }
	vec2 &operator-=(const vec2 &rhs) { x -= rhs.x; y -= rhs.y; return *this; }

	bool operator==(const vec2 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const vec2 &rhs) const
	{
		if (rhs.x - x < FLT_EPSILON && rhs.y - y < FLT_EPSILON)
		{
			return false;
		}
		return true;
	};

	vec2 operator-() const { return vec2(-x, -y); }

	operator float *()
	{
		return *this;
	}
	operator const float *() const
	{
		return *this;
	}
};