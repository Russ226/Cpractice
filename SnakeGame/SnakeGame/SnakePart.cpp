#include <iostream>
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
	this->snakeSpeed = snakeSp;
	this->turnDelay = snakePartSize + 8;


}
void SnakePart::setDirection(Direction dir) {
	this->partMovement = dir;
	
}

std::shared_ptr<SnakePart> SnakePart::getNextBodyPart() {
	return nextBodyPart;
}

std::shared_ptr<SnakePart> SnakePart::getPrevBodyPart() {
	return prevBodyPart;
}

Direction SnakePart::getDirection() {
	return partMovement;
}

void SnakePart::draw() {
	DrawRectangleLines(currentLocation.x, currentLocation.y, snakePartSize, snakePartSize, isHead? RED:WHITE);
	//DrawPixelV(currentLocation, PINK);
}


void SnakePart::update(){ 
	//head check for collision
		
	if ((currentLocation.x - snakePartSize <= 0 && partMovement == LEFT) || (currentLocation.x + snakePartSize >= screenWidth && partMovement == RIGHT)
		|| (currentLocation.y - snakePartSize <= 0 && partMovement == UP) || (currentLocation.y + snakePartSize >= screenHeight && partMovement == DOWN))
	{
		partMovement = STOP;
	}
	if (isHead) {
		//std::cout << "current location is: x: " << currentLocation.x << " y: " << currentLocation.y << std::endl;
		// use curren loc - the snake part size 

		auto cur = nextBodyPart;
		//to do: this doesn't work
		while (cur){

			if (cur->getNextBodyPart() && CheckCollisionRecs({ currentLocation.x, currentLocation.y, (float)snakePartSize, (float)snakePartSize }, 
				{ cur->getNextBodyPart()->getLocation().x, cur->getNextBodyPart()->getLocation().y, (float)snakePartSize, (float)snakePartSize})) {
				partMovement = STOP;
				break;
			}
			

			cur = cur->getNextBodyPart();
		}
	}

	if (isHead) {
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
	if (prevBodyPart) {
		if (prevBodyPart->getDirection() == STOP) {
			partMovement = STOP;
		}
		else {

			switch (prevBodyPart->getDirection()) {
				case LEFT:
					{
						currentLocation = Vector2{ prevBodyPart->getLocation().x + 10, prevBodyPart->getLocation().y};
						partMovement = prevBodyPart->getDirection();
					}
					break;
				case RIGHT:
					{
						currentLocation = Vector2{ prevBodyPart->getLocation().x - 10, prevBodyPart->getLocation().y };
						partMovement = prevBodyPart->getDirection();
					}
					break;
				case UP:
					{
						currentLocation = Vector2{ prevBodyPart->getLocation().x, prevBodyPart->getLocation().y + 10 };
						partMovement = prevBodyPart->getDirection();
					}
					break;
				case DOWN:
					{
						currentLocation = Vector2{ prevBodyPart->getLocation().x, prevBodyPart->getLocation().y - 10 };
						partMovement = prevBodyPart->getDirection();
					}
					break;
				default:
					break;
				}
			
		}
		
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