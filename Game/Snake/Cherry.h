#ifndef _Cherry__H
#define _Cherry__H
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
class Cherry {
public:
	void randomCherry();
	void printCherry(SDL_Renderer* renderer);
	int cherryPosX;
	int cherryPosY;
private:
	int cherrySize = 20;
	int random_numberX;
	int random_numberY;
};








#endif