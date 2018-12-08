#include "Vector4.h"

vec4::vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

vec4::vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

float vec4::dot(const vec4 &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

vec4 vec4::cross(const vec4 &rhs) const
{
	return { y*rhs.z - z * rhs.y, z*rhs.x - x * rhs.z, x*rhs.y - y * rhs.x, 0 };
}