#ifndef PLATFORMS_HPP
#define PLATFORMS_HPP

#include "Hero.hpp"
#include "Level.hpp"

bool collided = false;
int standed1 = 0;
int standed3 = 1;


// collision cooldown to prevent glitching
int collisionCooldown = 0;
bool wasColliding = false;

struct GroundLand {
	int x;
	int y;
	int height;
	int width;

	GroundLand(int _x, int _y, int _height, int _width) {
		x = _x;
		y = _y;
		height = _height;
		width = _width;
	}
};

// Platforms
GroundLand Gl1[2] = { { 760, 160, 70, 140 }, { 1040, 210, 130, 240 } };

GroundLand Gl2[6] = { { 29, 297, 50, 220 }, { 466, 42, 335, 135 }, { 610, 163, 15, 66 },
{ 680, 280, 15, 70 }, { 750, 80, 346, 504 }, { 997, 540, 15, 264 } };

GroundLand Gl3[12] = { { 3, 54, 720, 0 }, { 2, 435, 45, 310 }, { 360, 136, 300, 100 }, { 310, 435, 275, 145 }, { 1, 270, 28, 180 },
{ 645, 22, 367, 188 }, { 930, 96, 87, 336 }, { 835, 145, 40, 95 }, { 950, 243, 335, 315 }, { 643, 538, 41, 307 },
{ 1265, 22, 720, 0 }, { 31, 718, 0, 1240 } }; //{ 310, 435,275 ,145} comment this array to check collision 

GroundLand Gl4[4] = { { 45, 50, 670, 0 }, { 120, 465, 43, 1015 }, { 1265, 22, 720, 0 }, { 31, 718, 0, 1240 } };
void collision(int level) {
	if (collisionCooldown > 0) {
		collisionCooldown--;
		return;
	}

	collided = false;

	if (level == 1) {
		for (int i = 0; i < 2; i++) {
			bool collisionX = (heroX > Gl1[i].x - 70) && (heroX < (Gl1[i].x + Gl1[i].width));
			bool collisionY = (heroY >= (Gl1[i].y + Gl1[i].height));

			if (collisionX && collisionY) {
				groundLevel = Gl1[i].y + Gl1[i].height;
				standed1 = 1;
				collided = true;
			}
		}

		if (!collided && heroY > 50 && standed1 == 1) {
			groundLevel = 50;
			isFalling = 1;
			standed1 = 0;
		}
	}
	else if (level == 2) {
		for (int i = 0; i < 6; i++) {
			bool overlapX = (heroX < Gl2[i].x + Gl2[i].width) && (heroX + heroWidth > Gl2[i].x);// horizontal overlap between hero and platform
			bool overlapY = (heroY < Gl2[i].y + Gl2[i].height) && (heroY + heroHeight > Gl2[i].y);// vertical

			if (overlapX && overlapY) {
				int overlapLeft = (heroX + heroWidth) - Gl2[i].x;     //overlap each side 
				int overlapRight = (Gl2[i].x + Gl2[i].width) - heroX;
				int overlapTop = (heroY + heroHeight) - Gl2[i].y;
				int overlapBottom = (Gl2[i].y + Gl2[i].height) - heroY;

				int minOverlap = overlapLeft;
				int collisionSide = 0;        // 0 = left  1 = right  2 = top 3 = bottom

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;  //update minimum 
					collisionSide = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					collisionSide = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					collisionSide = 3;
				}

				if (minOverlap > 2) {
					if (collisionSide == 0 && velocityX > 0) {   // left side  push hero left  platform
						heroX = Gl2[i].x - heroWidth - 1;
						velocityX = 0;
						rightPressed = false;
						ctrR = 0;   //reset right movement
						collisionCooldown = 2;  //Set 2-frame cooldown 
					}
					else if (collisionSide == 1 && velocityX < 0) {  // right side push hero right platform
						heroX = Gl2[i].x + Gl2[i].width + 1;
						velocityX = 0;
						leftPressed = false;
						ctrL = 0;    //reset left movement
						collisionCooldown = 2;
					}
					else if (collisionSide == 2 && jumpSpeed > 0) {   //top hitting platform below
						heroY = Gl2[i].y - heroHeight - 1;
						jumpSpeed = -2;
					}
					else if (collisionSide == 3 && jumpSpeed <= 0) {   // bottom landing on platform
						heroY = Gl2[i].y + Gl2[i].height;
						groundLevel = Gl2[i].y + Gl2[i].height;
						isJumping = false;
						isFalling = 0;
						jumpSpeed = 0;
						standed1 = 1;
					}


					collided = true;
				}
			}
		}

		if (!collided && standed1 == 1 && heroY > 50) {
			bool stillOnPlatform = false;
			for (int i = 0; i < 6; i++) {
				if (heroX + heroWidth > Gl2[i].x && heroX < Gl2[i].x + Gl2[i].width && heroY == Gl2[i].y + Gl2[i].height) {
					stillOnPlatform = true;
				}
			}

			if (!stillOnPlatform) {
				groundLevel = 50;
				isFalling = 1;
				standed1 = 0;
			}
		}
	}

	else if (level == 3) {
		for (int i = 0; i <12; i++) {

			bool overlapX = (heroX < Gl3[i].x + Gl3[i].width) && (heroX + heroWidth > Gl3[i].x);
			bool overlapY = (heroY < Gl3[i].y + Gl3[i].height) && (heroY + heroHeight > Gl3[i].y);

			if (overlapX && overlapY) {

				int overlapLeft = (heroX + heroWidth) - Gl3[i].x;
				int overlapRight = (Gl3[i].x + Gl3[i].width) - heroX;
				int overlapTop = (heroY + heroHeight) - Gl3[i].y;
				int overlapBottom = (Gl3[i].y + Gl3[i].height) - heroY;


				int minOverlap = overlapLeft;
				int collisionSide = 0;

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;
					collisionSide = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					collisionSide = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					collisionSide = 3;
				}


				if (minOverlap > 2) {

					if (collisionSide == 0 && velocityX > 0) {
						heroX = Gl3[i].x - heroWidth - 1;
						velocityX = 0;
						rightPressed = false;
						ctrR = 0;
						collisionCooldown = 2;
					}

					else if (collisionSide == 1 && velocityX < 0) {
						heroX = Gl3[i].x + Gl3[i].width + 1;
						velocityX = 0;
						leftPressed = false;
						ctrL = 0;
						collisionCooldown = 2;
					}

					else if (collisionSide == 2 && jumpSpeed > 0) {
						heroY = Gl3[i].y - heroHeight - 1;
						jumpSpeed = -2;
					}

					else if (collisionSide == 3 && jumpSpeed <= 0) {
						heroY = Gl3[i].y + Gl3[i].height;
						groundLevel = Gl3[i].y + Gl3[i].height;
						isJumping = false;
						isFalling = 0;
						jumpSpeed = 0;
						standed3 = 1;
					}

					collided = true;
				}
			}
		}


		if (!collided && standed3 == 1 && heroY > 50) {
			bool stillOnPlatform = false;
			for (int i = 0; i < 12; i++) {

				if (heroX + heroWidth > Gl3[i].x &&
					heroX < Gl3[i].x + Gl3[i].width &&
					heroY == Gl3[i].y + Gl3[i].height) {
					stillOnPlatform = true;
					break;
				}
			}


			if (!stillOnPlatform) {
				groundLevel = 50;
				isFalling = 1;
				standed3 = 0;
			}
		}
	}
	else if (level == 4) {
		for (int i = 0; i <4; i++) {

			bool overlapX = (heroX < Gl4[i].x + Gl4[i].width) && (heroX + heroWidth > Gl4[i].x);
			bool overlapY = (heroY < Gl4[i].y + Gl4[i].height) && (heroY + heroHeight > Gl4[i].y);

			if (overlapX && overlapY) {

				int overlapLeft = (heroX + heroWidth) - Gl4[i].x;
				int overlapRight = (Gl4[i].x + Gl4[i].width) - heroX;
				int overlapTop = (heroY + heroHeight) - Gl4[i].y;
				int overlapBottom = (Gl4[i].y + Gl4[i].height) - heroY;


				int minOverlap = overlapLeft;
				int collisionSide = 0;

				if (overlapRight < minOverlap) {
					minOverlap = overlapRight;
					collisionSide = 1;
				}
				if (overlapTop < minOverlap) {
					minOverlap = overlapTop;
					collisionSide = 2;
				}
				if (overlapBottom < minOverlap) {
					minOverlap = overlapBottom;
					collisionSide = 3;
				}


				if (minOverlap > 2) {

					if (collisionSide == 0 && velocityX > 0) {
						heroX = Gl4[i].x - heroWidth - 1;
						velocityX = 0;
						rightPressed = false;
						ctrR = 0;
						collisionCooldown = 2;
					}

					else if (collisionSide == 1 && velocityX < 0) {
						heroX = Gl4[i].x + Gl4[i].width + 1;
						velocityX = 0;
						leftPressed = false;
						ctrL = 0;
						collisionCooldown = 2;
					}

					else if (collisionSide == 2 && jumpSpeed > 0) {
						heroY = Gl4[i].y - heroHeight - 1;
						jumpSpeed = -2;
					}

					else if (collisionSide == 3 && jumpSpeed <= 0) {
						heroY = Gl4[i].y + Gl4[i].height;
						groundLevel = Gl4[i].y + Gl4[i].height;
						isJumping = false;
						isFalling = 0;
						jumpSpeed = 0;
						standed3 = 1;
					}

					collided = true;
				}
			}
		}


		if (!collided && standed3 == 1 && heroY > 50) {
			bool stillOnPlatform = false;
			for (int i = 0; i < 12; i++) {

				if (heroX + heroWidth > Gl4[i].x &&
					heroX < Gl4[i].x + Gl4[i].width &&
					heroY == Gl4[i].y + Gl4[i].height) {
					stillOnPlatform = true;
					break;
				}
			}


			if (!stillOnPlatform) {
				groundLevel = 50;
				isFalling = 1;
				standed3 = 0;
			}
		}
	}

	wasColliding = collided;
}

#endif