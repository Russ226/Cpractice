// RaylibAttempt1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "raylib.h"



int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    float speed = 100.0f;
    float angleDegrees = 45.0f; // Angle of movement in degrees
    float angleRadians = angleDegrees * DEG2RAD; // Convert to radians

    // Calculate the velocity vector from the angle
    Vector2 velocity = {
        speed * cosf(angleRadians),
        speed * sinf(angleRadians)
    };

	Vector2 circle_position = { screenWidth / 5, 120 };

    while (!WindowShouldClose())    
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircle(circle_position.x, circle_position.y, 7, DARKBLUE);

		circle_position.x += (velocity.x * GetFrameTime());
		circle_position.y += (velocity.y * GetFrameTime());

		if ((circle_position.x >= screenWidth) || (circle_position.x <= 0)) velocity.x *= -1;
		if ((circle_position.y >= screenHeight) || (circle_position.y <= 0)) velocity.y *= -1;
       


        EndDrawing();
        
    }

    CloseWindow();       

}
