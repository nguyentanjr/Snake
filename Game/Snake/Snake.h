#ifndef _Snake__H
#define _Snake__H

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

const int snakeWidth = 25;
const int snakeHeight = 25;

struct pos {
	int x;
	int y;
};
struct velo {
	int X = 0;
	int Y = 0;
};


class Snake {

private:
	velo velocity;
	pos pos_head;
	pos tail[1000];
public:
	void outOfWindow();
	void handleEvents(Snake& snake);
	void drawHead(SDL_Renderer* renderer);
	void drawTail(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, Snake& snake);
	void snakeMove();
	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();
};
#endif