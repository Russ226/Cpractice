#pragma once
#include <raylib.h>
#include <math.h>
#include <memory>
#include "Paddle.h"
#include "UIBehavior.h"
#ifndef BALL_H     
#define BALL_H

class Ball: public UIBehavior {
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
        std::shared_ptr<Paddle> player1;
        std::shared_ptr<Paddle> player2;
    public:
        Ball() {};
        Ball(int sW, int sH, std::shared_ptr<Paddle> p1, std::shared_ptr<Paddle> p2);
        void draw() override;
        void update() override;
        Vector2 getCurrentPos();
        ~Ball();
};

#endif
