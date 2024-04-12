#ifndef _Game__H
#define _Game__H
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <sstream>

const int WIDTH = 600;
const int HEIGHT = 600;


class Game {
public:
	//void randomCherry(SDL_Renderer* renderer);
	void mainGame(SDL_Renderer* renderer);
	void runningGame(SDL_Renderer* renderer);
	void playAgain();
	void renderNumber(SDL_Renderer* renderer, int x, int y,int var);
	void renderText(SDL_Renderer* renderer, int x, int y, std::string text);
	SDL_Event gameEvent;
	SDL_Event mainEvent;
	SDL_Event insEvent;
	SDL_Event levelEvent;
	SDL_Event dieEvent;
	bool isRunning = true;
	bool gameRunning = true;
	bool insRunning = true;
	bool levelRunning = true;
	int die = 0;
	bool again = false;
	bool checkDelay = false;
	int delay = 40;
	std::string level;
private:


};
#endif