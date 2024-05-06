#ifndef _Cherry__H
#define _Cherry__H
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include<vector>
#include "Obstacles.h"
class Cherry {
public:
	void generateCherry();
	void printCherry(SDL_Renderer* renderer);
	std::vector<std::pair<int, int>> getObstaclesLevel;
	int PosX = 12;
	int PosY = 12;
	int random_numberX = 12;
	int random_numberY = 12;
private:
	int cherrySize = 20;
	//Obstacles cherry_Obstacles = {};
};








#endif