#pragma once
#include <raylib.h>
#include <map>
#ifndef PADDLE_H     
#define PADDLE_H

enum PaddleMovement {
	UP,
	DOWN,
	IGNORE
};

typedef std::map<PaddleMovement, KeyboardKey> directionalKeys;

class Paddle {
	private:
		int screenWidth;
		int screenHeight;
		int rectangleWidth;
		int rectangleHeight;
		Vector2 startingLocation;
		float moveSpeed;
		Rectangle rec;
		Color rectangleColor;
		directionalKeys dirKeys;
	public:
		Paddle(int screenW, int screenH, int rectangleW, int rectangleH, Vector2 location, directionalKeys dK);
		void draw();
		void update();
		Rectangle getRectangle();
};


#endif