#pragma once
#include <raylib.h>
#include <math.h>
#ifndef BALL_H     
#define BALL_H

class Ball {
	private:
        int screenWidth = 0;
        int screenHeight = 0;
        float radius = 7;
        float speed = 100.0f;
        float angleDegrees = 45.0f; 
        float angleRadians = angleDegrees * DEG2RAD;
        Vector2 velocity = {
            speed * cosf(angleRadians),
            speed * sinf(angleRadians)
        };
        Vector2 intialPos = { 160, 120 };
        Vector2 curPos = { 160, 120 };
    public:
        Ball() {};
        Ball(int sW, int sH);
        void draw();
        void update(Rectangle rec);
};

#endif
