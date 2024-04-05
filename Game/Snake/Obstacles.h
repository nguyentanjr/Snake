#ifndef _OBSTACLES__H
#define _OBSTACLES__H
#include<SDL.h>
#include "Snake.h"
const int obstacles_length = 25;
const int obstacles_quantity = 20;



class Obstacles {
public:
	void renderObstacles(SDL_Renderer* renderer, std::vector<std::pair<int, int>> obstacles_level);
	std::vector<std::pair<int, int>> obstacles_easy = { {4,4},{5,4},{6,4},{17,4},{18,4},{ 19,4 } };
	std::vector<std::pair<int, int>> obstacles_medium;
	std::vector<std::pair<int, int>> obstacles_hard;
	//void renderObstacles(SDL_Renderer* renderer);
private:
	int obstacles_size;
};




#endif