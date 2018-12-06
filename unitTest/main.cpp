#include <iostream>

#include "utils.h"

int main()
{
	int yay = min(2, 3);
	int nay = max(2, 3);
	int way = clamp(0, 1, 3);
	int may = clamp(4, 1, 3);
	int lay = abs(10);
	int fay = pow(3, 2);
	bool tay = isPowerOfTwo(fay);
	int bay = nextPowerOfTwo(fay);
	return 0;
}