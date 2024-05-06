#ifndef _Snake__H
#define _Snake__H

#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>	
#include <iostream>
#include <vector>
#include "Cherry.h"
#include "Game.h"
#include"Obstacles.h"
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
public:
	velo velocity;
	pos tail[10000];
	pos pos_head = { 0,12 };
	int tailNearHead = 0;
	int tailEnd = 0;
	double headAngle = 0;
	int tail_size = 0;
	int checkDirection[10000];
	int checkCorner[10000];
	bool trick = false;
	bool pause = false;
	std::vector<std::pair<int, int>> getObstaclesLevel;
	void stopMoving();
	bool eatCherry(Cherry& cherry, SDL_Renderer* renderer);
	void renderAngle(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h, int angle);
	void goOutOfWindow();
	void drawHead(SDL_Renderer* renderer);
	void drawTail(SDL_Renderer* renderer);
	void renderTail(SDL_Renderer* renderer, SDL_Surface* tmpSurface, SDL_Texture* tmpTexture, std::string path, pos tail_pos);
	bool tailCollision();
	void draw(SDL_Renderer* renderer, Snake& snake);
	void Move();
	void turnRight();
	void turnLeft();
	void turnUp();
	void turnDown();
	int changeDirection = 0;
	int checkDuplicateDirectionUp = 0;
	int checkDuplicateDirectionDown = 0;
	int checkDuplicateDirectionRight = 0;
	int checkDuplicateDirectionLeft = 0;
private:
	int isUpping = 0;
	int isDowning = 0;
	int isGoingRight = 0;
	int	isGoingLeft = 0;
	int tmp = 1;
	bool isRunning;
	//Cherry cherry = {};
//	Obstacles snakeObstacles = {};
};

#endif