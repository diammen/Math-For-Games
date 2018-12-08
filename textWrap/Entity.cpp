#include "Entity.h"

Entity::Entity()
{
	rec.x = 200;
	rec.y = 200;
	rec.width = 32;
	rec.height = 32;
	offset = 0;

	tick = 0;
	multiplier = 100;

	tex = LoadTexture("ballshade_1.png");
}

Entity::Entity(const string &filename, const Vector2 &newPos)
{
	rec.x = newPos.x;
	rec.y = newPos.y;
	rec.width = 32;
	rec.height = 32;

	tick = 0;
	multiplier = 50;

	tex = LoadTexture(filename.c_str());
}

void Entity::update(float _multiplier)
{
	tick += GetFrameTime() * 2;
	rec.x = _multiplier * (float)sin(tick + offset) + GetScreenWidth() / 2;
	rec.y = _multiplier * (float)cos(tick + offset) + GetScreenHeight() / 2;
}

void Entity::draw()
{
	DrawTexturePro(tex, Rectangle{ 0,0,rec.width,rec.height }, rec, Vector2{ 16,16 }, 0, WHITE);
}