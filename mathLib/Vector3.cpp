#include "Vector3.h"

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

vec3 vec3::cross(const vec3 &rhs) const
{
	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}