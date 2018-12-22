#include "Mat3.h"

mat3::mat3()
{
	m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0;
}

mat3::mat3(float * ptr)
{
	if (ptr != nullptr)
	{
		m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2];
		m4 = ptr[3]; m5 = ptr[4]; m6 = ptr[5];
		m7 = ptr[6]; m8 = ptr[7]; m9 = ptr[8];
	}
}

mat3::mat3(float _m1, float _m2, float _m3,
	float _m4, float _m5, float _m6,
	float _m7, float _m8, float _m9)
{
	m1 = _m1; m2 = _m2; m3 = _m3;
	m4 = _m4; m5 = _m5; m6 = _m6;
	m7 = _m7; m8 = _m8; m9 = _m9;
}

mat3 mat3::identity()
{
	return mat3(1, 0, 0,
				0, 1, 0,
				0, 0, 1);
}

void mat3::set(float _m1, float _m2, float _m3,
	float _m4, float _m5, float _m6,
	float _m7, float _m8, float _m9)
{
	m1 = _m1; m2 = _m2; m3 = _m3;
	m4 = _m4; m5 = _m5; m6 = _m6;
	m7 = _m7; m8 = _m8; m9 = _m9;
}

void mat3::set(float *ptr)
{
	m1 = ptr[0]; m2 = ptr[1]; m3 = ptr[2];
	m4 = ptr[3]; m5 = ptr[4]; m6 = ptr[5];
	m7 = ptr[6]; m8 = ptr[7]; m9 = ptr[8];
}

void mat3::transpose()
{
	*this = this->getTranspose();
}

mat3 mat3::getTranspose()
{
	mat3 newMat;
	for (int i = 0; i < 3; ++i) // rows
		for (int j = 0; j < 3; ++j) // columns
			newMat.mm[j][i] = mm[i][j];
	return newMat;
}

// returns a translation matrix with the given changes for each axis
mat3 mat3::translation(float x, float y)
{
	return mat3(1, 0, x,
				0, 1, y,
				0, 0, 1);
}
// returns a translation matrix with the given changes for each axis
mat3 mat3::translation(const vec2 &vec)
{
	return translation(vec.x, vec.y);
}
// returns a rotation matrix with the given rotation
mat3 mat3::rotation(float rot)
{
	return mat3(cos(rot), -sin(rot), 0,
				sin(rot), cos(rot), 0,
				0, 0, 1);
}
mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale, 0, 0,
				0, yScale, 0,
				0, 0, 1);
}