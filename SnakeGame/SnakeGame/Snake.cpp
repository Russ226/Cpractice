#include "Snake.h"
#include "raylib.h"

Snake::Snake(int screenW, int screenH, float bodyPartS, float snakeS, Vector2 spawnPoint, Direction curDir) {
	this->screenHeight = screenH;
	this->screenWidth = screenW;
	this->bodyPartSize = bodyPartS;
	this->currentDirection = curDir;
	this->snakeSpeed = snakeS;
	this->head = std::make_shared<SnakePart>(SnakePart(screenW, screenH, bodyPartS, snakeS, spawnPoint, true, nullptr, curDir));

}

void Snake::draw() {
	auto cur = head;
	while (cur) {
		cur->draw();
		cur = cur->getNextBodyPart();
	}
}

void Snake::update() {
	if (IsKeyPressed(KEY_W)) {
		currentDirection = UP;
	}
	else if (IsKeyPressed(KEY_S)) {
		currentDirection = DOWN;
	}
	else if (IsKeyPressed(KEY_A)) {
		currentDirection = LEFT;
	}
	else if (IsKeyPressed(KEY_D)) {
		currentDirection = RIGHT;
	}

	auto cur = head;
	while (cur) {
		cur->setDirection(currentDirection);
		cur->update();
		cur = cur->getNextBodyPart();
	}
}

void Snake::addBodyPart(std::shared_ptr<SnakePart> sb) {
	bool hasAdded = false;

	auto cur = head;
	while (cur) {
		if (!head->getNextBodyPart()) {
			switch (currentDirection) {
			case LEFT:
				break;
			case RIGHT:
				break;
			case UP:
				break;
			case DOWN:
				break;
			default:
				break;
			}
		}
		cur = head->getNextBodyPart();
	}

	//get loc of tail;

	while (!hasAdded) {
		hasAdded = cur->addBodyPart(sb);
		cur = head->getNextBodyPart();
	}

}