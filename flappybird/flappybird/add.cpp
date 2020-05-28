# include <windows.h>
# include <Mmsystem.h>
# include <iostream>
# include <stdio.h>
int main()
{
	PlaySound("sources\\gameoverclip.wav", NULL, SND_SYNC);
}