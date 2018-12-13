#include <iostream>
#include <cassert>
#include "utils.h"
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
	float time = 0;
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
	return 0;
}