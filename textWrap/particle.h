#pragma once
#include "raylib.h"
#include "mathLib.h"

struct particle
{
	Texture2D texture;
	Color color;
	vec2 position;
	Vector2 direction;
	float scale;
	float rotation;

	void update();
	void draw();
};