#ifndef _Cherry__H
#define _Cherry__H
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
class Cherry {
public:
	void randomCherry(int x,int y,int check,SDL_Renderer* renderer);
	int cherryPosX = 0;
	int cherryPosY = 0;
private:
	int cherrySize = 20;
};








#endif