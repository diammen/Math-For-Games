#pragma once
#include "mathlib.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class gameObject
{
public:
	transform2d transform;
	Texture2D sprite;
	vec2 startPos;
	int target;
	float duration;
	float elapsed;
	bool left;

	gameObject();
	gameObject(const string &filename, const vec2 &newPos, const float &newRot, const vec2 &newScale, float newDuration);

	void update(float _multiplier, vec2 center);
	void draw();
	void move(vector<vec2>& waypoints);
};