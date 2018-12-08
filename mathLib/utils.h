#pragma once
#include "Vector2.h"

// Returns the smaller of the two values
int min(int a, int b);

// Returns the larger of the two values
int max(int a, int b);

// Returns a value no smaller than lower and no larger than upper
int clamp(int value, int lower, int upper);

//const double PI = 3.141592653589793238;
//
//const double DEG_TO_RAD = PI / 180;
//
//const double RAD_TO_DEG = 180 / PI;

// Returns the absolute value of val
int abs(int val);

// Returns base to the power of exp
int pow(int base, int power);

// Returns true if the value is a power of two, otherwise returns false
bool isPowerOfTwo(int val);

// Returns the next power of two after the given value
int nextPowerOfTwo(int val);

// Moves the current value towards the target value
float moveTowards(float current, float target, float maxDelta);