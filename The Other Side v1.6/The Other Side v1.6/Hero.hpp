#ifndef HERO_HPP
#define HERO_HPP



//ground level across all map
int groundLevel = 50;
//jumping variables
const float gravity = 0.5;
const float initialJumpSpeed = 18;
bool isJumping = false;
float jumpSpeed = 0;
int jumpAnimSpeed = 0;



//idle 
int isIdle = 1;
int idleFrame = 0;
int idleAnimSpeed = 0;


//hero position
int heroX = 0;
int heroY = 0;


//Horizontal Movement Variables
float velocityX = 0.0f;
float acceleration = 1.0f;
float friction = 0.2f;
float maxSpeed = 5.0f;

int ctrR = 0;
bool rightPressed = false;
int rightAnimSpeed = 0;

int ctrL = 0;
bool leftPressed = false;
int leftAnimSpeed = 0;


int heroHeight = 70;
int heroWidth = 70;

int currentDir = 1;


int isFalling = 0;


struct Hero{

	int image;
} H[15];

void loadHeroImages(){

	H[0].image = iLoadImage("Images\\Hero\\idle_1.png");
	H[1].image = iLoadImage("Images\\Hero\\idle_2.png");
	H[2].image = iLoadImage("Images\\Hero\\jump_1.png");
	H[3].image = iLoadImage("Images\\Hero\\jump_2.png");
	H[4].image = iLoadImage("Images\\Hero\\jump_3.png");
	H[5].image = iLoadImage("Images\\Hero\\run_left_1.png");
	H[6].image = iLoadImage("Images\\Hero\\run_left_2.png");
	H[7].image = iLoadImage("Images\\Hero\\run_left_3.png");
	H[8].image = iLoadImage("Images\\Hero\\run_left_4.png");
	H[9].image = iLoadImage("Images\\Hero\\run_right_1.png");
	H[10].image = iLoadImage("Images\\Hero\\run_right_2.png");
	H[11].image = iLoadImage("Images\\Hero\\run_right_3.png");
	H[12].image = iLoadImage("Images\\Hero\\run_right_4.png");
	H[13].image = iLoadImage("Images\\Hero\\left_idle_1.png");
	H[14].image = iLoadImage("Images\\Hero\\left_idle_2.png");
}


int ctrlvl3 = 0;
int ctrlvl2 = 0;
int ctrlvl1 = 0;
int ctrlvl4 = 0;

void showHero(int lvl)
{
	// load image
	if (lvl == 1)
	{
		iShowImage(heroX, heroY, heroHeight, heroWidth, H[idleFrame].image);
		if (ctrlvl1 == 0)
		{
			heroX = 10;
			heroY = 50;
			groundLevel = 50;

		}
		ctrlvl1 = 1;
	}
	else if (lvl == 2)
	{
		if (ctrlvl2 == 0)
		{
			heroX = 10;
			heroY = 330;
			groundLevel = 50;

		}
		ctrlvl2 = 1;

		iShowImage(heroX, heroY, heroHeight, heroWidth, H[idleFrame].image);
	}
	else if (lvl == 3)
	{
		if (ctrlvl3 == 0)
		{
			heroX = 30;
			heroY = 480;
			groundLevel = 50;
			

		}
		ctrlvl3 = 1;

		iShowImage(heroX, heroY, heroHeight, heroWidth, H[idleFrame].image);

	}
	else if (lvl == 4)
	{
		if (ctrlvl4 == 0)
		{
			heroX = 190;
			heroY = 500;
			groundLevel = 50;


		}
		ctrlvl4 = 1;

		iShowImage(heroX, heroY, heroHeight, heroWidth, H[idleFrame].image);

	}



}

int ck = 0;
int checker = 0;

void Movement()
{
	//---------------------------Jumping movement-------------------------------------//

	if (isJumping) {
		jumpAnimSpeed++;
		if (jumpAnimSpeed == 0)
		{
			idleFrame = 2;
		}
		else if (jumpAnimSpeed == 1)
		{
			idleFrame = 3;
		}
		else if (jumpAnimSpeed == 2)
		{
			idleFrame = 4;
		}
		heroY += jumpSpeed;
		jumpSpeed -= gravity;

		heroX += velocityX;

		if (heroY <= groundLevel) {
			heroY = groundLevel;
			isJumping = false;
			jumpSpeed = 0;
			idleFrame = 0;
			jumpAnimSpeed = 0;
		}
	}

	//----------------------------Left Right movement----------------------------------//

	if (rightPressed && !leftPressed) {
		ctrR++;
		rightAnimSpeed++;
		if (rightAnimSpeed == 0)
		{
			idleFrame = 9;
		}
		if (rightAnimSpeed == 5)
		{
			idleFrame = 10;
		}

		if (rightAnimSpeed == 10)
		{
			idleFrame = 9;
			rightAnimSpeed = 0;
			currentDir = 1;
		}

		velocityX += acceleration;
		if (velocityX > maxSpeed)
			velocityX = maxSpeed;

		if (ctrR == 10)
		{
			rightPressed = false;
			ctrR = 0;
		}
	}
	else if (leftPressed && !rightPressed) {
		ctrL++;

		leftAnimSpeed++;
		if (leftAnimSpeed == 0)
		{
			idleFrame = 5;
		}
		if (leftAnimSpeed == 5)
		{
			idleFrame = 6;
		}

		if (leftAnimSpeed == 10)
		{
			idleFrame = 13;
			leftAnimSpeed = 0;
			currentDir = -1;
		}

		velocityX -= acceleration;
		if (velocityX < -maxSpeed)
			velocityX = -maxSpeed;

		if (ctrL == 10)
		{
			leftPressed = false;
			ctrL = 0;
		}
	}
	else {

		if (velocityX > 0) {
			velocityX -= friction;
			if (velocityX < 0)
			{
				velocityX = 0;
			}
		}
		else if (velocityX < 0) {
			velocityX += friction;
			if (velocityX > 0)
			{
				velocityX = 0;
			}
		}
	}


	heroX += velocityX;

	//-----------------------------Falling from platform---------------------//
	if (isFalling == 1)
	{
		heroY -= 5;

		if (heroY <= groundLevel) {
			heroY = groundLevel;
			isJumping = false;
			jumpSpeed = 0;
			isFalling = 0;
		}
	}

	// --------------------- Idle Animation ------------------//
	if (isIdle == 1 && isJumping == false && rightPressed == false && leftPressed == false)
	{
		idleAnimSpeed++;
		if (currentDir == 1){
			if (idleAnimSpeed >= 20)
			{
				idleAnimSpeed = 0;
				if (idleFrame != 1)
				{
					idleFrame = 1;
				}
				else{
					idleFrame = 0;
				}
			}
		}
		else if (currentDir == -1){
			if (idleAnimSpeed >= 20)
			{
				idleAnimSpeed = 0;
				if (idleFrame != 13)
				{
					idleFrame = 13;
				}
				else{
					idleFrame = 14;
				}
			}
		}
	}
}




#endif