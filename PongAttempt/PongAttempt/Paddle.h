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
		int screenWidth = 0 ;
		int screenHeight = 0;
		int rectangleWidth = 0;
		int rectangleHeight =0 ;
		Vector2 startingLocation = {0, 0};
		const float moveSpeed = 200.0f;
		Rectangle rec;
		Color rectangleColor = Color('255', '255', '255', '1.0');
	public:
		Paddle() {};
		Paddle(int screenW, int screenH, int rectangleW, int rectangleH, Vector2 location);
		void draw();
		void update(PaddleMovement dir);
		Rectangle getRectangle();
};


#endif