#include "raylib.h"
#include "Snake.h"



SnakePart::SnakePart(int screenW, int screenH, float snakePartS, float snakeSp, Vector2 initialLoc, bool isH, std::shared_ptr<SnakePart> nextBP, Direction dir) {
	this->screenHeight = screenH;
	this->screenWidth = screenW;
	this->snakePartSize = snakePartS;
	this->initialLocation = this->currentLocation = initialLoc;
	this->isHead = isH;
	this->body = { initialLoc.x, initialLoc.y, (float)snakePartS, (float)snakePartS };
	this->nextBodyPart = nextBP;
	this->partMovement = dir;
	this->snakeSpeed = snakeSp;

}
void SnakePart::setDirection(Direction dir) {
	this->partMovement = dir;
}

std::shared_ptr<SnakePart> SnakePart::getNextBodyPart() {
	return nextBodyPart;
}

void SnakePart::draw() {
	DrawRectangleLines(currentLocation.x, currentLocation.y, snakePartSize, snakePartSize, isHead? RED:WHITE);
}

void SnakePart::update(){ 
	//head check for collision
	if (isHead) {
		if ((currentLocation.x <= 0 && partMovement == LEFT) || (currentLocation.x >= screenWidth && partMovement == RIGHT)
			|| (currentLocation.y <= 0 && partMovement == UP) || (currentLocation.y >= screenHeight && partMovement == DOWN)) partMovement = STOP;

		auto &cur = nextBodyPart;
		while (cur){

			if (cur->nextBodyPart && CheckCollisionRecs(cur->body, cur->nextBodyPart->body)){
				partMovement = STOP;
				break;
			}
		}
	}

	switch(partMovement) {
		case LEFT:
			currentLocation.x - (snakeSpeed * GetFrameTime());
			break;
		case RIGHT:
			currentLocation.x + (snakeSpeed * GetFrameTime());
			break;
		case UP:
			currentLocation.y - (snakeSpeed * GetFrameTime());
			break;
		case DOWN:
			currentLocation.y + (snakeSpeed * GetFrameTime());
			break;
		default:
			break;
	}
}