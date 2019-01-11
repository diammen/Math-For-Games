#include "GameObject.h"

gameObject::gameObject()
{
	transform.setLocalPosition({ 100,100 });
	transform.setLocalRotation(0);
	transform.setLocalScale({ 1,1 });

	startPos = transform.localPos;

	duration = 1;
	elapsed = 0;
	target = 0;

	sprite = LoadTexture("ballshade_9.png");
}

gameObject::gameObject(const string &filename, const vec2 &newPos, const float &newRot, const vec2 &newScale, float newDuration)
{
	transform.setLocalPosition(newPos);
	transform.setLocalRotation(newRot);
	transform.setLocalScale(newScale);

	startPos = transform.localPos;

	duration = newDuration;
	elapsed = 0;
	target = 0;
	left = false;

	sprite = LoadTexture(filename.c_str());
}

void gameObject::update(float _multiplier, vec2 center)
{
	elapsed += GetFrameTime();
}

void gameObject::draw()
{
	DrawTexturePro(sprite, Rectangle{ 0,0,32,32 }, Rectangle{ transform.worldPosition().x, transform.worldPosition().y, 32 * transform.worldScale().x,32 * transform.worldScale().y }, { 16,16 }, transform.worldRotation(), WHITE);
}

void gameObject::move(vector<vec2>& waypoints)
{
	elapsed += GetFrameTime();
	//pos = lerp(startPos, waypoints[i], (elapsed/duration) > 1 ? 1 : (elapsed / duration));
	vec2 mid = startPos + (waypoints[target] - startPos) * 0.5f;
	vec2 leftNorm = { -mid.y, mid.x };
	vec2 rightNorm = { mid.y, mid.x };
	transform2d trsTarget;
	if (left) transform.localPos = quadraticBezier(startPos, leftNorm, waypoints[target], (elapsed / duration) > 1 ? 1 : (elapsed / duration));
	else transform.localPos = quadraticBezier(startPos, rightNorm, waypoints[target], (elapsed / duration) > 1 ? 1 : (elapsed / duration));
	trsTarget.localPos = waypoints[target];
	transform.rotate(1.0f);
	
}