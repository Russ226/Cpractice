#pragma once
#include <raylib.h>
#include <math.h>
#ifndef BALL_H     
#define BALL_H

class Ball {
	private:
        int screenWidth;
        int screenHeight;
        float speed = 100.0f;
        float angleDegrees = 45.0f; 
        float angleRadians = angleDegrees * DEG2RAD;
        Vector2 velocity = {
            speed * cosf(angleRadians),
            speed * sinf(angleRadians)
        };
        Vector2 curPos = { 160, 120 };
    public:
        Ball(int sW, int sH);
        void draw();
        void update();
};

#endif
