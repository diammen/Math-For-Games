#pragma once
#include <iostream>

// testName, expression
#define boolAssert(x, y) \
	{ if (y) std::cout << "[PASS] " << x << std::endl; \
		else std::cout << "[FAIL] " << x << std::endl; \
	}
// testName, expected, actual
#define equalAssert(x, y, z) \
	{ if (z == y)  std::cout << "[PASS] " << x << std::endl; \
		else std::cout << "[FAIL] " << x << std::endl; \
	}
// testName, expected, actual, tolerance
#define nearAssert(x, y, z, w) \
	{ if (y - z <= w) std::cout << "[PASS] " << x << std::endl; \
		else std::cout << "[FAIL] " << x << std::endl; \
	}