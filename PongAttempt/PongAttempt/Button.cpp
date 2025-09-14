#include "Button.h"

Button::Button(Vector2 btnL, int btnH, int btnW, Color btnC, std::string text, std::function<void(void)> onClick)
{
	this->btnLoc = btnL;
	this->btnHeight = btnH;
	this->btnWidth = btnW;
	this->btnText = text;
	this->callback = onClick;
	this->btnColor = btnC;
	this->button = { btnL.x, btnL.y, (float)btnH, (float)btnW };
	this->btnFont = LoadFont("resources/pixantiqua.fnt");

}

void Button::draw() {
}

void Button::update() {

	auto mousePoint = GetMousePosition();
	ButtonState btnState = NONE;

	if (CheckCollisionPointRec(mousePoint, button))
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = PRESSED;

		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnState = RELEASED;
	}

	if (btnState == RELEASED) {
		btnState = NONE;
		callback();
	}

}
//https://www.raylib.com/examples/text/loader.html?name=text_rectangle_bounds
void Button::drawTextRect() {
	int length = TextLength(btnText.c_str());

	float textOffsetY = 0;          
	float textOffsetX = 0.0f;       

	float scaleFactor = 10 / (float)btnFont.baseSize;
	enum { MEASURE_STATE = 0, DRAW_STATE = 1 };

	int startLine = -1;        
	int endLine = -1;          
	int lastk = -1;


}