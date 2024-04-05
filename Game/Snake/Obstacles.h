#ifndef _OBSTACLES__H
#define _OBSTACLES__H
#include<SDL.h>
#include "Snake.h"
#include<vector>
#include<iostream>
const int obstacles_length = 25;
const int obstacles_quantity = 20;



class Obstacles {
public:
	void renderObstacles(SDL_Renderer* renderer, int obs);
	std::vector<std::pair<int, int>> obstacles_easy = { {4,4},{5,4},{6,4},{7,4},{8,4},{15,4}, { 16,4 },{17,4},{18,4},{19,4},{4,5},{4,6},{4,7},{4,8}, { 19,5 },
														{19,6},{19,7},{19,8},
														{4,21},{5,21},{6,21},{7,21},{8,21},{15,21}, { 16,21 },{17,21},{18,21},{19,21},{4,20},{4,19},{4,18},{4,17}, { 19,20 },
														{19,19},{19,18},{19,17} };
	std::vector<std::pair<int, int>> obstacles_medium;
	std::vector<std::pair<int, int>> obstacles_hard;
	std::vector<std::pair<int, int>> obstacles_level;
	void createObstacles();
	int obs = 1;

private:
	int obstacles_size;
};




#endif