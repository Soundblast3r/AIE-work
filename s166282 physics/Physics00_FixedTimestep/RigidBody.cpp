#include "RigidBody.h"

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float rotation, float mass)
{
	m_position = position;
	m_rotation = rotation;
	m_mass = mass;
	m_shapeID = shapeID;
	m_velocity = { 0, 0 };
	m_acceleration = {0, 0};
}


RigidBody::~RigidBody()
{
}

void RigidBody::fixedUpdate(glm::vec2 gravity, float timeStep)
{ 
	applyForce(gravity * m_mass); 
	
	m_velocity += m_acceleration * timeStep;
	m_position += m_velocity * timeStep;

	m_acceleration = { 0, 0 };
}

void RigidBody::debug()
{
	//here
}

void RigidBody::applyForce(glm::vec2 force)
{
	this->m_acceleration += force / this->m_mass;
}

void RigidBody::applyForceToActor(RigidBody * actor2, glm::vec2 force)
{
	this->applyForce(force);
	actor2->applyForce(-force);
}
