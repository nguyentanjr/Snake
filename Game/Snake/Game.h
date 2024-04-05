#ifndef _Game__H
#define _Game__H
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

const int WIDTH = 600;
const int HEIGHT = 600;


class Game {
public:
	//void randomCherry(SDL_Renderer* renderer);
	void mainGame(SDL_Renderer* renderer);
	void runningGame(SDL_Renderer* renderer);
	void instruction(SDL_Renderer* renderer);
	void playAgain();
	SDL_Event gameEvent;
	SDL_Event mainEvent;
	SDL_Event insEvent;
	SDL_Event levelEvent;
	bool isRunning = true;
	bool gameRunning = true;
	bool insRunning = true;
	bool levelRunning = true;
	int obs;
private:


};
#endif