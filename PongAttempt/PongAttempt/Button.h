#pragma once
#include <string>
#include <functional>
#include <raylib.h>
#include "UIBehavior.h"
#ifndef BUTTON_H
#define BUTTON_H

enum ButtonState {
	PRESSED,
	RELEASED,
	NONE
};

class Button: public UIBehavior {
	private:
		std::string btnText;
		std::function<void(void)> callback;
		Vector2 btnLoc;
		int btnHeight;
		int btnWidth;
		Color btnColor;
		Rectangle button;
		Font btnFont;
		void drawTextRect();
public:
	Button(Vector2 btnL, int btnH, int btnW, Color btnC, std::string text, std::function<void(void)> onClick);
	void draw() override;
	void update() override;
};
#endif 