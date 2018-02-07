#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Physics00_FixedTimestepApp.h"
#include "PhysicsScene.h"
#include "Sphere.h"
#include "RigidBody.h"
#include "PhysicsObject.h"

#include <iostream>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

Physics00_FixedTimestepApp::Physics00_FixedTimestepApp() {

}

Physics00_FixedTimestepApp::~Physics00_FixedTimestepApp() {

}

bool Physics00_FixedTimestepApp::startup() {
	
	// increase the 2d line count to maximize the number of objects we can draw 
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_physicsScene = new PhysicsScene(); 
	m_physicsScene->setGravity(glm::vec2(0, -9.8));
	m_physicsScene->setTimeStep(0.01f);

	Sphere* ball = new Sphere(glm::vec2(-40, 0), glm::vec2(10, 30), 10.0f, 1, glm::vec4(1, 0, 1, 1));
	Sphere* ball1 = new Sphere(glm::vec2(-5, 0), glm::vec2(2, 0), 8.0f, 4, glm::vec4(1, 0, 0, 1));
	Sphere* ball2 = new Sphere(glm::vec2(5, 0), glm::vec2(-2, 0), 10.0f, 4, glm::vec4(1, 1, 0, 1));

	m_physicsScene->addActor(ball);
	m_physicsScene->addActor(ball1);
	m_physicsScene->addActor(ball2);

	ball1->applyForceToActor(ball2, glm::vec2(500, 0));
	ball2->applyForceToActor(ball1, glm::vec2(-500, 0));

	return true;
}

void Physics00_FixedTimestepApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Physics00_FixedTimestepApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();

	m_physicsScene->update(deltaTime); 
	m_physicsScene->updateGizmos();
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
	
	static const glm::vec4 colours[] = {
		glm::vec4(1, 0, 0, 1),glm::vec4(0, 1, 0, 1),
		glm::vec4(0, 0, 1, 1), glm::vec4(0.8f, 0, 0.5f, 1),
		glm::vec4(0, 1, 1, 1)
	};

	static const int rows = 5;
	static const int columns = 10;
	static const int hSpace = 1;
	static const int vSpace = 1;

	static const glm::vec2 scrExtents(100, 50);
	static const glm::vec2 boxExtents(7, 3);
	static const glm::vec2 startPos(
		-(columns >> 1) * ((boxExtents.x * 2) + vSpace) + boxExtents.x + (vSpace / 2.0f),
		scrExtents.y - ((boxExtents.y * 2) + hSpace));

	glm::vec2 pos;
	for (int y = 0; y < rows; y++) {
		pos = glm::vec2(startPos.x, startPos.y - (y * ((boxExtents.y * 2) + hSpace)));
		for (int x = 0; x < columns; x++) {
			aie::Gizmos::add2DAABBFilled(pos, boxExtents, colours[y]);
			pos.x += (boxExtents.x * 2) + vSpace;
		}
	}

	//player
	aie::Gizmos::add2DAABBFilled(glm::vec2(0, -40), glm::vec2(12, 2), glm::vec4(1, 0, 1, 1));

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		//move left
		std::cout << "player moves left" << std::endl;
		pos.x += 10;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		//move Right
		std::cout << "player moves Right" << std::endl;
		pos.x -= 10;
	}
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		std::cout << "player moves Up";
		std::cout << " (Not Implemented)" << std::endl;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		std::cout << "player moves Down";
		std::cout << " (Not Implemented)" << std::endl;
	}
}

void Physics00_FixedTimestepApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	static float aspectRatio = 16 / 9.f; 
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	//m_2dRenderer->drawText(m_font, "fixed Time Step", 500, 300);

	// done drawing sprites
	m_2dRenderer->end();
}