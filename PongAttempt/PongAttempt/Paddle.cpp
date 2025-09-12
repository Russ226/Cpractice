#include "Paddle.h"

Paddle::Paddle(int screenW, int screenH, int rectangleW, int rectangleH, Vector2 location, directionalKeys dK)
{
	this->screenWidth = screenW;
	this->screenHeight = screenH;
	this->rectangleHeight = rectangleH;
	this->rectangleWidth = rectangleW;
	this->startingLocation = location;
	this->dirKeys = dK;
	this->rec = {location.x, location.y, (float)rectangleW, (float)rectangleH};

	rectangleColor = Color('100', '23', '0', '1.0');
	moveSpeed = 200.0f;
	//startingLocation = { 0, 0 };

}

void Paddle::draw()
{
	DrawRectangleRec(this->rec, ORANGE);
}

void Paddle::update() {
	if(IsKeyDown(dirKeys[PaddleMovement::DOWN]) && ((this->rec.y + this->rectangleHeight) + (this->moveSpeed * GetFrameTime()) <= this->screenHeight)){
		this->rec.y += (this->moveSpeed * GetFrameTime());
	}

	if(IsKeyDown(dirKeys[PaddleMovement::UP]) && (this->rec.y * (this->moveSpeed * GetFrameTime()) >= 0)){
		this->rec.y -= (this->moveSpeed * GetFrameTime());
	}
}

Rectangle Paddle::getRectangle() {
	return this->rec;
}
