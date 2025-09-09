#include "Ball.h"

Ball::Ball(int sW, int sH)
{
	this->screenWidth = sW;
	this->screenHeight = sH;
}

void Ball::draw()
{
	DrawCircle(curPos.x, curPos.y, 7, DARKBLUE);
}

void Ball::update()
{
	curPos.x += (velocity.x * GetFrameTime());
	curPos.y += (velocity.y * GetFrameTime());

	if ((curPos.x >= screenWidth) || (curPos.x <= 0)) velocity.x *= -1;
	if ((curPos.y >= screenHeight) || (curPos.y <= 0)) velocity.y *= -1;
}
