#include "Paddle.h"

Paddle::Paddle(int screenW, int screenH, int rectangleW, int rectangleH, Vector2 location)
{
	this->screenWidth = screenW;
	this->screenHeight = screenH;
	this->rectangleHeight = rectangleH;
	this->rectangleWidth = rectangleW;
	this->startingLocation = location;

	this->rec = {location.x, location.y, (float)rectangleW, (float)rectangleH};

}

void Paddle::draw(PaddleMovement dir)
{
	switch (dir) {
		case PaddleMovement::DOWN:
			if ((this->rec.y + this->rectangleHeight) + (this->moveSpeed * GetFrameTime()) <= this->screenHeight) {
				this->rec.y += (this->moveSpeed * GetFrameTime());
				DrawRectangleRec(this->rec, this->rectangleColor);
			}
			break;
		case PaddleMovement::UP:
			if (this->rec.y * (this->moveSpeed * GetFrameTime()) >= 0) {
				this->rec.y -= (this->moveSpeed * GetFrameTime());
				DrawRectangleRec(this->rec, this->rectangleColor);
			}
				
			break;
		default:
			DrawRectangleRec(this->rec, this->rectangleColor);
			break;
	};
}
