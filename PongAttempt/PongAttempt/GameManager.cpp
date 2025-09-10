#include "GameManager.h"
#include "Ball.h"
#include "Paddle.h"

GameManager::GameManager(int sw, int sh)
{
	curScreen = START;
	screenWidth = sw;
	screenHeight = sh;
	ball = std::make_unique<Ball>(Ball(sw, sh));
	player1 = std::make_unique<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ 10, (float)screenHeight/2 }));
	player2 = std::make_unique<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ (float)screenWidth - 10, (float)screenHeight / 2 }));
	score = std::map<Players, int>();
	score.insert({ PLAYER1, 0 });
	score.insert({ PLAYER2, 0 });
}

void GameManager::Draw()
{
	player1->draw();
	player2->draw();
	ball->draw();
}

void GameManager::Update()
{
}
