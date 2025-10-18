#include <iostream>
#include "raylib.h"
#include "Snake.h"


int main()
{
    int screenWidth = 800;
    int screenHeight = 450;
    float snakePartSize = 10.0;
    float snakeSpeed = 50.0;

    InitWindow(screenWidth, screenHeight, "Snake");
    auto h_loc = Vector2();
    h_loc.x = screenWidth / 2;
    h_loc.y = screenHeight / 2;
    //auto headNode = std::make_shared<SnakePart>(SnakePart(screenWidth, screenHeight, snakePartSize, snakeSpeed, h_loc, true, NULL, RIGHT));

    auto snake = Snake(screenWidth, screenHeight, snakePartSize, snakeSpeed, h_loc, RIGHT);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        snake.update();
        BeginDrawing();
        ClearBackground(BLANK);
        snake.draw();
        EndDrawing();

    }
    CloseWindow();
}

