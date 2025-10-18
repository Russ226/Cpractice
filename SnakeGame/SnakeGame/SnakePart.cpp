#include "raylib.h"
#include "Snake.h"



SnakePart::SnakePart(int screenW, int screenH, int snakePartS, float snakeSp, Vector2 initialLoc, bool isH, std::shared_ptr<SnakePart> nextBP, std::shared_ptr<SnakePart> prevBP, Direction dir) {
	this->screenHeight = screenH;
	this->screenWidth = screenW;
	this->snakePartSize = snakePartS;
	this->initialLocation = this->currentLocation = initialLoc;
	this->isHead = isH;
	this->body = { initialLoc.x, initialLoc.y, (float)snakePartS, (float)snakePartS };
	this->nextBodyPart = nextBP;
	this->prevBodyPart = prevBP;
	this->partMovement = dir;
	this->changeMovement = dir;
	this->snakeSpeed = snakeSp;

	this->changeDirectionAt = dir != STOP ? initialLoc : Vector2{-999, -999};

}
void SnakePart::setDirection(Direction dir, Vector2 cda) {
	this->changeDirectionAt = cda;
	this->changeMovement = dir;
}

std::shared_ptr<SnakePart> SnakePart::getNextBodyPart() {
	return nextBodyPart;
}

std::shared_ptr<SnakePart> SnakePart::getPrevBodyPart() {
	return prevBodyPart;
}

void SnakePart::draw() {
	DrawRectangleLines(currentLocation.x, currentLocation.y, snakePartSize, snakePartSize, isHead? RED:WHITE);
}


void SnakePart::update(){ 
	//head check for collision
	if (isHead) {
		// use curren loc - the snake part size 
		if ((currentLocation.x <= 0 && partMovement == LEFT) || (currentLocation.x >= screenWidth && partMovement == RIGHT)
			|| (currentLocation.y <= 0 && partMovement == UP) || (currentLocation.y >= screenHeight && partMovement == DOWN)) partMovement = STOP;

		auto cur = nextBodyPart;
		//to do: this doesn't work
		while (cur){

			if (cur->getNextBodyPart() && CheckCollisionRecs(cur->getRectangle(), cur->getNextBodyPart()->getRectangle())) {
				partMovement = STOP;
				break;
			}

			if (cur->getPrevBodyPart() && CheckCollisionRecs(cur->getRectangle(), cur->getPrevBodyPart()->getRectangle())) {
				partMovement = STOP;
				break;
			}

			cur = cur->getNextBodyPart();
		}
	}
	if (!isHead && changeMovement != partMovement && currentLocation.x == changeDirectionAt.x && currentLocation.y == changeDirectionAt.y) {
		partMovement = changeMovement;
	}
	
	if (isHead) {
		partMovement = changeMovement;
	}

	switch(partMovement) {
		case LEFT:
			currentLocation.x -= (snakeSpeed * GetFrameTime());
			break;
		case RIGHT:
			currentLocation.x += (snakeSpeed * GetFrameTime());
			break;
		case UP:
			currentLocation.y -= (snakeSpeed * GetFrameTime());
			break;
		case DOWN:
			currentLocation.y += (snakeSpeed * GetFrameTime());
			break;
		default:
			break;
	}

}
void SnakePart::setCurrentLocation(Vector2 l) {
	//TODO: add screen boundaries check
	currentLocation = l;
}

Vector2 SnakePart::getLocation() {
	return currentLocation;
}

Rectangle SnakePart::getRectangle() {
	return body;
}

bool SnakePart::addNextBodyPart(std::shared_ptr<SnakePart> sb) {
	if (!nextBodyPart && sb) {
		nextBodyPart = sb;
		return true;
	}

	return false;
}

bool SnakePart::addPrevBodyPart(std::shared_ptr<SnakePart> sb) {
	if (!prevBodyPart && sb) {
		prevBodyPart = sb;
		return true;
	}

	return false;
}