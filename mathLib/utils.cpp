#include "utils.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int value, int lower, int upper)
{
	return min(upper, max(value, lower));
}

int abs(int val)
{
	return val < 0 ? -val : val;
}

int pow(int base, int power)
{
	if (power == 0)
		return 0;

	int temp = base;
	for (int i = 1; i < power; ++i)
	{
		base *= temp;
	}
	return base;
}

bool isPowerOfTwo(int val)
{
	return (val & (val-1)) == 0;
}

int nextPowerOfTwo(int val)
{
	if (isPowerOfTwo(val))
	{
		val++;
		while (!isPowerOfTwo(val))
		{
			val++;
		}
	}
	return val;
}

float moveTowards(float current, float target, float maxDelta)
{
	if (abs((int)(target - current)) <= maxDelta)
	{
		return target;
	}
	return (target - current) * maxDelta + current;
}

bool calculateDifference(float a, float b, float maxRelDiff)
{
	float diff = fabs(a - b);
	a = fabs(a);
	b = fabs(b);

	float largest = (b < a) ? b : a;

	if (diff <= largest * maxRelDiff)
		return true;
	return false;
}