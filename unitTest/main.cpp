#include <iostream>

#include "utils.h"

int main()
{
	int yay = min(2, 3);
	int nay = max(2, 3);
	int way = clamp(0, 1, 3);
	int may = clamp(4, 1, 3);
	int lay = abs(10);
	int fay = pow(2, 10);
	bool tay = isPowerOfTwo(fay);
	int bay = nextPowerOfTwo(fay);
	int hay = 0;
	float time = 0;
	while (hay > -15)
	{
		hay = moveTowards(hay, -10, time);
		time += 0.1f;
	}
	return 0;
}