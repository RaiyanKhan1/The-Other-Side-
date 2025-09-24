#ifndef HEROPORTAL_HPP
#define HEROPORTAL_HPP

#include "Portal.hpp"
#include "Boss.hpp"

struct HeroPortal {
	int x;
	int y;
	int width;
	int height;
};

HeroPortal Heroportal1[2] = {

	{ -300, -100, 100, 100 }, { -300, -100, -100, 100 }

};

int HeroPortalimage[6];

void loadHorizontalPortalImages() {

	HeroPortalimage[0] = iLoadImage("Images\\Portal\\Horizontalportal_1.png");
	HeroPortalimage[1] = iLoadImage("Images\\Portal\\Horizontalportal_2.png");
	HeroPortalimage[2] = iLoadImage("Images\\Portal\\Horizontalportal_3.png");
	HeroPortalimage[3] = iLoadImage("Images\\Portal\\Horizontalportal_4.png");
	HeroPortalimage[4] = iLoadImage("Images\\Portal\\Horizontalportal_5.png");
	HeroPortalimage[5] = iLoadImage("Images\\Portal\\Horizontalportal_6.png");


	
}

void HorizontalportalAnim()
{
	portalAnima++;
	if (portalAnima == 6)
	{
		portalAnima = 0;
	}
}


void showHeroPortal()
{
	
		iShowImage(Heroportal1[0].x, Heroportal1[0].y, Heroportal1[0].height, Heroportal1[0].width, HeroPortalimage[portalAnima]);
		iShowImage(Heroportal1[1].x, Heroportal1[1].y, Heroportal1[1].height, Heroportal1[1].width, Portalimages[portalAnima]);
	
	
}


//-----------------------------------------------Placer---------------------------
bool HportalPlaced = false;
bool VportalPlaced = false;

void portalHorizontalPlacer(int mx, int my)
{
	if (mx > 120 && mx < 1130 && my > 460 && my < 520 && HportalPlaced == false)
	{
		Heroportal1[0].x = mx-50;
		Heroportal1[0].y = 420;
		HportalPlaced = true;
	}
}

void portalVerticalPlacer(int mx, int my)
{
	if (mx > 1 && mx < 45 && my > 50 && my < 715 && VportalPlaced == false)
	{
		Heroportal1[1].x = -10;
		Heroportal1[1].y = my+50;
		VportalPlaced = true;
	}
}
//-----------------------------------------------Cooldown---------------------------
int hPortalCtrl = 0;
int vPortalCtrl = 0;

void heroPortalTimers()
{
	if (HportalPlaced == true)
	{
		hPortalCtrl++;
		if (hPortalCtrl == 300)
		{
			HportalPlaced = false;
			hPortalCtrl = 0;
			Heroportal1[0].x = -300;
		}
	}
	if (VportalPlaced == true)
	{
		vPortalCtrl++;
		if (vPortalCtrl == 300)
		{
			VportalPlaced = false;
			vPortalCtrl = 0;
			Heroportal1[1].x = -300;
		}
	}
}


bool placedHeroFireballs = false;
void FirePortalCollide()
{
	for (int i = 0; i < 4; i++)
	{
		if (fireball[i].x >= Heroportal1[0].x && fireball[i].x <= Heroportal1[0].x + Heroportal1[0].width && fireball[i].y >= Heroportal1[0].y && fireball[i].y <= Heroportal1[0].y +  Heroportal1[0].height)
		{
			fireball[i].x = -500;
			
			if (VportalPlaced == true)
			{
				fireball[4].x = Heroportal1[1].x+50;
				fireball[4].y = Heroportal1[1].y-50;
				placedHeroFireballs = true;
			}
		}
	}

	if (placedHeroFireballs == true)
	{
		fireball[4].x += 10;

	}

	if (fireball[4].x > 1300)
	{
		fireball[4].x = -300;
		placedHeroFireballs = false;
	}


	
}

void FireHeroBossCollide()
{
	if (fireball[4].x >= Boss1[0].x && fireball[4].x <= Boss1[0].x + Boss1[0].width && fireball[4].y >= Boss1[0].y && fireball[4].y <= Boss1[0].y + Boss1[0].height)
	{
		fireball[4].x = -300;
		enemyHealth--;
		printf("%d", enemyHealth);
		placedHeroFireballs = false;
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (fireball[i].x >= heroX-50 && fireball[i].x <= heroX + heroWidth && fireball[i].y >= heroY && fireball[i].y <= heroY + heroHeight)
		{
			fireball[i].x = -300;
			gameOver = true;
			

		}
	}

}







#endif