#include "Transform2D.h"

transform2d::transform2d()
{
	parent = nullptr;
}

void transform2d::setLocalPosition(const vec2 &newPos)
{
	localPos = newPos;
}
void transform2d::setLocalRotation(const float newRot)
{
	localRot = newRot;
}
void transform2d::setLocalScale(const vec2 &newScale)
{
	localScale = newScale;
}

void transform2d::translate(const vec2& offset)
{
	localPos += offset;
}
void transform2d::rotate(const float angle)
{
	localRot += angle;
}

void transform2d::lookAt(const transform2d &target)
{
	vec2 targetVec = target.localPos - localPos;
	float angle = atan2(targetVec.y, targetVec.x);
	setLocalRotation(angle);
}

vec2 transform2d::forward() const
{
	return vec2(cos(localRot), sin(localRot)).normalize();
}

void transform2d::setForward(const vec2 &newFwd)
{
	setLocalRotation(atan2(newFwd.y, newFwd.x));
}

mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(localRot) * mat3::scale(localScale.x, localScale.y);
}

vec2 transform2d::worldPosition() const
{
	if (parent == nullptr)
		return localPos;
	return vec2(parent->localPos.x + localPos.x, parent->localPos.y + localPos.y);
}
float transform2d::worldRotation() const
{
	if (parent == nullptr)
		return localRot;
	return parent->localRot + localRot;
}
vec2 transform2d::worldScale() const
{
	if (parent == nullptr)
		return localScale;
	return vec2(parent->localScale.x * localScale.x, parent->localScale.y * localScale.y);
}

void transform2d::setParent(transform2d *_parent)
{
	parent = _parent;
}

transform2d *transform2d::getParent() const
{
	return parent;
}

void transform2d::addChild(transform2d * child)
{
	children.push_back(child);
	child->setParent(this);
}

transform2d * transform2d::getChildren() const
{
	if (children.size() > 1)
		return children[0];
	return nullptr;
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
}