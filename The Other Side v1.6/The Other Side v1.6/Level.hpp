#ifndef LVL_HPP
#define LVL_HPP
#include "UI.hpp"
#include "Hero.hpp"
#include "Box.hpp"
#include "Trampoline.hpp"
#include "Timer.hpp"
#include "Boss.hpp"


int currentLevel;
bool buttonPressed = false;
bool boxOnButton = false;
bool isDoorOpen = false;
bool spikeHit = false;
int level = 0;
int buttonImage[2] = {}; // 0 -> unpressed, 1 -> pressed //update
int spikesImage[3] = {}; // 0 -> 2 headed spikes, 1 -> 4 Headed spikes //update
int doorImage[2] = {}; //update -> name change
int trampImage; //update
const int NUMBER_OF_LEVELS = 4;



struct Door{
	int x;
	int y;
	int width;
	int height;
};//update


Door door[] = {
	{ 187, 44, 53, 250 },
	{ 643, 579, 53, 140 }

};//update


struct Pbutton {
	int x;
	int y;
	int width;
	int height;
};

Pbutton pbtn[] = {
	{ 1180, 44, 60, 30 },
	{ 1200, 44, 60, 30 }
};

struct Spikes{
	int x;
	int y;
	int width;
	int height;
};

Spikes spike[] = {
	{ 317, 40, 150, 43 }
};

int level4Introl;

void loadElements(){
	spikesImage[0] = iLoadImage("Images//Level//2HeadedSpike.png");
	spikesImage[1] = iLoadImage("Images//Level//4HeadedSpike.png");
	spikesImage[2] = iLoadImage("Images//Level//4HeadedSpikeLong.png");
	buttonImage[0] = iLoadImage("Images//Level//Button.png");
	buttonImage[1] = iLoadImage("Images//Level//ButtonPressed.png");
	trampImage = iLoadImage("Images//Level//trampoline.png");
	doorImage[0] = iLoadImage("Images//Level//door.png");
	doorImage[1] = iLoadImage("Images//Level//doorOpen.png");
	level4Introl = iLoadImage("Images//Level//level4intro.png");

}//elements are spikes and doors

void showElements(int level){
	if (level == 2){
		iShowImage(spike[0].x, spike[0].y, spike[0].width, spike[0].height, spikesImage[1]);
		if (buttonPressed == false && boxOnButton == false){
			iShowImage(pbtn[0].x, pbtn[0].y, pbtn[0].width, pbtn[0].height, buttonImage[0]);
		}
		else iShowImage(pbtn[0].x, pbtn[0].y, pbtn[0].width, pbtn[0].height, buttonImage[1]);

		if (isDoorOpen) {
			iShowImage(door[0].x, door[0].y, door[0].width, door[0].height, doorImage[1]);
		}
		else {
			iShowImage(door[0].x, door[0].y, door[0].width, door[0].height, doorImage[0]);
		}
	}
	if (level == 3){
		iShowImage(tramp[0].x, tramp[0].y, tramp[0].width, tramp[0].height, trampImage);
		iShowImage(tramp[1].x, tramp[1].y, tramp[1].width, tramp[1].height, trampImage);

		if (buttonPressed == false && boxOnButton == false){
			iShowImage(pbtn[1].x, pbtn[1].y, pbtn[1].width, pbtn[1].height, buttonImage[0]);
		}
		else iShowImage(pbtn[1].x, pbtn[1].y, pbtn[1].width, pbtn[1].height, buttonImage[1]);

		if (isDoorOpen) {
			iShowImage(door[1].x, door[1].y, door[1].width, door[1].height, doorImage[1]);
		}
		else {
			iShowImage(door[1].x, door[1].y, door[1].width, door[1].height, doorImage[0]);
		}
	}
}


void checkDoorState() {
	isDoorOpen = (buttonPressed || boxOnButton);
}


void checkButtonPress(){
	if ((heroX + heroWidth > pbtn[0].x) && (heroX < pbtn[0].x + pbtn[0].width) && (heroY == 50)){
		buttonPressed = true;
	}
	else buttonPressed = false;
}

void checkBoxOnButton(){
	if ((boxes[0].x + boxes[0].width > pbtn[0].x) && (boxes[0].x < pbtn[0].x + pbtn[0].width) && (boxes[0].y == 50)){
		boxOnButton = true;
	}
	else boxOnButton = false;
}

void checkSpikeHit(int level){
	if (level == 2) {
		if ((heroX + heroWidth > spike[0].x + 13) && (heroX < spike[0].x + spike[0].width) && (heroY > spike[0].y) && (heroY < spike[0].y + spike[0].height - 15)) {
			spikeHit = true;
			
		}
		else {
			spikeHit = false;
		}
	}
}



void checkDoorCollision(int level){
	if (level == 2){
		if (isDoorOpen == false){
			if ((heroX < door[0].x + door[0].width) && (heroY < door[0].y + door[0].height)){
				heroX = (door[0].x + door[0].width) + 1;
			}
		}
	}

	else if (level == 3){
		if (isDoorOpen == false){
			if ((heroX + heroWidth > door[1].x) && (heroY >= door[1].y)){
				heroX = door[1].x - heroWidth;
			}
		}
	}
}



struct Level{
	int background; //integer for storing the level's specific background image memory address
	int levelNum;
} L[NUMBER_OF_LEVELS];

void loadLevels(){ //Loads the background images for all the levels
	for (int i = 0; i < NUMBER_OF_LEVELS; i++){
		char text[100];
		char levelNum[50];
		sprintf_s(text, "Images\\Level\\level%d.png", i + 1);
		sprintf_s(levelNum, "Images//Ui//Level Number//%d.png", i + 1);
		L[i].background = iLoadImage(text);
		L[i].levelNum = iLoadImage(levelNum); //using number pics to display level number
	}
}

void showLevels(int level, bool isHover[]){ //takes the level number as argument from iMain
	iShowImage(0, 0, 1280, 720, L[level - 1].background);
	showPauseButton(isHover); //pause button ui
	showLevelDisplay(); //level display ui
	iShowImage(displayX + 110, displayY + 13, 30, 30, L[level - 1].levelNum);
	showElements(level);
	showBoxes(level);
	showTimer(); //change -> shows timer
	showHealthBar(level, enemyHealth); //change -> shows enemy health
}//hover effect


bool stopLvl4Intro = false;
int lvl4introCtrl = 0;
void lvl4introAnim()
{
	if (level == 4)
	{
		lvl4introCtrl++;
		if (lvl4introCtrl == 7)
		{
			stopLvl4Intro = true;
		}
	}
}

void showLvl4Intro()
{
	if (stopLvl4Intro == false)
	{
		iShowImage(0, 0, 1280, 720, level4Introl);
	}
	
}






#endif