#ifndef PORTAL_HPP
#define PORTAL_HPP

#include "Hero.hpp"
#include "Box.hpp"
#include "Enemy.hpp"



int portalAnima = 0;

struct LvlPortal {
	int x;
	int y;
	int width;
	int height;
};

LvlPortal Lvlportal1[1] = {

	{ 1180, 340, 100, 100 }

};

LvlPortal Lvlportal2[1] = {

	{ 54, 50, 100, 100 }

};

LvlPortal Lvlportal3[1] = {

	{ 1040, 570, 100, 100 }

};

int LvlPortalimages[1];


struct Portal {
	int x;
	int y;
	int width;
	int height;

};

Portal portal1[2]
{
	{ 1100, 420, 70, 70 }, { 610, 50, 70, 70 }
};

Portal portal2[6]
{
	{ 490, 50, 70, 70 }, { 60, 50, 70, 70 }, { 210, 480, 70, 70 }, { 20, 298, 70, 70 }, { 1180, 183, 50, 50 }, { 830, 50, 70, 70 }
};


int Portalimages[6];

void loadPortalImages() {

	Portalimages[0] = iLoadImage("Images\\Portal\\portal_1.png");
	Portalimages[1] = iLoadImage("Images\\Portal\\portal_2.png");
	Portalimages[2] = iLoadImage("Images\\Portal\\portal_3.png");
	Portalimages[3] = iLoadImage("Images\\Portal\\portal_4.png");
	Portalimages[4] = iLoadImage("Images\\Portal\\portal_5.png");
	Portalimages[5] = iLoadImage("Images\\Portal\\portal_6.png");


	LvlPortalimages[0] = iLoadImage("Images\\Portal\\level_portal_1.png");
}

void portalAnim()
{
	portalAnima++;
	if (portalAnima == 6)
	{
		portalAnima = 0;
	}
}



void showPortals() {

	if (level == 1)
	{
		iShowImage(Lvlportal1[0].x, Lvlportal1[0].y, Lvlportal1[0].height, Lvlportal1[0].width, LvlPortalimages[0]);
	}
	else if (level == 2)
	{

		iShowImage(portal1[0].x, portal1[0].y, portal1[0].height, portal1[0].width, Portalimages[portalAnima]);


		iShowImage(portal1[1].x, portal1[1].y, portal1[1].height, portal1[1].width, Portalimages[portalAnima]);


		iShowImage(Lvlportal2[0].x, Lvlportal2[0].y, Lvlportal2[0].height, Lvlportal2[0].width, LvlPortalimages[0]);
	}
	else if (level == 3)
	{
		iShowImage(portal2[0].x, portal2[0].y, portal2[0].height, portal2[0].width, Portalimages[portalAnima]);
		iShowImage(portal2[1].x, portal2[1].y, portal2[1].height, portal2[1].width, Portalimages[portalAnima]);

		iShowImage(portal2[2].x, portal2[2].y, portal2[2].height, portal2[2].width, Portalimages[portalAnima]);
		iShowImage(portal2[3].x, portal2[3].y, portal2[3].height, portal2[3].width, Portalimages[portalAnima]);

		iShowImage(portal2[4].x, portal2[4].y, portal2[4].height, portal2[4].width, Portalimages[portalAnima]);
		iShowImage(portal2[5].x, portal2[5].y, portal2[5].height, portal2[5].width, Portalimages[portalAnima]);

		iShowImage(Lvlportal3[0].x, Lvlportal3[0].y, Lvlportal3[0].height, Lvlportal3[0].width, LvlPortalimages[0]);
	}




}


bool pcollision1 = false;
bool pcollision2 = false;

bool ecollision1 = false;
bool ecollision2 = false;

void PortalCollision()
{

	if (level == 2)
	{
		pcollision1 = (heroX >= portal1[0].x + 2 && heroX <= portal1[0].x + 6) && (heroY <= (portal1[0].y + portal1[0].height) && heroY >= (portal1[0].y));

		if (pcollision1) {

			heroX = portal1[1].x + 8;
			heroY = portal1[1].y;
			heroHeight = portal1[1].height;
			heroWidth = portal1[1].width;
			groundLevel = 50;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal1[1].height;
				boxes[0].width = portal1[1].width;
			}



		}

		pcollision2 = (heroX >= portal1[1].x + 2 && heroX <= portal1[1].x + 6) && (heroY <= (portal1[1].y + portal1[1].height) && heroY >= (portal1[1].y));

		if (pcollision2 && heroHeight <= portal1[1].height) {

			heroX = portal1[0].x;
			heroY = portal1[0].y;
			heroHeight = portal1[0].height;
			heroWidth = portal1[0].width;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal1[0].height;
				boxes[0].width = portal1[0].width;
			}


			groundLevel = 426;
		}


	}
	else if (level == 3)
	{

		//------------------------------------------------portals 1 ----------------------------------------------------------------------------

		if ((heroX >= portal2[2].x + 2 && heroX <= portal2[2].x + 6) && (heroY <= (portal2[2].y + portal2[2].height) && heroY >= (portal2[2].y)) && heroHeight <= portal2[2].height) {

			heroX = portal2[3].x + 8;
			heroY = portal2[3].y;
			heroHeight = portal2[3].height;
			heroWidth = portal2[3].width;
			//groundLevel = portal2[3].y;;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[3].height;
				boxes[0].width = portal2[3].width;
			}



		}


		if ((heroX >= portal2[3].x + 2 && heroX <= portal2[3].x + 6) && (heroY <= (portal2[3].y + portal2[3].height) && heroY >= (portal2[3].y)) && heroHeight <= portal2[3].height) {

			heroX = portal2[2].x;
			heroY = portal2[2].y;
			heroHeight = portal2[2].height;
			heroWidth = portal2[2].width;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[2].height;
				boxes[0].width = portal2[2].width;
			}


			//groundLevel = portal2[2].y;
		}

		//------------------------------------------------portals 1 end ----------------------------------------------------------------------------

		//------------------------------------------------portals 2 ----------------------------------------------------------------------------
		if ((heroX >= portal2[0].x + 2 && heroX <= portal2[0].x + 6) && (heroY <= (portal2[0].y + portal2[0].height) && heroY >= (portal2[0].y)) && heroHeight <= portal2[0].height) {

			heroX = portal2[1].x + 8;
			heroY = portal2[1].y;
			heroHeight = portal2[1].height;
			heroWidth = portal2[1].width;
			//groundLevel = portal2[1].y;


			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[1].height;
				boxes[0].width = portal2[1].width;
			}



		}


		if ((heroX >= portal2[1].x + 2 && heroX <= portal2[1].x + 6) && (heroY <= (portal2[1].y + portal2[1].height) && heroY >= (portal2[1].y)) && heroHeight <= portal2[1].height) {

			heroX = portal2[0].x;
			heroY = portal2[0].y;
			heroHeight = portal2[0].height;
			heroWidth = portal2[0].width;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[0].height;
				boxes[0].width = portal2[0].width;
			}


			//groundLevel = portal2[0].y;
		}

		//------------------------------------------------portals 2 End ----------------------------------------------------------------------------

		//------------------------------------------------portals 3 ----------------------------------------------------------------------------

		if ((heroX >= portal2[4].x + 2 && heroX <= portal2[4].x + 6) && (heroY <= (portal2[4].y + portal2[4].height) && heroY >= (portal2[4].y)) && heroHeight <= portal2[4].height) {

			heroX = portal2[5].x + 8;
			heroY = portal2[5].y;
			heroHeight = portal2[5].height;
			heroWidth = portal2[5].width;
			//groundLevel = portal2[3].y;;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[5].height;
				boxes[0].width = portal2[5].width;
			}



		}


		if ((heroX >= portal2[5].x + 2 && heroX <= portal2[5].x + 6) && (heroY <= (portal2[5].y + portal2[5].height) && heroY >= (portal2[5].y)) && heroHeight <= portal2[5].height) {

			heroX = portal2[4].x;
			heroY = portal2[4].y;
			heroHeight = portal2[4].height;
			heroWidth = portal2[4].width;

			if (boxGrabbed == true)
			{
				boxes[0].height = portal2[4].height;
				boxes[0].width = portal2[4].width;
			}


			//groundLevel = portal2[2].y;
		}

		//------------------------------------------------portals 3 end ----------------------------------------------------------------------------

		// enemy collision
		for (int i = 0; i < 3; i++)
		{

			ecollision1 = (Lvl3Enemy[i].x >= portal2[0].x + 2 && Lvl3Enemy[i].x <= portal2[0].x + 15) && (Lvl3Enemy[i].y <= (portal2[0].y + portal2[0].height) && Lvl3Enemy[i].y >= (portal2[0].y));
			ecollision2 = (Lvl3Enemy[i].x >= portal2[1].x + 2 && Lvl3Enemy[i].x <= portal2[1].x + 15) && (Lvl3Enemy[i].y <= (portal2[1].y + portal2[1].height) && Lvl3Enemy[i].y >= (portal2[1].y));



			if (ecollision1 == true)
			{
				Lvl3Enemy[i].x = portal2[1].x + 2;
				Lvl3Enemy[i].y = portal2[1].y;
				Lvl3Enemy[i].h = portal2[1].height;
				Lvl3Enemy[i].w = portal2[1].width;


			}
			else if (ecollision2 == true)
			{
				Lvl3Enemy[i].x = portal2[0].x - 2;
				Lvl3Enemy[i].y = portal2[0].y;
				Lvl3Enemy[i].h = portal2[0].height;
				Lvl3Enemy[i].w = portal2[0].width;

			}

		}


	}




}


void portalSizeControllerLvl1(int mx, int my)
{
	if (level == 2)
	{
		if (mx >= portal1[1].x && mx <= (portal1[1].x + portal1[1].width) && my >= portal1[1].y && my <= (portal1[1].y + portal1[1].height))
		{
			if (portal1[1].width == 70)
			{
				portal1[1].width = 50;
				portal1[1].height = 50;
				portal1[1].x = 632;
			}
			else if (portal1[1].width == 50)
			{
				portal1[1].width = 30;
				portal1[1].height = 30;
				portal1[1].x = 636;
			}
			else if (portal1[1].width == 30)
			{
				portal1[1].width = 70;
				portal1[1].height = 70;
				portal1[1].x = 630;
			}
		}
	}
	else if (level == 3)
	{
		if (mx >= portal2[0].x && mx <= (portal2[0].x + portal2[0].width) && my >= portal2[0].y && my <= (portal2[0].y + portal2[0].height))
		{
			if (portal2[0].width == 70)
			{
				portal2[0].width = 50;
				portal2[0].height = 50;

			}
			else if (portal2[0].width == 50)
			{
				portal2[0].width = 30;
				portal2[0].height = 30;

			}
			else if (portal2[0].width == 30)
			{
				portal2[0].width = 70;
				portal2[0].height = 70;

			}
		}

		if (mx >= portal2[5].x && mx <= (portal2[5].x + portal2[5].width) && my >= portal2[5].y && my <= (portal2[5].y + portal2[5].height))
		{
			if (portal2[5].width == 70)
			{
				portal2[5].width = 50;
				portal2[5].height = 50;

			}
			else if (portal2[5].width == 50)
			{
				portal2[5].width = 30;
				portal2[5].height = 30;

			}
			else if (portal2[5].width == 30)
			{
				portal2[5].width = 70;
				portal2[5].height = 70;

			}
		}


	}

}

void LevelSwitch()
{
	if (level == 1)
	{
		if ((heroX > Lvlportal1[0].x - 70) && (heroX < (Lvlportal1[0].x + Lvlportal1[0].width)) && (heroY >= (Lvlportal1[0].y)) && (heroY <= (Lvlportal1[0].y + Lvlportal1[0].width))){

			level = 2;

		}
			
	}
	else if (level == 2)
	{
		if ((heroX > Lvlportal2[0].x - 70) && (heroX < (Lvlportal2[0].x + Lvlportal2[0].width)) && (heroY >= (Lvlportal2[0].y)) && (heroY <= (Lvlportal2[0].y + Lvlportal2[0].width))){

			level = 3;

		}

	}
	else if (level == 3)
	{
		if ((heroX > Lvlportal3[0].x - 70) && (heroX < (Lvlportal3[0].x + Lvlportal3[0].width)) && (heroY >= (Lvlportal3[0].y)) && (heroY <= (Lvlportal3[0].y + Lvlportal3[0].width))){

			level = 4;

		}

	}

}









#endif