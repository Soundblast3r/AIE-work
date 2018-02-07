#include "Sphere.h"
#include "RigidBody.h"

Sphere::Sphere(
	glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 colour) :
	RigidBody(
		SPHERE, position, velocity, 0, mass)
		{
			m_radius = radius;
			m_colour = colour;
		}

Sphere::~Sphere()
{

}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(getPosition(), m_radius, 1000, m_colour);
}

bool Sphere::checkCollision(PhysicsObject * pOther)
{
	return false;
}
