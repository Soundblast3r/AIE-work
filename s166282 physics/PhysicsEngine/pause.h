#pragma once
#include "Application2D.h"
#include "Renderer2D.h"


class pause
{
public:
	pause();
	~pause();

	bool startup(Application2D* a_app);
	void shutdown();

	void update(float deltaTime);
	void draw(aie::Renderer2D& a_renderer);



protected:
	aie::Font*			m_font;
	float m_timer;
	aie::Texture*		m_texture;
	Application2D*		application;

};