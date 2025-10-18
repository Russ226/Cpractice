#include <iostream>
#include "raylib.h"
#include "Snake.h"


int main()
{
    int screenWidth = 800;
    int screenHeight = 450;
    int padding = 5;
    int snakePartSize = 10.0;
    float snakeSpeed = 50.0;

    InitWindow(screenWidth, screenHeight, "Snake");
    auto h_loc = Vector2();
    h_loc.x = screenWidth / 2;
    h_loc.y = screenHeight / 2;
    auto node2_loc = Vector2{ 200, 400 };
    auto node2 = std::make_shared<SnakePart>(SnakePart(screenWidth, screenHeight, snakePartSize, snakeSpeed, node2_loc, false, nullptr, nullptr, RIGHT));
    
    auto snake = Snake(screenWidth, screenHeight, padding, snakePartSize, snakeSpeed, h_loc, RIGHT);
    snake.addBodyPart(node2);
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

