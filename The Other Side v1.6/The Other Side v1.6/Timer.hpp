#define _CRT_SECURE_NO_WARNINGS
#ifndef TIMER_HPP
#define TIMER_HPP
#include <stdio.h>
#include <stdlib.h>
#include "Ui.hpp"

int gameWin = 0;
extern int level;
int timerSeconds = 0;
bool timerRunning = false;
char timeStore[6];
bool showWinScreen = false;
double finalTime = 0;
int minutes, seconds;


double topTimers[3];
int topTimesCount = 0;

void timeFormat(int totalSeconds) {
	minutes = totalSeconds / 60;
	seconds = totalSeconds % 60;
	sprintf_s(timeStore, "%02d:%02d", minutes, seconds);
}

void loadTopTimes() {
	FILE* fp;
	topTimesCount = 0;
	if (fopen_s(&fp, "playerStats.txt", "r") == 0 && fp != NULL) {
		double allTimes[100];
		int allTimesCount = 0;
		double tempTime;
		while (fscanf_s(fp, "%lf", &tempTime) == 1 && allTimesCount < 100) {
			allTimes[allTimesCount] = tempTime;
			allTimesCount++;
		}
		fclose(fp);
		if (allTimesCount == 0) {
			return;
		}

		for (int i = 0; i < allTimesCount - 1; i++) {
			for (int j = 0; j < allTimesCount - i - 1; j++) {
				if (allTimes[j] > allTimes[j + 1]) {
					double temp = allTimes[j];
					allTimes[j] = allTimes[j + 1];
					allTimes[j + 1] = temp;
				}
			}
		}
		if (allTimesCount > 3) {
			topTimesCount = 3;
		}
		else {
			topTimesCount = allTimesCount;
		}

		for (int i = 0; i < topTimesCount; i++) {
			topTimers[i] = allTimes[i];
		}

	}

}

void saveTimeToFile() {
	FILE* fp;
	if (fopen_s(&fp, "playerStats.txt", "a") == 0 && fp != NULL) {
		fprintf(fp, "%.1f\n", (double)timerSeconds);
		fclose(fp);
	}

}


void getTopTimesForDisplay(char topTimeStrings[3][10]) {
	loadTopTimes();

	for (int i = 0; i < 3; i++) {
		if (i < topTimesCount) {
			int mins = (int)(topTimers[i] / 60);
			int secs = (int)topTimers[i] % 60;
			sprintf_s(topTimeStrings[i], 10, "%02d:%02d", mins, secs);
		}
	}
}

void incrementTimer() {
	if (timerRunning) timerSeconds++;
}

void showTimer() {
	timeFormat(timerSeconds);
	int mTens = minutes / 10;
	int mOnes = minutes % 10;
	int sTens = seconds / 10;
	int sOnes = seconds % 10;
	int timeX = displayX + displayWidth + displaySpacing + 12, timeY = displayY + 13, timeWidth = 30, timeHeight = 30, spacing = 10;
	iShowImage(displayX + displayWidth + displaySpacing, displayY, 150, 50, timeDisplay);
	iShowImage(timeX, timeY, timeWidth, timeHeight, digitImg[mTens]);
	iShowImage(timeX + timeWidth, timeY, timeWidth, timeHeight, digitImg[mOnes]);
	iShowImage(timeX + 2 * timeWidth, timeY, spacing, timeHeight, colonImage);
	iShowImage(timeX + 2 * timeWidth + spacing, timeY, timeWidth, timeHeight, digitImg[sTens]);
	iShowImage(timeX + 3 * timeWidth + spacing, timeY, timeWidth, timeHeight, digitImg[sOnes]);
}

void startTimer() {
	timerRunning = true;
	timerSeconds = 0;
}

void stopTimerAndSave() {
	if (timerRunning) {
		timerRunning = false;
		saveTimeToFile();
		finalTime = timerSeconds;
		showWinScreen = true;
	}
}

void showWinMessage() {
	if (showWinScreen) {
		timeFormat((int)finalTime);
		char timeText[100];
		sprintf_s(timeText, sizeof(timeText), "Completion Time: %s", timeStore);
		iSetColor(255, 255, 255);
		iText(510, 98, timeText, GLUT_BITMAP_HELVETICA_18);
	}
}

#endif