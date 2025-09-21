// PongAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "raylib.h"
#include <string>
#include "Paddle.h"
#include "Ball.h"
#include "Button.h"
#include "GameManager.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    const std::string players[2] = { "PLayer 1", "Player 2" };

    InitWindow(screenWidth, screenHeight, "pong");

    SetTargetFPS(60);
    GameManager gh = GameManager(screenWidth, screenHeight);
    Button btn = Button(Vector2(100, 100), 100, 200, BLUE, "test", []() {std::cout << "I've benn clicked!\n";});
    while (!WindowShouldClose())
    {
        btn.update();
        //gh.update();
        BeginDrawing();
        ClearBackground(BLANK);
        //gh.draw();
        btn.draw();
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
