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
#include <chrono>
#include "Backround.h"
#include "Image.h"
#include "Snake.h"
#include "Obstacles.h"
#include "Sound.h"
using namespace std::chrono;

class Game {
public:
	void mainGame(SDL_Renderer* renderer);
	void runningGame(SDL_Renderer* renderer);
	void reset();
	void renderNumber(SDL_Renderer* renderer, int x, int y, int var);
	void renderText(SDL_Renderer* renderer, int x, int y, std::string text);
	void renderAfterClickBackButton(SDL_Renderer* renderer);
	bool checkDelay = false;
	bool isRunning = true;
	void loadSound();
private:	
	Image background = {};
	Image scoreboard = {};
	Image icon = {};
	Image playAgain = {};
	Image returnMenu = {};
	Image renderTip = {};
	Image backButton = {};
	Image TipIMG = {};
	Image menu = {};
	Image chooseLevel = {};
	Image instruction = {};
	Image pauseButton = {};
	Image playButton = {};
	Sound crash = {};
	Sound click = {};
	Sound eat = {};
	//Obstacles obstacles = {};
	//Cherry cherrryGame = {};
	SDL_Event gameEvent;
	SDL_Event mainEvent;
	SDL_Event insEvent;
	SDL_Event levelEvent;
	SDL_Event deadEvent;
	bool gameRunning = true;
	bool insRunning = true;
	bool levelRunning = true;
	int dead = 0;
	bool again = false;
	bool gameContinue = false;
	int delay = 33;
	std::string level;
	bool tip = false;
	bool checkESC = false;
};
#endif