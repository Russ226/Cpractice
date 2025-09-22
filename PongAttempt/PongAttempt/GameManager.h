#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "UIBehavior.h"
#include "Button.h"
#include <map>
#include <memory>

#ifndef GAMEMANGER_H
#define GAMEMANGER_H

enum Screen {
	START,
	GAME,
	END
};

enum Players {
	PLAYER1,
	PLAYER2
};

class GameManager: public UIBehavior {
	private:
		int screenWidth;
		int screenHeight;
		Screen curScreen;
		std::map<Players, int> score;
		std::shared_ptr <Ball> ball;
		std::shared_ptr<Paddle> player1;
		std::shared_ptr<Paddle> player2;
		std::unique_ptr<Button> startBtn;
		std::unique_ptr<Button> endBtn;
	public:
		GameManager(int sw, int sh);
		void draw() override;
		void update()override;
		void drawScore();
		~GameManager();
};

#endif