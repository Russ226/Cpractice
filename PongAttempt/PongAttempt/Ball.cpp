#include "Ball.h"
#include "Paddle.h"

Ball::Ball(int sW, int sH, std::shared_ptr<Paddle> p1, std::shared_ptr<Paddle> p2)
{
	this->screenWidth = sW;
	this->screenHeight = sH;
	this->player1 = p1;
	this->player2 = p2;
}

void Ball::draw()
{
	DrawCircle(curPos.x, curPos.y, radius, DARKBLUE);
}

void Ball::update()
{
	curPos.x += (velocity.x * GetFrameTime());
	curPos.y += (velocity.y * GetFrameTime());
	if (CheckCollisionCircleRec(curPos, radius, player1->getRectangle()) || CheckCollisionCircleRec(curPos, radius, player2->getRectangle())) {
		velocity.x *= -1.2;
		velocity.y *= -1.2;
	}
	else if ((curPos.x - 1 > screenWidth) || (curPos.x + 1 < 0)) curPos = intialPos;
	else if ((curPos.y >= screenHeight) || (curPos.y <= 0)) velocity.y *= -1;
}

Vector2 Ball::getCurrentPos()
{
	return this->curPos;
}

Ball::~Ball()
{
	player1.reset();
	player2.reset();
}
