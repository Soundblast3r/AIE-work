#include "PhysicsScene.h"
#include "RigidBody.h"
#include <iostream>
#include <list>
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0, 0))
{
}

void PhysicsScene::update(float dt) 
{ // update physics at a fixed time step 
	static std::list<PhysicsObject*> dirty;

	static float accumulatedTime = 0.0f; 
	accumulatedTime += dt; 
	while (accumulatedTime >= m_timeStep) 
	{ 
		for (auto pActor : m_actors) 
		{ 
			pActor->fixedUpdate(m_gravity, m_timeStep); 
		} 
		accumulatedTime -= m_timeStep; 

		// check for collisions (ideally you'd want to have some sort of 
		// scene management in place) 
		for (auto pActor : m_actors) 
		{ 
			for (auto pOther : m_actors) 
			{ 
				if (pActor == pOther) 
					continue; 
				
				if (std::find(dirty.begin(), dirty.end(), pActor) != dirty.end() && 
					std::find(dirty.begin(), dirty.end(), pOther) != dirty.end()) 
					continue; 
				
				RigidBody* pRigid = dynamic_cast<RigidBody*>(pActor); 
				if (pRigid->checkCollision(pOther) == true) { 
					pRigid->applyForceToActor( 
						dynamic_cast<RigidBody*>(pOther), 
					pRigid->getVelocity() * pRigid->getMass()); 
					dirty.push_back(pRigid); 
					dirty.push_back(pOther); 
				} 
			} 
		} 
		dirty.clear();
	} 
} 

void PhysicsScene::updateGizmos() 
{ 
	for (auto pActor : m_actors) 
	{
		pActor->makeGizmo(); 
	}
}

PhysicsScene::~PhysicsScene()
{
	for (auto pActor : m_actors) 
	{ 
		delete pActor; 
	}
}

void PhysicsScene::addActor(PhysicsObject * actor)
{
	m_actors.push_back(actor);
}

void PhysicsScene::removeActor(PhysicsObject * actor)
{
	//here
}

void PhysicsScene::debugScene() 
{ 
	int count = 0; 
	for (auto pActor : m_actors) 
	{ 
		std::cout << count << " : "; pActor->debug(); count++; 
	} 
}