#include "Snake.h"
#include "raylib.h"

void Snake::draw() {
	auto& cur = head;
	while (cur) {
		cur->draw();
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

	auto& cur = head;
	while (cur) {
		cur->setDirection(currentDirection);
		cur->update();
		cur = cur->getNextBodyPart();
	}
}