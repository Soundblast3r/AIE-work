#pragma once

#include "Application.h"
#include "Renderer2D.h"

class aieProject2D2App : public aie::Application {
public:

	aieProject2D2App();
	virtual ~aieProject2D2App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};