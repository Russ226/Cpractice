// PongAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include <string>
#include "Paddle.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const std::string players[2] = { "PLayer 1", "Player 2" };

    InitWindow(screenWidth, screenHeight, "pong");

    SetTargetFPS(60);

    Paddle p1 = Paddle(screenWidth, screenHeight, 10, 100, Vector2{ 10,screenHeight/2});

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLANK);
        if (IsKeyDown(KeyboardKey::KEY_W)) {
            p1.draw(PaddleMovement::UP);
        }
        if (IsKeyDown(KeyboardKey::KEY_S)) {
            p1.draw(PaddleMovement::DOWN);
        }
        p1.draw(PaddleMovement::IGNORE);
       
        EndDrawing();

    }

    CloseWindow();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
