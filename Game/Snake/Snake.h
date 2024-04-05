#ifndef _Snake__H
#define _Snake__H

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include "Cherry.h"
#include "Game.h"
const int snakeWidth = 25;
const int snakeHeight = 25;

struct pos {
	int x;
	int y;
};
struct velo {
	int X = 1;
	int Y = 0;
};


class Snake {

private:
	velo velocity;
	pos pos_head;
	pos tail[10000];
	int tailNearHead = 0;
	int tailEnd = 0;
	int tail_size = 0;
	int tmp = 0;
public:
	bool isRunning;
	std::vector<std::pair<int, int>> pos_obstacles;
	void snakeEatCherry(Cherry& cherry,SDL_Renderer* renderer);
	void outOfWindow();
	void handleEvents(Snake& snake);
	void drawHead(SDL_Renderer* renderer);
	void drawTail(SDL_Renderer* renderer);
	bool tailCollision();
	void draw(SDL_Renderer* renderer, Snake& snake);
	void snakeMove();
	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();
};
#endif