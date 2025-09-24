#include "iGraphics.h"
#include "Menu.hpp"
#include "Hero.hpp"
#include "Ui.hpp"
#include "Level.hpp"
#include "Platforms.hpp"
#include "Box.hpp"
#include "Portal.hpp"
#include "Enemy.hpp"
#include "Trampoline.hpp"
#include "Boss.hpp"
#include "Timer.hpp"
#include "HeroPortal.hpp"
#include "ScoreBoard.hpp"

int x = 0;
int y = 0;

//level number. Main menu marked as 'Level 0'
bool gameWon = false;
bool pause = false; //Pause menu flag
bool music = true; //Music on/off flag
bool credits = false;
bool isHover[8] = {}; //0=menu play, 1=credit, 2=exit, 3=credit back, 4=pause, 5=resume, 6=home, 7=music on/off

void iDraw()
{
	iClear();

	if (level == 0)
	{
		showMenu();
		showMenuButtons(isHover);
	}// Shows main menu which has been marked 'Level 0'

	if (level != 0)
	{
		showLevels(level, isHover);
		if (level == 2)
		{
			showBoxes(2);
		}
		showPortals();
		if (level == 3)
		{
			showEnemyImage();
		}
		if (level == 4)
		{
			showLvl4Intro();
			showHeroPortal();
		}
		showBoss(level);
		showHero(level);
		showTimer();//up
		//checkWinCondition();//up


	}
	if (pause) showPauseBackground(music, isHover); // Shows pause menu when pause button is clicked; music is passed as parameter
	//update
	if (credits){
		showCredits();
		showBackButton(isHover);//update
	}//View Credits

	//hero dead gameover on screen
	if (gameOver) {
		iShowImage(0, 0, 1280, 720, gameOverScreen);
		//showGameWinOrOverButtons(isHover, gameOver, gameWon);
	} //change -> gameOver screen

	if (gameWon) {
		iShowImage(0, 0, 1280, 720, gameWonScreen);
		showWinMessage(); //up
		//showGameWinOrOverButtons(isHover, gameOver, gameWon);
	} //change -> gameWon screen




}

void onPlayClicked() {
	startTimer();
} //change

void timerPauseResume() {
	if (timerRunning) timerRunning = false;
	else timerRunning = true;
} //change -> pause timer when pause button is clicked and resume when resume clicked


void resumeMusic() {
	mciSendString("resume loadsong", NULL, 0, NULL);
}//update -> music resume function

void pauseMusic() {
	mciSendString("pause loadsong", NULL, 0, NULL);
}//update -> music pause function

void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{
	if (mx >= menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY + menuButtonsSpacing * 2 && my <= menuButtonsY + menuButtonsSpacing * 2 + menuButtonsHeight){
		isHover[0] = true;
	}
	else isHover[0] = false; //Menu Play Hover

	if (mx >= menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY + menuButtonsSpacing && my <= menuButtonsY + menuButtonsSpacing + menuButtonsHeight){
		isHover[1] = true;
	}
	else isHover[1] = false;//Credits button Hover

	if (mx > menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY && my <= menuButtonsY + menuButtonsHeight){
		isHover[2] = true;
	}
	else isHover[2] = false; //Quit button hover

	if (credits){
		if (mx >= backButtonX && mx <= backButtonX + backButtonWidth && my >= backButtonY && my <= backButtonY + backButtonHeight){
			isHover[3] = true;
		}
		else isHover[3] = false;
	}// Credits back button hover

	if (level != 0){
		if (mx >= PauseButtonX && mx <= PauseButtonX + PauseButtonWidth && my >= PauseButtonY && my <= PauseButtonY + PauseButtonHeight){
			isHover[4] = true;
		}
		else isHover[4] = false;
	} //Pause button hover

	if (level != 0 && pause){
		if (mx >= pauseMenuButtonX && mx <= pauseMenuButtonX + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
			isHover[5] = true;
		}
		else isHover[5] = false; //Resume hover

		if (mx >= pauseMenuButtonX + pauseMenuButtonSpacing && mx <= pauseMenuButtonX + pauseMenuButtonSpacing + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
			isHover[6] = true;
		}
		else isHover[6] = false;//Home hover

		if (mx >= pauseMenuButtonX + pauseMenuButtonSpacing * 2 && mx <= pauseMenuButtonX + pauseMenuButtonSpacing * 2 + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
			isHover[7] = true;
		}
		else isHover[7] = false;//Music On/Off Hover
	}
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d\n", mx, my);

		if (level == 0){//up
			bool leaderboardClicked = false;
			if (leaderboardClicked) {
				showScoreboard = !showScoreboard;
				if (showScoreboard) {
					
				}
			}
			if (showScoreboard) {
				leaderboardClicked = (mx >= leaderboardX && mx <= leaderboardX + leaderboardWidth &&
					my >= leaderboardY && my <= leaderboardY + leaderboardOpenHeight);
			}
			else {
				leaderboardClicked = (mx >= leaderboardX && mx <= leaderboardX + leaderboardWidth &&
					my >= leaderboardY && my <= leaderboardY + leaderboardHeight);
			}

			if (leaderboardClicked) {
				showScoreboard = !showScoreboard;
			}
		}//up

		if (level == 0){
			if (mx >= menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY + menuButtonsSpacing * 2 && my <= menuButtonsY + menuButtonsSpacing * 2 + menuButtonsHeight){
				level = 1;
				onPlayClicked();
			}
		} //Starts level 1 when play is clicked


		if (level == 0){
			if (mx >= menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY + menuButtonsSpacing && my <= menuButtonsY + menuButtonsSpacing + menuButtonsHeight){
				credits = true;
			}//View credits button
		}


		if (level == 0){
			if (mx > menuButtonsX && mx <= menuButtonsX + menuButtonsWidth && my >= menuButtonsY && my <= menuButtonsY + menuButtonsHeight){
				exit(0);
			}
		} //Exits the game when exit is clicked during main menu


		if (credits){
			if (mx >= backButtonX && mx <= backButtonX + backButtonWidth && my >= backButtonY && my <= backButtonY + backButtonHeight){
				credits = false;
			}
		} //Close credits button


		if (level != 0){
			if (mx >= PauseButtonX && mx <= PauseButtonX + PauseButtonWidth && my >= PauseButtonY && my <= PauseButtonY + PauseButtonHeight)
			{
				pause = true;
				timerPauseResume();
			}

		} //Pause button click function


		if (pause){
			if (mx >= pauseMenuButtonX && mx <= pauseMenuButtonX + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
				pause = false;
				timerPauseResume();

			}
		} //Resume button function during the pause screen


		if (pause){
			if (mx >= pauseMenuButtonX + pauseMenuButtonSpacing && mx <= pauseMenuButtonX + pauseMenuButtonSpacing + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
				pause = false;
				level = 0;
			}
		} //Home button function during the pause screen


		if (pause){
			if (mx >= pauseMenuButtonX + pauseMenuButtonSpacing * 2 && mx <= pauseMenuButtonX + pauseMenuButtonSpacing * 2 + pauseMenuButtonWH && my >= pauseMenuButtonY && my <= pauseMenuButtonY + pauseMenuButtonWH){
				if (music == true) music = false;
				else if (music == false) music = true;
				if (music) {
					resumeMusic();
				}
				else {
					pauseMusic();
				}
			}
		} //Music On Off button


		if (level == 0){

		}
		if (level != 0)
		{
			portalSizeControllerLvl1(mx, my); // size controller for lvl 1
			portalHorizontalPlacer(mx, my);
		}


	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){

		portalVerticalPlacer(mx, my);

	}
}

// Special Keys:
// GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
// GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT

void fixedUpdate()
{
	if (isKeyPressed(' ') || isSpecialKeyPressed(GLUT_KEY_UP))
	{
		if (isJumping == 0)
		{
			isJumping = true;
			jumpSpeed = initialJumpSpeed;
		}

	}
	if (isKeyPressed('a') || isSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		leftPressed = true;
		rightPressed = false;
	}
	if (isKeyPressed('s') || isSpecialKeyPressed(GLUT_KEY_DOWN))
	{
		y--;
	}
	if (isKeyPressed('d') || isSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		rightPressed = true;
		leftPressed = false;
	}

	if (isKeyPressed('w')) {
		// Playing the audio once
		mciSendString("play ggsong from 0", NULL, 0, NULL);
	}

	if (isKeyPressed('g')) {
		setShiftPressed(true);
	}
	else {
		setShiftPressed(false);
	}//update


}

void iKeyboard(unsigned char key)//up
{
	if (showWinScreen && key == ' ') {
		showWinScreen = false;
		gameWin = 0;
		level = 0;
		timerSeconds = 0;
		timerRunning = false;
	}
}



void collideWithBoss()
{
	bool overlapX = (heroX < Boss1[0].x + Boss1[0].width) && (heroX + heroWidth > Boss1[0].x);
	bool overlapY = (heroY < Boss1[0].y + Boss1[0].height) && (heroY + heroHeight > Boss1[0].y);
	if (overlapX && overlapY) {
		gameWin = 1;
		printf("%d", gameWin);
	}
}

void decreaseHealth() {
	if (level == 4) {
		// write condition here that will decrease enemy's health
		if (enemyHealth == 0) {
			gameWon = true;
			stopTimerAndSave();
		}
	}
} //change -> write whatever condition you want to decrease enemy health

void ms1update()
{
	collision(level);
	checkDoorCollision(level);

	grabBox(level);
	checkEnemyCollision(level);//update
	trampolineUpdate(level);
	LevelSwitch();
	bossMovement();
	collideWithBoss();
	bossShooting();
	heroPortalTimers();
	FirePortalCollide();
	FireHeroBossCollide();
	checkBoxOnButton();
	checkSpikeHit(level);
	checkButtonPress();
	checkDoorState();
	decreaseHealth();

	if (spikeHit) gameOver = true;
}

void AnimationCtrl()
{
	fireballAnim();
	menuAnim();
}


int main()
{
	mciSendString("open \"Audios//load.mp3\" alias loadsong", NULL, 0, NULL);//update
	if (music){
		mciSendString("play loadsong from 0", NULL, 0, NULL);
		mciSendString("play loadsong repeat", NULL, 0, NULL);
	}//update - music play function
	//iSetTimer(1, callRespawn);//update
	//iSetTimer(1, callGrabBox);//update
	//iSetTimer(1, checkCollision); //update
	//iSetTimer(1, callCheckDoorCollision);//update
	iSetTimer(1, checkButtonPress);//update


	iSetTimer(1, ms1update);

	iSetTimer(1, PortalCollision);
	iSetTimer(80, portalAnim);
	iSetTimer(120, AnimationCtrl);
	iSetTimer(10, Movement);
	iSetTimer(100, enemyMovement);
	iSetTimer(1000, incrementTimer);
	iSetTimer(100, bossAnim);
	iSetTimer(1000, lvl4introAnim);

	iInitialize(1280, 720, "Project Title");

	loadEnemyImages();
	loadLevels();
	loadUI(); //update
	loadCredits();
	loadHeroImages();
	loadElements(); //update
	initializeBoxes();
	loadPortalImages();
	loadBossImages();
	loadHorizontalPortalImages();



	initializeMenu();
	iStart();

	return 0;

}