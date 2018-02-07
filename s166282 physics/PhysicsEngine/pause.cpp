#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include "pause.h"
#include "Application2D.h"
#include "size.h"


pause::pause()
{
}


pause::~pause()
{
}

bool pause::startup(Application2D* a_app)
{
	application = a_app;
	m_font = new aie::Font("./font/consolas.ttf", 32);
	return true;
}

void pause::shutdown()
{
	delete m_font;
}

void pause::update(float deltaTime)
{
	m_timer += deltaTime;

	aie::Input* input = aie::Input::getInstance();

	float mouseX = input->getMouseX();
	float mouseY = input->getMouseY();


	bool ButtonCheck(size button, int mouseX, int mouseY);
	bool MainMenuButton_stateCheck = false;
	bool GameButton_stateCheck = false;
	bool PauseButton_stateCheck = false;

	if (input->wasKeyReleased(aie::INPUT_KEY_BACKSPACE))
	{
		MainMenuButton_stateCheck = true;
	}

	if (input->wasKeyReleased(aie::INPUT_KEY_ENTER))
	{
		GameButton_stateCheck = true;
	}

	if (MainMenuButton_stateCheck == true)
	{
		//change to MainMenu scene
		system("cls");
		std::cout << "MainMenu Selected" << "\n";
		application->SwitchScene(Scene::MAINMENU);
		return;
	}

	if (GameButton_stateCheck == true)
	{
		//change to Game scene
		system("cls");
		std::cout << "Game selected" << "\n";
		application->ResumeScene(Scene::GAME);
		return;
	}


}

void pause::draw(aie::Renderer2D& a_renderer) {

	a_renderer.drawText(m_font, "Your Game is Paused", 510, 350);
}

//bool ButtonCheck(Size button, int mouseX, int mouseY)
//{
//	aie::Input* input = aie::Input::getInstance();
//
//	if (mouseY <= (button.y - button.height) + (button.height + button.height / 2) && mouseY >= (button.y - button.height) + (button.height - button.height / 2)
//		&&
//		mouseX <= (button.x - button.width) + (button.width + button.width / 2) && mouseX >= (button.x - button.width) + (button.width - button.width / 2))
//	{
//		if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT))
//		{
//			return true;
//		}
//	}
//}