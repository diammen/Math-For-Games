#pragma once
#include "Vector4.h"
#include "Vector3.h"
struct mat4
{
	union
	{
		struct
		{
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
			vec3 wAxis;
		};
		vec3 axis[4];
		struct
		{
			float m1, m2, m3, m4,
				m5, m6, m7, m8,
				m9, m10, m11, m12,
				m13, m14, m15, m16;
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float mm[4][4];
		};
	};

	mat4();
	mat4(float *ptr);
	mat4(float m1, float m2, float m3, float m4,
		float m5, float m6, float m7, float m8,
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16);

	// implicit operator to convert mat4 into a float array
	operator float *()
	{
		float *ptr = m;
		return ptr;
	}

	// returns vec3 objects when accessing by subscript operator
	vec3 &operator[](const int index)
	{
		return axis[index];
	}

	// concatenates two matrices together and returns the result
	mat4  operator*(const mat4 &rhs) const
	{
		mat4 newMat;
		for (int i = 0; i < 4; ++i) // y columns on first matrix
			for (int j = 0; j < 4; ++j) // x rows on second matrix
				for (int k = 0; k < 4; ++k) // both y columns and x rows
					newMat.mm[i][j] += mm[i][k] * rhs.mm[k][j];
		return newMat;
	}
	// concatenates and assigns the result to the matrix
	mat4 &operator*=(const mat4 &rhs)
	{
		mat4 newMat;
		for (int i = 0; i < 4; ++i) // y columns on first matrix
			for (int j = 0; j < 4; ++j) // x rows on second matrix
				for (int k = 0; k < 4; ++k) // both y columns and x rows
					newMat.mm[i][j] += mm[i][k] * rhs.mm[k][j];
		(*this).set(newMat);
		return *this;
	}

	// returns true if the matrices are equal
	bool operator==(const mat4 &rhs) const
	{
		return (xAxis == rhs.xAxis && yAxis == rhs.yAxis && zAxis == rhs.zAxis);
	}
	// returns true if the matrices are inequal
	bool operator!=(const mat4 &rhs) const
	{
		return !(xAxis == rhs.xAxis && yAxis == rhs.yAxis && zAxis == rhs.zAxis);
	}

	// returns a 4x4 identity matrix
	static mat4 identity();

	// updates the matrix elements with the given values
	void set(float m1, float m2, float m3, float m4,
		float m5, float m6, float m7, float m8,
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16);

	// updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	mat4 getTranspose();

	// returns a translation matrix with the given changes for each axis
	static mat4 translation(float x, float y, float z);
	// returns a translation matrix with the given changes for each axis
	static mat4 translation(const vec3 &vec);
	// returns a rotation matrix with the given rotation
	static mat4 rotation(float rot, int axis);
	// returns a translation matrix with the given changes for each axis
	static mat4 scale(float xScale, float yScale, float zScale);

	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec3 operator*(const vec3 &rhs) const
	{
		vec3 newVec;
		for (int i = 0; i < 4; ++i) // y columns on first matrix
			for (int j = 0; j < 4; ++j) // x rows on second matrix
				newVec[i] += mm[i][j] * rhs[j];
		return newVec;
	}
	// convenience function for transforming a 3D vector
	vec3 operator*(const vec3 &rhs) const
	{
		vec3 newVec;
		for (int i = 0; i < 3; ++i) // y columns on first matrix
			for (int j = 0; j < 3; ++j) // x rows on second matrix
				newVec[i] += mm[i][j] * rhs[j];
		return newVec;
	}
};