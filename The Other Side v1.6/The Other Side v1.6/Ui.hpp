#ifndef UI_HPP
#define UI_HPP

int play[2] = {};  //[0] -> normal, [1]-> hover
int credit[2] = {};
int quit[2] = {};
int backButton[2] = {};
int pauseButton[2] = {};
int resume[2] = {};
int home[2] = {};
int menuButton[2] = {}; //change
int musicOn[2] = {};
int musicOff[2] = {};
int mPlayButtonClick;
int healthBar[4] = {}; //change
int digitImg[10]; //change
int colonImage; //change
int displayX = 40, displayY = 665, displayWidth = 150, displayHeight = 50, displaySpacing = 20; //change
int levelDisplay; //change
int timeDisplay; //change
int pauseBackground;
int gameOverScreen; //change
int gameWonScreen; //change
const int healthBarX = 1045, healthBarY = 670, healthBarWidth = 128, healthBarHeight = 40; //change
const int menuButtonsX = 520, menuButtonsY = 50, menuButtonsWidth = 240, menuButtonsHeight = 80, menuButtonsSpacing = 90;
const int backButtonX = 32, backButtonY = 642, backButtonWidth = 130, backButtonHeight = 40;
const int PauseButtonX = 1185, PauseButtonY = 665, PauseButtonWidth = 50, PauseButtonHeight = 50;
const int gameOverHomeButtonX = 590, gameOverHomeButtonY = 80, gameOverHomeButtonWidth = 100, gameOverHomeButtonHeight = 100; //change
const int gameWinMenuButtonX = 480, gameWinMenuButtonY = 50, gameWinMenuButtonWidth = 260, gameWinMenuButtonHeight = 100; //change
const int pauseMenuButtonX = 440, pauseMenuButtonY = 310, pauseMenuButtonWH = 100, pauseMenuButtonSpacing = 150; //WH -> width and height


void loadTimerImages() {
	char path[100];
	for (int i = 0; i < 10; i++) {
		sprintf_s(path, "Images//Ui//Level Number//%d.png", i);
		digitImg[i] = iLoadImage(path);
	}
	colonImage = iLoadImage("Images//Ui//Level Number//colon.png");
} //change -> load timer images

void loadUI(){
	play[0] = iLoadImage("Images//Ui//Play.png");
	play[1] = iLoadImage("Images//Ui//PlayHover.png");
	mPlayButtonClick = iLoadImage("Images//Ui//MenuPlayButtonClick.png");
	credit[0] = iLoadImage("Images//Ui//Credits.png");
	credit[1] = iLoadImage("Images//Ui//CreditsHover.png");
	quit[0] = iLoadImage("Images//Ui//Quit.png");
	quit[1] = iLoadImage("Images//Ui//QuitHover.png");
	backButton[0] = iLoadImage("Images//Ui//Back.png");
	backButton[1] = iLoadImage("Images//Ui//BackHover.png");
	levelDisplay = iLoadImage("Images//Ui//level.png");
	timeDisplay = iLoadImage("Images//Ui//TimeDisplay.png");
	pauseButton[0] = iLoadImage("Images//Ui//Pause.png");
	pauseButton[1] = iLoadImage("Images//Ui//PauseHover.png");
	pauseBackground = iLoadImage("Images//Ui//pausemenu.png");
	resume[0] = iLoadImage("Images//Ui//Resume.png");
	resume[1] = iLoadImage("Images//Ui//ResumeHover.png");
	home[0] = iLoadImage("Images//Ui//Home.png");
	home[1] = iLoadImage("Images//Ui//HomeHover.png");
	menuButton[0] = iLoadImage("Images//Ui//Menu.png"); //change
	menuButton[1] = iLoadImage("Images//Ui//MenuHover.png"); //change
	musicOn[0] = iLoadImage("Images//Ui//MusicOn.png");
	musicOn[1] = iLoadImage("Images//Ui//MusicOnHover.png");
	musicOff[0] = iLoadImage("Images//Ui//MusicOff.png");
	musicOff[1] = iLoadImage("Images//Ui//MusicOffHover.png");
	healthBar[0] = iLoadImage("Images//Ui//Health Bar//Health3.png"); //change
	healthBar[1] = iLoadImage("Images//Ui//Health Bar//Health2.png"); //change
	healthBar[2] = iLoadImage("Images//Ui//Health Bar//Health1.png"); //change
	healthBar[3] = iLoadImage("Images//Ui//Health Bar//Health0.png"); //change
	gameOverScreen = iLoadImage("Images//Ui//gameOver.png"); //change
	gameWonScreen = iLoadImage("Images//Ui//Win.png"); //change
	loadTimerImages(); //change
}



void showMenuButtons(bool isHover[]){
	if (isHover[0]) iShowImage(menuButtonsX, menuButtonsY + menuButtonsSpacing * 2, menuButtonsWidth, menuButtonsHeight, play[1]);
	else iShowImage(menuButtonsX, menuButtonsY + menuButtonsSpacing * 2, menuButtonsWidth, menuButtonsHeight, play[0]);

	if (isHover[1]) iShowImage(menuButtonsX, menuButtonsY + menuButtonsSpacing, menuButtonsWidth, menuButtonsHeight, credit[1]);
	else iShowImage(menuButtonsX, menuButtonsY + menuButtonsSpacing, menuButtonsWidth, menuButtonsHeight, credit[0]);

	if (isHover[2]) iShowImage(menuButtonsX, menuButtonsY, menuButtonsWidth, menuButtonsHeight, quit[1]);
	else iShowImage(menuButtonsX, menuButtonsY, menuButtonsWidth, menuButtonsHeight, quit[0]);

}



void showHealthBar(int level, int enemyHealth) {
	if (level == 4) {
		iText(1080, 659, "Enemy Health", GLUT_BITMAP_HELVETICA_10);
		if (enemyHealth == 3) iShowImage(healthBarX, healthBarY, healthBarWidth, healthBarHeight, healthBar[0]);
		else if (enemyHealth == 2) iShowImage(healthBarX, healthBarY, healthBarWidth, healthBarHeight, healthBar[1]);
		else if (enemyHealth == 1) iShowImage(healthBarX, healthBarY, healthBarWidth, healthBarHeight, healthBar[2]);
		else if (enemyHealth == 0) iShowImage(healthBarX, healthBarY, healthBarWidth, healthBarHeight, healthBar[3]);
	}
} //change -> shows enemy health bar

void showPauseButton(bool isHover[]){
	if (isHover[4]) iShowImage(PauseButtonX, PauseButtonY, PauseButtonWidth, PauseButtonHeight, pauseButton[1]);
	else iShowImage(PauseButtonX, PauseButtonY, PauseButtonWidth, PauseButtonHeight, pauseButton[0]);
}


void showLevelDisplay(){
	iShowImage(displayX, displayY, displayWidth, displayHeight, levelDisplay);
}


void showResumeButton(bool isHover[]){
	if (isHover[5]){
		iShowImage(pauseMenuButtonX, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, resume[1]);
		iText(555, 150, "Click to resume game", GLUT_BITMAP_HELVETICA_18);
	}
	else iShowImage(pauseMenuButtonX, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, resume[0]);
}


void showHomeButton(bool isHover[]){
	if (isHover[6]){
		iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, home[1]);
		iText(560, 150, "Return to main menu", GLUT_BITMAP_HELVETICA_18);
	}
	else iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, home[0]);


}

void showGameWinOrOverButtons(bool isHover[], bool gameOver, bool gameWon) {
	if (gameOver) {
		if (isHover[8]) {
			iShowImage(gameOverHomeButtonX, gameOverHomeButtonY, gameOverHomeButtonWidth, gameOverHomeButtonHeight, home[1]);
		}
		else iShowImage(gameOverHomeButtonX, gameOverHomeButtonY, gameOverHomeButtonWidth, gameOverHomeButtonHeight, home[0]);
	}
	if (gameWon) {
		if (isHover[9]) {
			iShowImage(gameWinMenuButtonX, gameWinMenuButtonY, gameWinMenuButtonWidth, gameWinMenuButtonHeight, menuButton[1]);
		}
		else iShowImage(gameWinMenuButtonX, gameWinMenuButtonY, gameWinMenuButtonWidth, gameWinMenuButtonHeight, menuButton[0]);
	}

} //change -> shows buttons on gameover or gamewon screen


void showMusic(bool music, bool isHover[]){
	if (music){
		if (isHover[7]){
			iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing * 2, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, musicOn[1]);
			iText(601, 150, "Music On", GLUT_BITMAP_HELVETICA_18);
		}
		else  iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing * 2, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, musicOn[0]);
	}

	else if (music == false){
		if (isHover[7]){
			iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing * 2, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, musicOff[1]);
			iText(601, 150, "Music Off", GLUT_BITMAP_HELVETICA_18);
		}
		else iShowImage(pauseMenuButtonX + pauseMenuButtonSpacing * 2, pauseMenuButtonY, pauseMenuButtonWH, pauseMenuButtonWH, musicOff[0]);
	}
}


void showPauseBackground(bool music, bool isHover[]){ //Opens the pause menu when clicked
	iShowImage(0, 0, 1280, 720, pauseBackground);
	showResumeButton(isHover);
	showHomeButton(isHover);
	showMusic(music, isHover);
}


void showBackButton(bool isHover[]){
	if (isHover[3]) iShowImage(backButtonX, backButtonY, backButtonWidth, backButtonHeight, backButton[1]);
	else iShowImage(backButtonX, backButtonY, backButtonWidth, backButtonHeight, backButton[0]);
}




#endif