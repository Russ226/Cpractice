#pragma once
#include <raylib.h>
#ifndef PADDLE_H     
#define PADDLE_H
enum PaddleMovement {
	UP,
	DOWN,
	IGNORE
};

class Paddle {
	private:
		int screenWidth;
		int screenHeight;
		int rectangleWidth;
		int rectangleHeight;
		Vector2 startingLocation;
		const float moveSpeed = 200.0f;
		Rectangle rec;
		Color rectangleColor = Color('255', '255', '255', '1.0');
	public:
		Paddle(int screenW, int screenH, int rectangleW, int rectangleH, Vector2 location);
		void draw();
		void update(PaddleMovement dir);
};


#endif