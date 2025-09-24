#ifndef BOX_HPP
#define BOX_HPP
#include "Hero.hpp"
#include "Platforms.hpp"

struct Box {
	int x;
	int y;
	int width;
	int height;
	int image;
};
Box boxes[] = {
	{ 1100, 545, 60, 60, 0 }
};
bool boxLoaded = false;
bool shiftPressed = false;
bool onPlatform = false;
bool boxGrabbed = false;
bool gKeyPressed = false;
bool level3BoxSet = false;
void loadBoxImages() {
	boxes[0].image = iLoadImage("Images\\Level\\Box.png");
	boxes[0].image = boxes[0].image;
}
void initializeBoxes() {

	loadBoxImages();
	boxLoaded = true;
}
void grabBox(int level) {
	if (level != 2 && level != 3) return;
	if (level == 3) {
		if (!level3BoxSet) {
			boxes[0].x = 700;
			boxes[0].y = 400;
			level3BoxSet = true;
		}
	}
	bool overlapX = (heroX < boxes[0].x + boxes[0].width) && (heroX + heroWidth > boxes[0].x);
	bool overlapY = (heroY < boxes[0].y + boxes[0].height) && (heroY + heroHeight > boxes[0].y);
	bool touching = overlapX && overlapY;
	if (shiftPressed && !gKeyPressed) {
		gKeyPressed = true;
		if (touching && !boxGrabbed) {
			boxGrabbed = true;
		}
		else if (boxGrabbed) {
			boxGrabbed = false;
		}
	}
	if (!shiftPressed) {
		gKeyPressed = false;
	}
	if (boxGrabbed) {
		boxes[0].x = heroX + 40;
		boxes[0].y = heroY;
		if (boxes[0].x < 0) boxes[0].x = 0;
		if (boxes[0].x + boxes[0].width > 1280) boxes[0].x = 1280 - boxes[0].width;
	}
}

void setShiftPressed(bool pressed) {
	shiftPressed = pressed;
}
void showBoxes(int level) {
	if ((level == 2 || level == 3) && boxLoaded) {
		iShowImage(boxes[0].x, boxes[0].y, boxes[0].width, boxes[0].height, boxes[0].image);
	}
}
#endif