#include "GameManager.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>

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
	player1= std::make_shared<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ 20, (float)screenHeight/2 }, player1Keys));
	player2 = std::make_shared<Paddle>(Paddle(screenWidth, screenHeight, 10, 100, Vector2{ (float)screenWidth - 20, (float)screenHeight / 2 }, player2Keys));
	ball = std::make_shared<Ball>(Ball(sw, sh, player1, player2));
	score = std::map<Players, int>();
	score.insert({ PLAYER1, 0 });
	score.insert({ PLAYER2, 0 });

	startBtn = std::make_unique<Button>(Button(Vector2(100, 100), 100, 200, BLACK, WHITE, "Start", [&]() {curScreen = GAME; }));
	endBtn = std::make_unique<Button>(Button(Vector2(100, 100), 100, 200, BLACK, WHITE, "Play Again", [&]() {curScreen = GAME; }));
}

void GameManager::draw()
{
	switch(curScreen) {
		case START:
			startBtn->draw();
			break;
		case GAME:
			drawScore();
			player1->draw();
			player2->draw();
			ball->draw();
			break;
		case END:
			endBtn->draw();
			break;
		default:
			std::cout << "Invalid game state" << std::endl;
			curScreen = START;
			break;
	}
	
}

void GameManager::update()
{
	switch (curScreen) {
		case START:
			startBtn->update();
			break;
		case GAME:
			ball->update();
			player1->update();
			player2->update();

			if (ball->getCurrentPos().x >= screenWidth - 1) {
				score[PLAYER2]++;
			}
			if (ball->getCurrentPos().x <= 0 + 1) {
				score[PLAYER1]++;
			}
			if (score[PLAYER1] == 3 || score[PLAYER2] == 3) {
				score[PLAYER1] = score[PLAYER2] = 0;
				curScreen = END;
			}
			break;
		case END:
			endBtn->update();
			break;
		default:
			std::cout << "Invalid game state" << std::endl;
			curScreen = START;
			break;
	}

	
}

void GameManager::drawScore(){
	DrawText(TextFormat("%i", score[PLAYER1]), (screenWidth/2) - 50, 20, 20, WHITE);
	DrawText(TextFormat("%i", score[PLAYER2]), (screenWidth/2) + 50, 20, 20, WHITE);
}

GameManager::~GameManager()
{
	ball.reset();
	player1.reset();
	player2.reset();
}
