#pragma once
#include <cmath>

// Returns the smaller of the two values
int min(int a, int b);

// Returns the larger of the two values
int max(int a, int b);

// Returns a value no smaller than lower and no larger than upper
int clamp(int value, int lower, int upper);

constexpr double PI2 = 3.141592653589793238;

constexpr double DEG_TO_RAD2 = PI2 / 180;

constexpr double RAD_TO_DEG2 = 180 / PI2;

// Returns the absolute value of val
int abs2(int val);

// Returns base to the power of exp
int pow(int base, int power);

// Returns true if the value is a power of two, otherwise returns false
bool isPowerOfTwo(int val);

// Returns the next power of two after the given value
int nextPowerOfTwo(int val);

// Moves the current value towards the target value
float moveTowards(float current, float target, float maxDelta);

bool calculateDifference(float a, float b, float maxRelDiff);

// Linearly interpolate between two values
template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}

template<typename T>
T quadraticBezier(const T& a, const T& b, const T& c, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	return lerp(x, y, t);
}

template <typename T>
T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);
	T z = lerp(c, d, t);
	return quadraticBezier(x, y, z, t);
}