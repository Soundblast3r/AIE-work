#pragma once
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

enum ShapeType
{
	PLANE = 0,
	SPHERE,
	BOX
};

class PhysicsObject{
	protected: PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {}

public:
	PhysicsObject();
	~PhysicsObject();
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

protected:
	ShapeType m_shapeID;
};