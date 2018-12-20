#include "Vector3.h"
#include <cmath>
#include <cfloat>

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float vec3::dot(const vec3 &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

float vec3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

vec3 vec3::cross(const vec3 &rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}

vec3 &vec3::scale(const vec3 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 &rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z };
}

vec3 &vec3::normalize()
{
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
	return *this;
}

vec3 vec3::getNormalized() const
{
	return { x / magnitude(), y / magnitude(), z / magnitude() };
}

//vec3 operator*(const float lhs, const vec3 &rhs)
//{
//	return { lhs * rhs.x, lhs * rhs.y, lhs * rhs.z };
//}