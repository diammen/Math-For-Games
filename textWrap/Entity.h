#pragma once
#include "raylib.h"
#include "mathLib.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;
class Entity
{
public:
	Rectangle rec;
	vec2 pos;
	vec2 startPos;
	Texture2D tex;
	float offset;
	float tick;
	float duration;
	float elapsed;
	int multiplier;
	int i;
	bool left;

	void update(float _multiplier, vec2 center);
	void draw();
	void move(vector<vec2>& waypoints);

	Entity();
	Entity(const string &filename, const Vector2 &newPos, float newDuration);
};