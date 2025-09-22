#include "Button.h"

Button::Button(Vector2 btnL, int btnH, int btnW, Color btnC, Color btnTC, std::string text, std::function<void(void)> onClick)
{
	this->btnLoc = btnL;
	this->btnHeight = btnH;
	this->btnWidth = btnW;
	this->btnText = text;
	this->callback = onClick;
	this->btnColor = btnC;
	this->btnTextColor = btnTC;
	this->button = { btnL.x, btnL.y, (float)btnH, (float)btnW };
	this->btnFont = GetFontDefault();
	this->button = { btnLoc.x, btnLoc.y, (float)btnWidth, (float)btnHeight };

}

void Button::draw() {
	DrawRectangleRec(this->button, btnColor);
	drawTextRect();
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
// based the code of a a raylib example 
//https://www.raylib.com/examples/text/loader.html?name=text_rectangle_bounds
void Button::drawTextRect() {
	int selectStart = 0;
	int selectLength = 0;

	int length = TextLength(btnText.c_str());
	float fontSize = (btnHeight+btnWidth)/length;
	float spacing = fontSize/2.0;
	float intialTextOffsetY = 20.0, textOffsetY = intialTextOffsetY;
	float intialTextOffsetX = 10.0f, textOffsetX = intialTextOffsetX;

	float scaleFactor = fontSize / (float)btnFont.baseSize;
	enum { MEASURE_STATE = 0, DRAW_STATE = 1 };
	int state = MEASURE_STATE;

	int startLine = -1;        
	int endLine = -1;          
	int lastk = -1;
	for (int i = 0, k = 0; i < length; i++, k++)
	{
		int codepointByteCount = 0;
		int codepoint = GetCodepoint(&btnText.c_str()[i], &codepointByteCount);
		int index = GetGlyphIndex(btnFont, codepoint);

		if (codepoint == 0x3f) codepointByteCount = 1;
		i += (codepointByteCount - 1);

		float glyphWidth = 0;
		if (codepoint != '\n')
		{
			glyphWidth = (btnFont.glyphs[index].advanceX == 0) ? btnFont.recs[index].width * scaleFactor : btnFont.glyphs[index].advanceX * scaleFactor;

			if (i + 1 < length) glyphWidth = glyphWidth + spacing;
		}

		if (state == MEASURE_STATE)
		{
			if ((codepoint == ' ') || (codepoint == '\t') || (codepoint == '\n')) endLine = i;


			if ((textOffsetX + glyphWidth) > button.width)
			{
				endLine = (endLine < 1) ? i : endLine;
				if (i == endLine) endLine -= codepointByteCount;
				if ((startLine + codepointByteCount) == endLine) endLine = (i - codepointByteCount);

				state = !state;
			}
			else if ((i + 1) == length)
			{
				endLine = i;
				state = !state;
			}
			else if (codepoint == '\n') state = !state;

			if (state == DRAW_STATE)
			{
				textOffsetX = intialTextOffsetX;
				i = startLine;
				glyphWidth = 0;

				int tmp = lastk;
				lastk = k - 1;
				k = tmp;
			}
		}
		else {
			if (codepoint != '\n') {
				if ((textOffsetY + btnFont.baseSize * scaleFactor) > button.height) break;
				
				bool isGlyphSelected = false;
				if ((0 >= 0) && (k >= selectStart) && (k < (selectStart + selectLength)))
				{
					DrawRectangleRec(Rectangle(button.x + textOffsetX - 1, button.y + textOffsetY, glyphWidth, (float)btnFont.baseSize* scaleFactor), btnTextColor);
					isGlyphSelected = true;
				}

				if ((codepoint != ' ') && (codepoint != '\t'))
				{
					 DrawTextCodepoint(btnFont, codepoint, Vector2(button.x + textOffsetX, button.y + textOffsetY), fontSize, btnTextColor);
				}

			}

		if ((textOffsetX != 0) || (codepoint != ' ')) textOffsetX += glyphWidth;
		if(i == endLine)
		{
			textOffsetY += ((btnFont.baseSize + btnFont.baseSize / 2) * scaleFactor) + 20;
			textOffsetX = intialTextOffsetX;
			startLine = endLine;
			endLine = -1;
			glyphWidth = 0;
			selectStart += lastk - k;
			k = lastk;

			state = !state;
		}
		}
	}

}