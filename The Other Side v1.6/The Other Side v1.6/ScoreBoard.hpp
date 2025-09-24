#define _CRT_SECURE_NO_WARNINGS
#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP
#include "Timer.hpp"
#include <stdio.h>
#include <stdlib.h>

bool showScoreboard = false;
bool gameCompleted = false;

int leaderboardClosedImage;
int leaderboardOpenedImage;
int leaderboardX = 1000;
int leaderboardY = 50;
int leaderboardWidth = 250;
int leaderboardHeight = 400;
int leaderboardOpenHeight = 400;

void loadLeaderboardImages() {
	leaderboardClosedImage = iLoadImage("Images\\MenuImage\\leaderboard_2.png");
	leaderboardOpenedImage = iLoadImage("Images\\MenuImage\\leaderboard_1.png");
}
void showLeaderboard() {
	if (showScoreboard) {
		iShowImage(leaderboardX, leaderboardY, leaderboardWidth, leaderboardOpenHeight, leaderboardOpenedImage);


		char topTimeStrings[3][10];
		getTopTimesForDisplay(topTimeStrings);

		int scoreStartY = leaderboardY + leaderboardOpenHeight - 100;
		for (int i = 0; i < 3; i++) {
			char scoreText[50];
			sprintf_s(scoreText, sizeof(scoreText), " %s", topTimeStrings[i]);
			iText(leaderboardX + 120, scoreStartY - 45 - (i * 70), scoreText, GLUT_BITMAP_HELVETICA_12);
		}
	}
	else {
		iShowImage(leaderboardX, leaderboardY, leaderboardWidth, leaderboardHeight, leaderboardClosedImage);
	}
}
void onGameWin() {
	gameCompleted = true;

}

#endif