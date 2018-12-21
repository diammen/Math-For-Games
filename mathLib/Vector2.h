#pragma once
#include <cmath>
#include <cfloat>

struct vec2
{
#ifdef RAYLIB_H
	vec2(Vector2 vec)
	{
		x = vec.x;
		y = vec.y;
}

	vec2& operator=(const Vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;

		return *this;
	}
	operator Vector2()
	{
		return { x, y };
	}
#endif

	float x, y;

	vec2();
	vec2(float _x, float _y);

	float magnitude() const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

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
	vec2 operator*(const float rhs) const { return { x * rhs, y * rhs }; }
	friend vec2 operator*(const float lhs, const vec2 &rhs)
	{
		return { lhs * rhs.x, lhs * rhs.y };
	}
	vec2 operator/(const float rhs) const { return vec2(x / rhs, y / rhs); }

	vec2 &operator+=(const vec2 &rhs) { x += rhs.x; y += rhs.y; return *this; }
	vec2 &operator-=(const vec2 &rhs) { x -= rhs.x; y -= rhs.y; return *this; }

	float dot(const vec2 &rhs) const;

	bool operator==(const vec2 &rhs) const
	{
		//if (abs(rhs.x - x) < (FLT_EPSILON * 1000) && abs(rhs.y - y) < (FLT_EPSILON * 1000))
		//{
		//	return true;
		//}
		//return false;
		return (abs(x - rhs.x) < (1) && abs(y - rhs.y) < (1));
	};
	bool operator!=(const vec2 &rhs) const
	{
		//if (abs(x - rhs.x) < (FLT_EPSILON * 10) && abs(y - rhs.y) < (FLT_EPSILON * 10))
		//{
		//	return false;
		//}
		//return true;
		return !(abs(x - rhs.x) < (1) && abs(y - rhs.y) < (1));
	};

	vec2 operator-() const { return vec2(-x, -y); }

	operator float *()
	{
		return &x;
	}
	operator const float *() const
	{
		return &x;
	}
};

//vec2 operator*(const float lhs, const vec2 &rhs);