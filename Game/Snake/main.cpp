#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Snake.h"
#include "Game.h"
#include "Obstacles.h"
#include <chrono>

using namespace std::chrono;
Uint32 frameStart;
int frameTime;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int main(int argc, char* argv[]) {
	Game game = {};
	Sound eat = {};
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
		if (window != NULL) {
			std::cout << "Window created!";
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer != NULL) {
				std::cout << "Renderer created!";
			}
		}
	}
	SDL_Surface* iconSurface = IMG_Load("assets/images/icon.png");
	SDL_SetWindowIcon(window, iconSurface);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	while (game.isRunning) {
		frameStart = SDL_GetTicks();
		game.load();
		game.runningGame(renderer);
		frameTime = SDL_GetTicks() - frameStart;
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}
	return 0;
}