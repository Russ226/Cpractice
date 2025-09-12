#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <map>
#include <memory>

enum Screen {
	START,
	GAME,
	END
};

enum Players {
	PLAYER1,
	PLAYER2
};

class GameManager{
	private:
		int screenWidth;
		int screenHeight;
		Screen curScreen;
		std::map<Players, int> score;
		std::shared_ptr <Ball> ball;
		std::shared_ptr<Paddle> player1;
		std::shared_ptr<Paddle> player2;
	public:
		GameManager(int sw, int sh);
		void draw();
		void update();
		void drawScore();
		~GameManager();
};