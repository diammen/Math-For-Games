#pragma once
#include <vector>
#include "Vector2.h"
#include "Mat3.h"
struct transform2d
{
public:
	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;

	void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);

	void translate(const vec2& offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;
	mat3 getWorldTRS() const;

	vec2 worldPosition() const;
	float worldRotation() const;
	vec2 worldScale() const;

	void setParent(transform2d *parent);
	transform2d *getParent() const;

	void addChild(transform2d * child);
	transform2d *getChildren() const;
	size_t getChildrenCount() const;

private:
	transform2d * parent;
	std::vector<transform2d *> children;
};