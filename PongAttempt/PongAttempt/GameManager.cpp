#include "GameManager.h"
#include "Ball.h"
#include "Paddle.h"

GameManager::GameManager(int sw, int sh)
{
	auto player1Keys = directionalKeys();
	player1Keys.insert({PaddleMovement::DOWN, KeyboardKey::KEY_S});
	player1Keys.insert({PaddleMovement::UP, KeyboardKey::KEY_W});

	auto player2Keys = directionalKeys();
	player2Keys.insert({ PaddleMovement::DOWN, KeyboardKey::KEY_DOWN });
	player2Keys.insert({ PaddleMovement::UP, KeyboardKey::KEY_UP });

	curScreen = START;
	screenWidth = sw;
	screenHeight = sh;
	player1= std::make_shared<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ 10, (float)screenHeight/2 }, player1Keys));
	player2 = std::make_shared<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ (float)screenWidth - 10, (float)screenHeight / 2 }, player2Keys));
	ball = std::make_shared<Ball>(Ball(sw, sh, player1, player2));
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
	player1->update();
	player2->update();
	ball->update();
}
