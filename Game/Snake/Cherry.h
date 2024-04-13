#ifndef _Cherry__H
#define _Cherry__H
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<vector>
class Cherry {
public:
	void randomCherry();
	void printCherry(SDL_Renderer* renderer);
	int cherryPosX = 12;
	int cherryPosY = 12;
	std::vector<std::pair<int, int>> cherryObs;
private:
	int cherrySize = 20;
	int random_numberX = 12;
	int random_numberY = 12;	
};








#endif