#pragma once
#include "raylib.h"
#include "utils.h"
#include <iostream>
using std::string;
class Entity
{
public:
	Rectangle rec;
	Texture2D tex;
	float offset;
	float tick;
	int multiplier;

	void update(float _multiplier);
	void draw();

	Entity();
	Entity(const string &filename, const Vector2 &newPos);
};