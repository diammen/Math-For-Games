#include <iostream>
#include <cassert>
#include <time.h>
#include "mathlib.h"
#include "macros.h"

int main()
{
	int yay = min(2, 3);
	int nay = max(2, 3);
	int way = clamp(0, 1, 3);
	int may = clamp(4, 1, 3);
	int lay = abs(-10);
	int fay = pow(2, 2);
	bool tay = isPowerOfTwo(fay);
	int bay = nextPowerOfTwo(fay);
	int hay = 0;
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, vec2(18.5f, -44.24f));
	TEST("Vector3 addition", v3c, vec3(18.5f, -44.24f, 850));
	TEST("Vector4 addition", v4c, vec4(18.5f, -44.24f, 850, 1));
	equalAssert("min", 2, min(2,3));
	equalAssert("max", 3, max(2, 3));
	equalAssert("clamp", 1, clamp(0, 1, 3));
	equalAssert("clamp", 3, clamp(4, 1, 3));
	equalAssert("abs", 10, abs(-10));
	equalAssert("pow", 4, pow(2, 2));
	
	boolAssert("isPowerOfTwo", isPowerOfTwo(fay));
	equalAssert("nextPowerOfTwo", 8, nextPowerOfTwo(fay));
	
	vec2 a = { 2, 2, };
	vec2 b = { 1, 1, };
	vec2 diff = a - b;

	nearAssert("diff x", 1.0f, diff.x, 0.0001f);

	gen tRand;
	gen fRand;

	tRand.seedRand(time(NULL));
	fRand.seedRand(time(NULL));
	int result = tRand.rand(0, 10);
	float fresult = fRand.randDecimal(0.0f, 5.0f);

	mat3 matrix1(2, -1, 1, 1, 3, 1, 2, 3, 1);
	mat3 matrix2(1, 2, 4, 3, 4, 1, 2, 4, 3);
	mat3 matrix3 = matrix1 * matrix2;

	matrix1 *= matrix2;

	bool yes = matrix1 == matrix3;

	matrix1.transpose();

	TEST("Matrix3 multiply", matrix3, mat3(1, 4, 10, 12, 18, 10, 13, 20, 14));
	TEST("Matrix3 transpose", matrix1, mat3(1, 12, 13, 4, 18, 20, 10, 10, 14));

	vec3 testVec3 = { 2,2,2 };
	vec2 testVec2 = { 2,2 };

	vec3 vec3Result = matrix2 * testVec3;
	vec2 vec2Result = matrix2 * testVec2;

	getchar();
	return 0;
}