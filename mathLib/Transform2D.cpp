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
	vec2 up = { 1,0 };
	float angle = acos(up.dot(target.localPos) / (up.magnitude() * target.localPos.magnitude()));
	localRot = angle;
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

mat3 transform2d::getWorldTRS() const
{
	if (parent == nullptr)
		return getTRSMatrix();

	return parent->getWorldTRS() * getTRSMatrix();
}

vec2 transform2d::worldPosition() const
{
	if (parent == nullptr)
		return {getTRSMatrix().m3, getTRSMatrix().m6};

	mat3 worldTRS = parent->getWorldTRS() * getTRSMatrix();

	return { worldTRS.m3, worldTRS.m6 };
}

// in radians, convert to degrees when passing values into raylib functions
float transform2d::worldRotation() const
{
	if (parent == nullptr)
		return atan2(getTRSMatrix().m4, getTRSMatrix().m1);

	mat3 worldTRS = parent->getWorldTRS() * getTRSMatrix();
	float angle = atan2(worldTRS.m4, worldTRS.m1);

	return angle;
}

vec2 transform2d::worldScale() const
{
	float magX, magY;

	if (parent == nullptr)
	{
		magX = sqrt(getTRSMatrix().m1 * getTRSMatrix().m1 + getTRSMatrix().m4 * getTRSMatrix().m4);
		magY = sqrt(getTRSMatrix().m2 * getTRSMatrix().m2 + getTRSMatrix().m5 * getTRSMatrix().m5);
		return { magX, magY };
	}

	mat3 worldTRS = parent->getWorldTRS() * getTRSMatrix();

	magX = sqrt(worldTRS.m1 * worldTRS.m1 + worldTRS.m4 * worldTRS.m4);
	magY = sqrt(worldTRS.m2 * worldTRS.m2 + worldTRS.m5 * worldTRS.m5);

	return { magX, magY };
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