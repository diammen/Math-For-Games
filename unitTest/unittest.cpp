#include "unittest.h"
#include <iostream>
#include <iomanip>

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Vector2& rhs) { 
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1]; return os; }
	std::ostream& operator << (std::ostream& os, Vector3& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2]; return os; }
	std::ostream& operator << (std::ostream& os, Vector4& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2] << "," << std::setprecision(12) << a[3]; return os; }
	
	/*std::ostream& operator << (std::ostream& os, Matrix3& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 9; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 8))
				os << ",";
		}
		return os;
	}
	std::ostream& operator << (std::ostream& os, Matrix4& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 16; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 15))
				os << ",";
		}
		return os;
	}*/

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compare(float a, float b, float tolerance = DEFAULT_TOLERANCE) {
	if (abs(a - b) > tolerance)
		return false;
	return true;
}

bool compare( Vector2& A,  Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = (float*)A;
	 float* b = (float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compare( Vector3& A,  Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

bool compare( Vector4& A,  Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance || 
		abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compare( Matrix3& A,  Matrix3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance ||
		abs(a[3] - b[3]) > tolerance || abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance ||
		abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance || abs(a[8] - b[8]) > tolerance)
		return false;
	return true;
}

bool compare( Matrix4& A,  Matrix4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance ||
		abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance || abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance ||
		abs(a[8] - b[8]) > tolerance || abs(a[9] - b[9]) > tolerance || abs(a[10] - b[10]) > tolerance || abs(a[11] - b[11]) > tolerance ||
		abs(a[12] - b[12]) > tolerance || abs(a[13] - b[13]) > tolerance || abs(a[14] - b[14]) > tolerance || abs(a[15] - b[15]) > tolerance)
		return false;
	return true;
}

template <typename T>
bool TestFunc(const char* msg, T& a, T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
		return false;
	}
	return true;
}
// needed for comparing a float variable with a const float
template <typename T>
bool TestFunc(const char* msg, T& a, float b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match -\n\tB: (" << b << ")\n";
		return false;
	}
	return true;
}

#define TEST(a, b, c) {if (TestFunc(a, b, c) == false) {return false;}}

bool runUnitTests() {
	
	//Vector 2,3,4 
	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, Vector2(18.5f,-44.24f));
	TEST("Vector3 addition", v3c, Vector3(18.5f,-44.24f,850));
	TEST("Vector4 addition", v4c, Vector4(18.5f,-44.24f,850,1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vector2 subtraction", v2c, Vector2(8.5f,-52.22f));
	TEST("Vector3 subtraction", v3c, Vector3(8.5f,-52.22f,874));
	TEST("Vector4 subtraction", v4c, Vector4(8.5f,-52.22f,874,-1));

	// vector += 
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2a += v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3a += v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4a += v4b;

	TEST("Vector2 +=", v2a, Vector2(18.5f, -44.24f));
	TEST("Vector3 +=", v3a, Vector3(18.5f, -44.24f, 850));
	TEST("Vector4 +=", v4a, Vector4(18.5f, -44.24f, 850, 1));

	// vector -= 
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2a -= v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3a -= v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4a -= v4b;

	TEST("Vector2 -=", v2a, Vector2(8.5f, -52.22f));
	TEST("Vector3 -=", v3a, Vector3(8.5f, -52.22f, 874));
	TEST("Vector4 -=", v4a, Vector4(8.5f, -52.22f, 874, -1));

	//vector ==
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v2a -= v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v3a -= v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;
	v4a -= v4b;

	TEST("Vector2 ==", v2c, v2a);
	TEST("Vector3 ==", v3c, v3a);
	TEST("Vector4 ==", v4c, v4a);
	TEST("Vector2 ==", v2c, v2c);
	TEST("Vector3 ==", v3c, v3c);
	TEST("Vector4 ==", v4c, v4c);

	//vector !=
	//test true and false?

	//vector invert
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = -v2a;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = -v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = -v4a;

	TEST("Vector2 invert", v2c, Vector2(-13.5f, 48.23f));
	TEST("Vector3 invert", v3c, Vector3(-13.5f, 48.23f, -862));
	TEST("Vector4 invert", v4c, Vector4(-13.5f, 48.23f, -862, 0));

	//vector as array


	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector *=
	v2a = Vector2(13.5f, -48.23f);
	v2a *= 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a *= 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4a *= 4.89f;

	TEST("Vector2 *=", v2a, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 *=", v3a, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 *=", v4a, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));


	// vector dot product
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vector3 cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TEST("Vector4 cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	TEST("Vector3 magnitude", mag3, 863.453735352f);
	TEST("Vector4 magnitude", mag4, 863.453735352f);

	// vector normalise
	v2a = Vector2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.normalize();

	TEST("Vector2 normalise", v2a, Vector2(-0.269548f,-0.962987f));
	TEST("Vector3 normalise", v3a, Vector3(0.0156349f,-0.0558571f,0.998316f));
	TEST("Vector4 normalise", v4a, Vector4(0.270935f,-0.0537745f,0.961094f,0));

	// vector getNormalise
	v2a = Vector2(-13.5f, -48.23f);
	v2b = v2a.getNormalized();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = v3a.getNormalized();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4b = v4a.getNormalized();

	TEST("Vector2 getNormalise", v2b, Vector2(-0.269548f, -0.962987f));
	TEST("Vector3 getNormalise", v3b, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("Vector4 getNormalise", v4b, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));

	// vector scale
	vec2 scale2 = { 5.5f, 3.3f };
	v2a = Vector2(-13.5f, -48.23f);
	v2a.scale(scale2);
	vec3 scale3 = { 5.5f, 3.3f , 1.4f };
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.scale(scale3);
	vec4 scale4 = { 5.5f, 3.3f, 1.4f, 2.6f };
	v4a = Vector4(243, -48.23f, 862, 1);
	v4a.scale(scale4);

	TEST("Vector2 scale", v2a, Vector2(-74.25f, -159.159f));
	TEST("Vector3 scale", v3a, Vector3(74.25f, -159.159f, 1206.7999f));
	TEST("Vector4 scale", v4a, Vector4(1336.5f, -159.159f, 1206.7999f, 2.6f));

	// vector getScaled
	scale2 = { 5.5f, 3.3f };
	v2a = Vector2(-13.5f, -48.23f);
	v2b = v2a.getScaled(scale2);
	scale3 = { 5.5f, 3.3f , 1.4f };
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = v3a.getScaled(scale3);
	scale4 = { 5.5f, 3.3f, 1.4f, 2.6f };
	v4a = Vector4(243, -48.23f, 862, 1);
	v4b = v4a.getScaled(scale4);

	TEST("Vector2 getScaled", v2b, Vector2(-74.25f, -159.159f));
	TEST("Vector3 getScaled", v3b, Vector3(74.25f, -159.159f, 1206.7999f));
	TEST("Vector4 getScaled", v4b, Vector4(1336.5f, -159.159f, 1206.7999f, 2.6f));
	

    
	//Matrix 3 and Matrix 4

	// matrix rotation
	Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;
	//m3a = m3a.rotation(3.98f); //rotationX for mat3 not implemented
	m4a = Matrix4::rotation(4.5f, 1);
	m4a.transpose();
	//m3b = m3b.rotation(1.76f); rotationY for mat3 not implemented
	m4b = Matrix4::rotation(-2.6f, 2);
	m4b.transpose();
	m3c = m3c.rotation(9.62f);
	m3c.transpose();
	m4c = Matrix4::rotation(0.72f, 3);
	m4c.transpose();

	//TEST("Matrix3 set rotate1", m3a, Matrix3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	//TEST("Matrix3 set rotate2", m3b, Matrix3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("Matrix3 set rotate3", m3c, Matrix3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	TEST("Matrix4 set rotate4", m4a, Matrix4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate5", m4b, Matrix4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate6", m4c, Matrix4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// vector transform
	v2a = Vector2(13.5f, -48.23f);
	v3a = Vector3(13.5f, -48.23f, 862);
	m3a = Matrix3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f);
	m3a.transpose();
	m3b = Matrix3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f);
	m3b.transpose();
	v3b = m3b * v3a;
	m3c.transpose();
	v3c = m3c * v3a;
	m3c.transpose();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	m4b.transpose();
	v4b = m4b * v4a;
	m4c.transpose();
	v4c = m4c * v4a;

	TEST("Vector3 matrix transform1", v3b, Vector3(844.07769f, -48.2299995422f, -175.38145f));
	TEST("Vector3 matrix transform2", v3c, Vector3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform3", v4b, Vector4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform4", v4c, Vector4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	m3a = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	m3b = Matrix3(9, 8, 7, 6, 5, 4, 3, 2, 1);
	m3d = m3a * m3b;
	m4d = m4c * m4b;

	TEST("Matrix3 multiply1", m3d, Matrix3(30,24,18,84,69,54,138,114,90));
	TEST("Matrix4 multiply2", m4d, Matrix4(-0.644214,-0.659385,-0.387557,0,-0.565019,0.751806,-0.339914,0,0.515501,0,-0.856889,0,0,0,0,1));

	// homogeneous point translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3b.transpose();
	m3c = m3c.rotation(2.2f);
	m3c.transpose();
	m3c[2] = Vector3(55, 44, 1);
	m3c.transpose();
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4b.transpose();
	m4c.transpose();
	m4c = Matrix4::rotation(2.2f, 3);
	m4c.transpose();
	m4c[3] = Vector4(55, 44, 99, 1);
	m4c.transpose();

	v3a = Vector3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation A", v3b, Vector3(68.5f, -4.23f, 1));
	TEST("Vector3 matrix translation B", v3c, Vector3(86.0490112305f, 83.2981109619f, 1));
	TEST("Vector4 matrix translation A", v4b, Vector4(68.5f, -4.23f, 45, 1));
	TEST("Vector4 matrix translation B", v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3b.transpose();
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4b.transpose();
	m4c = Matrix4::rotation(2.2f, 3);

	v3a = Vector3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation C", v3b, Vector3(13.5f, -48.23f, 0));
	TEST("Vector3 matrix translation D", v3c, Vector3(31.0490131378f, 39.2981109619f, 0));
	TEST("Vector4 matrix translation C", v4b, Vector4(13.5f, -48.23f, -54, 0));
	TEST("Vector4 matrix translation D", v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));

	return true;
}