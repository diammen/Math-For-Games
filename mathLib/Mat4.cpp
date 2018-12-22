#include "Mat4.h"

mat4::mat4()
{
	m1 = m2 = m3 = m4 =
	m5 = m6 = m7 = m8 =
	m9 = m10 = m11 = m12 =
	m13 = m14 = m15 = m16;
}

mat4::mat4(float * ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2]; m4 = ptr[3];
		m5 = ptr[4]; m6 = ptr[5]; m7 = ptr[6]; m8 = ptr[7];
		m9 = ptr[8]; m10 = ptr[9]; m11 = ptr[10]; m12 = ptr[11];
		m13 = ptr[12]; m14 = ptr[13]; m15 = ptr[14]; m16 = ptr[15];
	}
}

mat4::mat4(float _m1, float _m2, float _m3, float _m4,
	float _m5, float _m6, float _m7, float _m8,
	float _m9, float _m10, float _m11, float _m12,
	float _m13, float _m14, float _m15, float _m16)
{
	m1 = _m1; m2 = _m2; m3 = _m3; m4 = _m4;
	m5 = _m5; m6 = _m6; m7 = _m7; m8 = _m8;
	m9 = _m9; m10 = _m10; m11 = _m11; m12 = _m12;
	m13 = _m13; m14 = _m14; m15 = _m15; m16 = _m16;
}

mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}

void mat4::set(float _m1, float _m2, float _m3, float _m4,
	float _m5, float _m6, float _m7, float _m8,
	float _m9, float _m10, float _m11, float _m12,
	float _m13, float _m14, float _m15, float _m16)
{
	m1 = _m1; m2 = _m2; m3 = _m3; m4 = _m4;
	m5 = _m5; m6 = _m6; m7 = _m7; m8 = _m8;
	m9 = _m9; m10 = _m10; m11 = _m11; m12 = _m12;
	m13 = _m13; m14 = _m14; m15 = _m15; m16 = _m16;
}

void mat4::set(float *ptr)
{
	m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2]; m4 = ptr[3];
	m5 = ptr[4]; m6 = ptr[5]; m7 = ptr[6]; m8 = ptr[7];
	m9 = ptr[8]; m10 = ptr[9]; m11 = ptr[10]; m12 = ptr[11];
	m13 = ptr[12]; m14 = ptr[13]; m15 = ptr[14]; m16 = ptr[15];
}

void mat4::transpose()
{
	*this = this->getTranspose();
}

mat4 mat4::getTranspose()
{
	mat4 newMat;
	for (int i = 0; i < 4; ++i) // rows
		for (int j = 0; j < 4; ++j) // columns
			newMat.mm[j][i] = mm[i][j];
	return newMat;
}

mat4 mat4::translation(float x, float y, float z)
{
	return mat4(1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 0, z,
				0, 0, 0, 1);
}

mat4 mat4::translation(const vec3 &vec)
{
	return translation(vec.x, vec.y, vec.z);
}

mat4 mat4::rotation(float rot, int axis)
{
	switch (axis)
	{
	case 1:
		return mat4(1, 0, 0, 0,
					0, cos(rot), -sin(rot), 0,
					0, sin(rot), cos(rot), 0,
					0, 0, 0, 1);
		break;
	case 2:
		return mat4(cos(rot), 0, sin(rot), 0,
					0, 1, 0, 0,
					-sin(rot), 0, cos(rot), 0,
					0, 0, 0, 1);
		break;
	case 3:
		return mat4(cos(rot), -sin(rot), 0, 0,
					sin(rot), cos(rot), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1);
		break;
	default:
		break;
	}
}

mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	return mat4(xScale, 0, 0, 0,
				0, yScale, 0, 0,
				0, 0, zScale, 0,
				0, 0, 0, 1);
}