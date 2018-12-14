#include "Entity.h"

Entity::Entity()
{
	rec.x = 100;
	rec.y = 100;
	rec.width = 32;
	rec.height = 32;

	pos.x = rec.x;
	pos.y = rec.y;
	duration = 1;
	elapsed = 0;

	startPos = pos;

	offset = 0;

	i = 0;
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

	pos.x = rec.x;
	pos.y = rec.y;
	duration = 1;
	elapsed = 0;

	startPos = pos;

	i = 0;
	tick = 0;
	multiplier = 50;

	tex = LoadTexture(filename.c_str());
}

void Entity::update(float _multiplier, vec2 center)
{
	tick += GetFrameTime() * 2;
	pos.x = _multiplier * (float)sin(tick + offset) + center.x;
	pos.y = _multiplier * (float)cos(tick + offset) + center.y;
}

void Entity::draw()
{
	DrawTexturePro(tex, Rectangle{ 0,0,rec.width,rec.height }, Rectangle{ pos.x,pos.y,rec.width,rec.height }, Vector2{ 16,16 }, 0, WHITE);
}

void Entity::move(vector<vec2>& waypoints)
{
	elapsed += GetFrameTime();
	//pos = lerp(startPos, waypoints[i], (elapsed/duration) > 1 ? 1 : (elapsed / duration));
	vec2 mid = startPos + (waypoints[i] - startPos) * 0.5f;
	pos = quadraticBezier(startPos, vec2{-mid.y,mid.x}, waypoints[i], (elapsed / duration) > 1 ? 1 : (elapsed / duration));
}