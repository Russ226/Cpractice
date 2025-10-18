#include "Snake.h"
#include "raylib.h"

Snake::Snake(int screenW, int screenH, int p, int bodyPartS, float snakeS, Vector2 spawnPoint, Direction curDir) {
	this->screenHeight = screenH;
	this->screenWidth = screenW;
	this->bodyPartSize = bodyPartS;
	this->currentDirection = curDir;
	this->snakeSpeed = snakeS;
	this->padding = p;
	this->head = std::make_shared<SnakePart>(SnakePart(screenW, screenH, bodyPartS, snakeS, spawnPoint, true, nullptr, nullptr, curDir));

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

	auto loc_change = head->getLocation();

	if (currentDirection == RIGHT || currentDirection == UP) {
		loc_change.y += .5;
		loc_change.x += .5;
	
	}

	if (currentDirection == LEFT || currentDirection == DOWN) {
		loc_change.y -= .5;
		loc_change.x -= .5;

	}
	auto cur = head;
	while (cur) {
		cur->setDirection(currentDirection, loc_change);
		cur->update();
		cur = cur->getNextBodyPart();
	}
}

void Snake::addBodyPart(std::shared_ptr<SnakePart> sb) {
	bool hasAdded = false;

	auto cur = head;
	while (cur) {
		if (!cur->getNextBodyPart()) {
			switch (currentDirection) {
			case LEFT:
				{
					auto parent_loc = cur->getLocation();
					Vector2 child_loc = { cur->getLocation().x + bodyPartSize + padding  , cur->getLocation().y};
					sb->setCurrentLocation(child_loc);
				}
				break;
			case RIGHT:
				{
					auto parent_loc = cur->getLocation();
					Vector2 child_loc = { cur->getLocation().x - bodyPartSize - padding  , cur->getLocation().y};
					sb->setCurrentLocation(child_loc);
				}
				break;
			case UP:
				{
					auto parent_loc = cur->getLocation();
					Vector2 child_loc = { cur->getLocation().x, cur->getLocation().y + bodyPartSize + padding};
					sb->setCurrentLocation(child_loc);
				}
				break;
			case DOWN:
				{
					auto parent_loc = cur->getLocation();
					Vector2 child_loc = { cur->getLocation().x  , cur->getLocation().y - bodyPartSize - padding};
					sb->setCurrentLocation(child_loc);
				}
				break;
			default:
				break;
			}


			break;
		}
		cur = cur->getNextBodyPart();
	}

	//get loc of tail;

	while (!hasAdded) {
		if (!cur->getNextBodyPart()) {
			sb->addPrevBodyPart(cur);
			hasAdded = cur->addNextBodyPart(sb);
		
		}
		cur = cur->getNextBodyPart();
	}

}