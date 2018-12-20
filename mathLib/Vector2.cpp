#include "Vector2.h"

vec2::vec2()
{
	x = 0;
	y = 0;
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

float vec2::magnitude() const
{
	return sqrt(x * x + y * y);
}

vec2 &vec2::normalize()
{
	x /= magnitude();
	y /= magnitude();
	return *this;
}

vec2 vec2::getNormalized() const
{
	return { x / magnitude(), y / magnitude() };
}

vec2 &vec2::scale(const vec2 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 &rhs) const
{
	return { x * rhs.x, y * rhs.y };
}

float vec2::dot(const vec2 &rhs) const
{
	return x * rhs.x + y * rhs.y;
}

//vec2 operator*(const float lhs, const vec2 &rhs)
//{
//	return { lhs * rhs.x, lhs * rhs.y };
//}