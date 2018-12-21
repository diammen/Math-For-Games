#pragma once
#include "Vector2.h"
#include "Mat3.h"
struct transform2d
{
	vec2 localPosition() const;
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);

	void translate(const vec2& offset);
	void rotate(const float angle);

private:
	mat3 trsMatrix;
	// position
	// rotation
	// scale
};