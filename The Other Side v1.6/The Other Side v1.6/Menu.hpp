#ifndef MENU_H
#define MENU_H
#include"ScoreBoard.hpp"
#include "Timer.hpp"

int creditPage;

int menu[5];
int i = 1;


void initializeMenu(){



	menu[1] = iLoadImage("Images\\MenuImage\\menu_1.png");
	menu[2] = iLoadImage("Images\\MenuImage\\menu_2.png");
	menu[3] = iLoadImage("Images\\MenuImage\\menu_3.png");
	menu[4] = iLoadImage("Images\\MenuImage\\menu_4.png");
	menu[5] = iLoadImage("Images\\MenuImage\\menu_5.png");

	loadLeaderboardImages();//up
	//loadScores();//up
}


void showMenu(){

	iShowImage(0, 0, 1280, 720, menu[i]);
	showLeaderboard();//up

}

void menuAnim()
{

	i++;;
	if (i == 5)
	{
		i = 1;
	}
}


void loadCredits(){
	creditPage = iLoadImage("Images//Credit//credits.png");
}

void showCredits(){
	iShowImage(0, 0, 1280, 720, creditPage);
}






#endif