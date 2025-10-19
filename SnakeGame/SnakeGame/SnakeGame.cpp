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
    auto node2 = std::make_shared<SnakePart>(SnakePart(screenWidth, screenHeight, snakePartSize, snakeSpeed, node2_loc, false, nullptr, nullptr, UP));
    auto node3 = std::make_shared<SnakePart>(SnakePart(screenWidth-20, screenHeight - 20, snakePartSize, snakeSpeed, node2_loc, false, nullptr, nullptr, UP));
    auto node4 = std::make_shared<SnakePart>(SnakePart(screenWidth - 40, screenHeight - 40, snakePartSize, snakeSpeed, node2_loc, false, nullptr, nullptr, UP));
    auto node5 = std::make_shared<SnakePart>(SnakePart(screenWidth - 80, screenHeight - 80, snakePartSize, snakeSpeed, node2_loc, false, nullptr, nullptr, UP));
    
    auto snake = Snake(screenWidth, screenHeight, padding, snakePartSize, snakeSpeed, h_loc, UP);
    snake.addBodyPart(node2);
    snake.addBodyPart(node3);
    //snake.addBodyPart(node4); 
    //snake.addBodyPart(node5);
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

