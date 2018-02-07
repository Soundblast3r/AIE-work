#pragma once

#include "Application.h"
#include "Renderer2D.h"

class PhysicsEngineApp : public aie::Application {
public:

	PhysicsEngineApp();
	~PhysicsEngineApp();

	bool startup();
	void shutdown();

	void update(float deltaTime);
	void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};