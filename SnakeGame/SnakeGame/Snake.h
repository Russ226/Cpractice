#include "UIBehavior.h"
#include "raylib.h"
#include <memory>
#ifndef SNAKE_H     
#define SNAKE_H

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
};

// snake 
class SnakePart : public UIBehavior {
	private:
		int screenWidth;
		int screenHeight;
		float snakePartSize;
		float snakeSpeed;
		Vector2 initialLocation;
		Vector2 currentLocation;
		Rectangle body;
		bool isHead;
		std::shared_ptr<SnakePart> nextBodyPart;
		Direction partMovement;
	public:
		SnakePart(int screenW, int screenH, float snakePartS, float snakeSp,Vector2 initialLoc, bool isH, std::shared_ptr<SnakePart> nextBP, Direction dir);
		std::shared_ptr<SnakePart> getNextBodyPart();
		void setDirection(Direction dir);
		void draw() override;
		void update()override;
};

class Snake: public UIBehavior {
	private:
		int screenWidth;
		int screenHeight;
		float bodyPartSize;
		float snakeSpeed;
		Direction currentDirection;
		std::shared_ptr<SnakePart> head;
	public:
		Snake(int screenW, int screenH, float bodyPartS, float snakeS, Vector2 spawnPoint, Direction curDir);
		void draw() override;
		void update()override;
};

#endif
