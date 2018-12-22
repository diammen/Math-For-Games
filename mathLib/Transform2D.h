#pragma once
#include <vector>
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

	vec2 worldPosition() const;
	float worldRotation() const;
	vec2 worldScale() const;

	void setParent(transform2d *parent);
	transform2d *getParent() const;

	void addChild(transform2d * child);
	transform2d *getChildren() const;
	size_t getChildrenCount() const;

private:
	mat3 trsMatrix;
	// position
	// rotation
	// scale
	transform2d * parent;
	std::vector<transform2d *> children;
};