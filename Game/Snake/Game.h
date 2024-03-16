#ifndef _Game__H
#define _Game__H
const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#include <vector>



class Game {
public:

	void gameRunning();
	void mainGame(SDL_Renderer* renderer);
	SDL_Event gameEvent;
	bool running() {
		return isRunning;
	}
private:
	bool isRunning;
};
#endif