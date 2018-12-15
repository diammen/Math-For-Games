#pragma once
#include <cmath>
#include <string>
#include "time.h"
#include "utils.h"
using std::string;

class gen
{
private:
	uint64_t currentSeed;
	int origSeed;
	int seedLength;

	uint64_t w = 0;
public:

	// returns a random value between min and max
	template<typename T>
	T rand(T min, T max)
	{
		//size_t len = seedLength / 2;
		nextSeed();
		return currentSeed % (max - min) + min;
		//string seed = std::to_string(squaredSeed);
		//currentSeed = std::stoi(seed.substr(len,seedLength));
		//return fmod(currentSeed,(max - min + 1) + min);
	}

	// returns a random value between min and max
	//  - the value may contain decimal components
	template<typename T>
	T randDecimal(T min, T max)
	{
		nextSeed();

		T temp = fmod(currentSeed, (max * 100 - min * 100) + min * 100);

		temp /= 100;

		return temp;
	}

	// seed the random number generator
	void seedRand(int seedValue)
	{
		currentSeed = origSeed = seedValue;
		//seedLength = std::to_string(currentSeed).substr(0, 6).length();
	}

	void nextSeed()
	{
		const uint64_t s = 0xb5ad4eceda1ce2a9;
		currentSeed *= currentSeed;
		w += s;
		currentSeed += w;
		currentSeed = (currentSeed >> 32) | (currentSeed << 32);
	}

	// returns the seed used for the random number generator
	int getRandSeed()
	{
		return currentSeed;
	}
};