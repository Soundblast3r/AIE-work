#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

class Physics00_FixedTimestepApp : public aie::Application {
public:

	Physics00_FixedTimestepApp();
	virtual ~Physics00_FixedTimestepApp();


	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	PhysicsScene*		m_physicsScene;

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

};