#ifndef TRAMP_H
#define TRAMP_H
#include "Hero.hpp"
#include "Level.hpp"

struct Trampoline{
	int x;
	int y;
	int width;
	int height;
};

Trampoline tramp[] = {
	{ 620, 48, 20, 10 },
	{ 840, 186, 20, 10 }
};



bool trampolineOverlapX1 = false;
bool trampolineOverlapY1 = false;
bool trampolineOverlapX2 = false;
bool trampolineOverlapY2 = false;

const float bounceMultiplier = 1.5f;

void trampolineUpdate(int level){
	if (level == 3) {
		trampolineOverlapX1 = (heroX + heroWidth > tramp[0].x && heroX < tramp[0].x + tramp[0].width);
		trampolineOverlapY1 = (heroY <= tramp[0].y + tramp[0].height && heroY >= tramp[0].y);
		trampolineOverlapX2 = (heroX + heroWidth > tramp[1].x && heroX < tramp[1].x + tramp[1].width);
		trampolineOverlapY2 = (heroY <= tramp[1].y + tramp[1].height && heroY >= tramp[1].y);

		if ((trampolineOverlapX1 && trampolineOverlapY1) || (trampolineOverlapX2 && trampolineOverlapY2)) {
			isJumping = true;
			jumpSpeed = initialJumpSpeed * bounceMultiplier;
		}
	}

}


#endif