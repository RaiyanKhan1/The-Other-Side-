#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Level.hpp"

bool gameOver = false;
bool enemyAlive[3] = { true, true, true };

struct EnemyPos{
	int x;
	int y;
	int h;
	int w;
};

int AnimIndex = 0;

EnemyPos Lvl3Enemy[3] = {

	{ 300, 50, 70, 70 }, { 420, 50, 70, 70 }, { 180, 50, 70, 70 }

};



struct Enemy{

	int image;
} E[4];

void loadEnemyImages(){

	E[0].image = iLoadImage("Images\\Enemy\\Enemy_Walk_1.png");
	E[1].image = iLoadImage("Images\\Enemy\\Enemy_Walk_2.png");
	E[2].image = iLoadImage("Images\\Enemy\\Enemy_Walk_3.png");
	E[3].image = iLoadImage("Images\\Enemy\\Enemy_Walk_4.png");

}


void showEnemyImage()
{
	if (level == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			iShowImage(Lvl3Enemy[i].x, Lvl3Enemy[i].y, Lvl3Enemy[i].h, Lvl3Enemy[i].w, E[AnimIndex].image);
			
		}
		
	}

}


void enemyMovement()
{
	if (level == 3)
	{
		Lvl3Enemy[0].x -= 8;
		Lvl3Enemy[1].x -= 8;
		Lvl3Enemy[2].x -= 8;
		AnimIndex++;
		if (AnimIndex == 4)
		{
			AnimIndex = 0;
		}
	}





}


void checkEnemyCollision(int level) {
	if (level != 3) return;
	for (int i = 0; i < 3; i++) {
		if (!enemyAlive[i]) continue;
		bool overlapX = (heroX < Lvl3Enemy[i].x + Lvl3Enemy[i].w) && (heroX + heroWidth > Lvl3Enemy[i].x);
		bool overlapY = (heroY < Lvl3Enemy[i].y + Lvl3Enemy[i].h) && (heroY + heroHeight > Lvl3Enemy[i].y);
		if (overlapX && overlapY) {
			int heroSize = heroWidth * heroHeight;
			int enemySize = Lvl3Enemy[i].w * Lvl3Enemy[i].h;
			if (heroSize > enemySize) {
				enemyAlive[i] = false;
				Lvl3Enemy[i].x = -200;
				jumpSpeed = 8;
				isJumping = true;
				isFalling = false;
			}

			else{
				gameOver = true;
			}
		}
	}
}

















#endif