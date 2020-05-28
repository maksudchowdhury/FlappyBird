/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/



# include "iGraphics.h"
# include <windows.h>

int mposx,  mposy;
int i;
//p = 964, q = 714, r = 464, u = 214, s = 1000, a = 0, t;
int grounddot[28];
int gameover_flag = 0, flag2 = 1, bird_down_flag = 1,gamestart=1;
int birdx = 250, birdy = 500, brickspeed = 10;
int brickpos[28],pos=28;
int g, b, c, d, e = 950;
int score = 0;
char scr[9];
int callsong = 1,callsong2=1;
int level=0;
char lvl[9], speed_up = 0, birdfall=0;
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{

	//place your drawing codes here
	iClear();
	
	if (gameover_flag != 1 && callsong == 1 && gamestart == 0){
		PlaySound("sources\\themeclip.wav", NULL, SND_LOOP | SND_ASYNC);
		callsong = 0;
	}
	
	if (birdx + 25 ==e && birdy>=b && birdy<=500){
		//printf("collision");
		gameover_flag = 1;
	}
	if (birdx + 25 == e && birdy >= 60 && birdy <= b-100){
		//printf("collision");
		gameover_flag = 1;
	}
	if (flag2 == 1){
		e = 950;
		g = 50, b = 400 - ((rand()) % 100);  // g is the width of the pillars
	}
	flag2 = 0;
	
	if (birdy > 500){
		birdy = 500;
	}
	if (birdy < 71){
		birdy = 71;
	}
	if (e < 0){
		flag2 = 1;

		//c = (rand() % 170);//170 is the minimum distance bitween the bars
	}
	if (e ==250){
		score += 5;
	}
	if (e == 250 && score%20==0){
		level++;
		birdfall += 2;
	}
	if (gamestart==1){
		iShowBMP(0, 0, "sources\\gamestart.bmp");//colorful bg
	}
	if (gameover_flag != 1 && gamestart == 0){
		iShowBMP(0, 0, "sources\\background.bmp");//colorful bg
	}
	if (gameover_flag == 1 && gamestart == 0){
		iShowBMP(0, 0, "sources\\mbackground.bmp");//mono bg
	}
	if (gameover_flag != 1 && gamestart == 0){
		iSetColor(40, 130, 24);// colorful bars
	}
	if (gameover_flag == 1 && gamestart == 0){
		iSetColor(100,100,100);//dark ash bars
	}
	if (gamestart == 0){
		iFilledRectangle(e, b, g, 500 - b);//upper obstacle
		iFilledRectangle(e, 70, g, b - 170);//lower obstacle
	}

	if (gameover_flag != 1 && gamestart == 0){
		iShowBMP(0, 0, "sources\\ground2.bmp");// colorful ground
	}
	if (gameover_flag == 1){
		iShowBMP(0, 0, "sources\\mground2.bmp");//mono ground
	}
	
	if (bird_down_flag == 0 && gamestart == 0){
		iShowBMP2(birdx, birdy, "sources\\up_bird.bmp",0);// bird image dy=40 and dx=40
	}
	if (bird_down_flag == 1 && gameover_flag != 1 && gamestart == 0){
		iShowBMP2(birdx, birdy, "sources\\down_bird.bmp",0);//change to down to see down
	}
	if (bird_down_flag == 1 && gameover_flag == 1 && gamestart == 0){
		iShowBMP2(birdx, birdy, "sources\\mdown_bird.bmp", 0);//change to down to see down
	}
	bird_down_flag = 1;
	if (gameover_flag == 0 && gamestart == 0){
		birdy = birdy - 10-birdfall;
		e = e - 25;
	}
	
	for (i = 0; i < 27 && gameover_flag != 1 && gamestart == 0; i++){
		iShowBMP(brickpos[i], 40, "sources\\ground_dot.bmp");
	}
	for (i = 0; i < 27 && gameover_flag == 1 && gamestart == 0; i++){
		iShowBMP(brickpos[i], 40, "sources\\mground_dot.bmp");// mono groundDot
	}
	for (i = 0; i < 27 && gameover_flag != 1 && gamestart == 0; i++){
		brickpos[i] = brickpos[i] - brickspeed;
	}
	for (i = 0; i < 27 && gameover_flag != 1 && gamestart == 0; i++){
		if (brickpos[i] < 0){
			brickpos[i] = 964;
		}
	}
	if (gamestart == 0){
		_itoa_s(score, scr, 10);
		_itoa_s(level, lvl, 10);
		iSetColor(255, 255, 255);
		iText(930, 480, scr, GLUT_BITMAP_HELVETICA_18);
		iText(880, 460, "LEVEL : ", GLUT_BITMAP_HELVETICA_12);
		iText(930, 460, lvl, GLUT_BITMAP_HELVETICA_18);
	}
	
	if (gameover_flag == 1 && birdy != 70 && gamestart == 0){
		birdy -= 25;
	}
	if (gameover_flag == 1 && callsong2 == 1 && gamestart == 0){
		PlaySound("sources\\gameoverclip.wav", NULL, SND_ASYNC);
		callsong2 = 0;
	}
	if (gameover_flag == 1 && gamestart == 0){
		iShowBMP2(0, 0, "sources\\gover.bmp", 0);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 320 && mx <= 680 && my >= 130 && my <= 210){
			gamestart = 0;
			callsong = 1, callsong2 = 1;
		}
		printf("x=%d  y=%d", mx, my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'r'  && gamestart == 0)
	{
		gameover_flag = 0, flag2 = 1, bird_down_flag = 1;
		birdx = 250, birdy = 500, brickspeed = 10;
		e = 950;
		score = 0;
		callsong = 1, callsong2 = 1;
		level = 0;
		
	}
	if (key == 'p')
	{
		gamestart = 1;
		PlaySound(0,0,0);

	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);

	}
	if (key == GLUT_KEY_UP && gameover_flag != 1 && gamestart == 0)
	{
		bird_down_flag = 0;
		birdy = birdy + 70;
	}
	
	//place your codes for other keys here
}
//
void bricpos()
{
	for (i = 0; i < 27; i++){
		brickpos[i] = pos;
		pos = pos + 36;
	}
}

int main()
{
	//place your own initialization codes here.
	bricpos();
	iInitialize(1000, 500, ".                                                                                                                                 Flappy Bird");
	
	return 0;
}
