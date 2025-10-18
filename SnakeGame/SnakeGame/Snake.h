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
		int snakePartSize;
		float snakeSpeed;
		Vector2 initialLocation;
		Vector2 currentLocation;
		Vector2 changeDirectionAt;
		Rectangle body;
		bool isHead;
		std::shared_ptr<SnakePart> nextBodyPart;
		std::shared_ptr<SnakePart> prevBodyPart;
		Direction partMovement;
	public:
		SnakePart(int screenW, int screenH, int snakePartS, float snakeSp,Vector2 initialLoc, bool isH, std::shared_ptr<SnakePart> nextBP, std::shared_ptr<SnakePart> prevBP, Direction dir);
		std::shared_ptr<SnakePart> getNextBodyPart();
		std::shared_ptr<SnakePart> getPrevBodyPart();
		bool addNextBodyPart(std::shared_ptr<SnakePart> sb);
		bool addPrevBodyPart(std::shared_ptr<SnakePart> sb);
		void setDirection(Direction dir, Vector2 cda);
		Vector2 getLocation();
		Rectangle getRectangle();
		void setCurrentLocation(Vector2 l);
		void draw() override;
		void update()override;
};
// basically a doubly linked list
class Snake: public UIBehavior {
	private:
		int screenWidth;
		int screenHeight;
		int padding;
		int bodyPartSize;
		float snakeSpeed;
		Direction currentDirection;
		std::shared_ptr<SnakePart> head;
	public:
		Snake(int screenW, int screenH, int p, int bodyPartS, float snakeS, Vector2 spawnPoint, Direction curDir);
		void addBodyPart(std::shared_ptr<SnakePart> sb);
		void draw() override;
		void update()override;
};

#endif
