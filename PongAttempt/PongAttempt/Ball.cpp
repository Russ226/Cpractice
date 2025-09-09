#include "Ball.h"

Ball::Ball(int sW, int sH)
{
	this->screenWidth = sW;
	this->screenHeight = sH;
}

void Ball::draw()
{
	DrawCircle(curPos.x, curPos.y, radius, DARKBLUE);
}

void Ball::update(Rectangle rec)
{
	curPos.x += (velocity.x * GetFrameTime());
	curPos.y += (velocity.y * GetFrameTime());
	if (CheckCollisionCircleRec(curPos, radius, rec)) {
		velocity.x *= -1;
	}
	if ((curPos.x >= screenWidth) || (curPos.x <= 0)) velocity.x *= -1;
	if ((curPos.y >= screenHeight) || (curPos.y <= 0)) velocity.y *= -1;
}
