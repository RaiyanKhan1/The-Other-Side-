#ifndef BOSS_HPP
#define BOSS_HPP

#include "Level.hpp"

int enemyHealth = 3;


struct Boss {
	int x;
	int y;
	int width;
	int height;
	int image;
	
};

Boss Boss1[6] = {

	{ 500, 50, 100, 100 }

};

struct FireBall {
	int x;
	int y;
	int width;
	int height;
	int image;

};

FireBall fireball[5] = {

	{ -100, -100, 50, 50 }, { -100, -100, 50, 50 }, { -100, -100, 50, 50 }, { -100, -100, 50, 50 }, { -100, -100, 50, 50 }

};






void loadBossImages(){

	
	Boss1[0].image = iLoadImage("Images\\Boss\\Boss_idle1.png");
	Boss1[1].image = iLoadImage("Images\\Boss\\Boss_idle2.png");

	Boss1[2].image = iLoadImage("Images\\Boss\\Boss_run1.png");
	Boss1[3].image = iLoadImage("Images\\Boss\\Boss_run2.png");
	Boss1[4].image = iLoadImage("Images\\Boss\\Boss_run3.png");
	Boss1[5].image = iLoadImage("Images\\Boss\\Boss_run4.png");

	fireball[0].image = iLoadImage("Images\\Fireball\\FB001.png");
	fireball[1].image = iLoadImage("Images\\Fireball\\FB002.png");
	fireball[2].image = iLoadImage("Images\\Fireball\\FB003.png");
	fireball[3].image = iLoadImage("Images\\Fireball\\FB004.png");
	fireball[4].image = iLoadImage("Images\\Fireball\\FB005.png");

}

int fireballAnimCtrl = 1;
void fireballAnim()
{

	fireballAnimCtrl++;;
	if (fireballAnimCtrl == 5)
	{
		fireballAnimCtrl = 1;
	}
}

int direction = 1;
int BossRunAnimCtrl = 2;

void showBoss(int lvl) {

	if (lvl == 4)
	{
		iShowImage(Boss1[0].x, Boss1[0].y, Boss1[0].height * direction, Boss1[0].width, Boss1[BossRunAnimCtrl].image);
		iShowImage(fireball[0].x, fireball[0].y, fireball[0].height, fireball[0].width, fireball[fireballAnimCtrl].image);
		iShowImage(fireball[1].x, fireball[1].y, fireball[1].height, fireball[1].width, fireball[fireballAnimCtrl].image);
		iShowImage(fireball[2].x, fireball[2].y, fireball[2].height, fireball[2].width, fireball[fireballAnimCtrl].image);
		iShowImage(fireball[3].x, fireball[3].y, fireball[3].height, fireball[3].width, fireball[fireballAnimCtrl].image);
		iShowImage(fireball[4].x, fireball[4].y, fireball[4].height, fireball[4].width, fireball[fireballAnimCtrl].image);
	}

}


int bossJumpctrl = 1;
int bossJumpSpeed = 30;
bool bossJumping = false;

int boosIdle = 0;
bool bossIsIdle = false;
bool bossFired = false;

void bossAnim()
{
	if (bossIsIdle == false)
	{
		BossRunAnimCtrl++;
		
		if (BossRunAnimCtrl == 5)
		{
			BossRunAnimCtrl = 2;
		}
	}
	
}

void bossMovement()
{
	
	    boosIdle++;
		

		if (boosIdle > 200 && bossJumping == false)
		{
			bossIsIdle = true;

			if (boosIdle == 300)
			{
				boosIdle = 0;
				bossIsIdle = false;
				bossFired = false;
			}
		}
		else{
			bossJumpctrl++;
			Boss1[0].x += 5 * direction;

			if (Boss1[0].x > 1080)
			{
				direction = -1;

			}
			else if (Boss1[0].x < 100)
			{
				direction = 1;
			}

			if (bossJumpctrl == 80 || bossJumping == true)
			{
				Boss1[0].y += bossJumpSpeed;
				bossJumpSpeed -= 2;
				bossJumping = true;
			}
			if (Boss1[0].y < 50) {
				bossJumping = false;
				Boss1[0].y = 50;
				bossJumpSpeed = 30;
				bossJumpctrl = 0;

			}
		}
		


}


bool placedfireballs = false;
void bossShooting()
{
	if (level == 4)
	{
		if (bossIsIdle == true && bossFired == false)
		{

			if (bossJumping == false)
			{
				for (int i = 0; i < 4; i++)
				{
					fireball[i].x = Boss1[0].x;
					fireball[i].y = Boss1[0].y;
				}
				//fireball[0].x = Boss1[0].x;
				//fireball[0].y = Boss1[0].y;

				//fireball[1].x = Boss1[0].x;
				//fireball[1].y = Boss1[0].y;
				placedfireballs = true;
				bossFired = true;
			}


		}
		if (placedfireballs == true)
		{
			fireball[0].x++;
			fireball[0].y += 4;

			fireball[1].x--;
			fireball[1].y += 4;

			fireball[2].x -= 3;
			fireball[2].y += 4;

			fireball[3].x += 3;
			fireball[3].y += 4;
		}
	}
	

}









#endif