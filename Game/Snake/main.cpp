#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Snake.h"
#include "Game.h"
#include "Obstacles.h"
Uint32 frameStart;
int frameTime;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
Obstacles obstacles1 = {};
Snake snake1 = {};
int main(int argc, char* argv[]) {
	Game game = {};
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
	//SDL_Surface* tmpSurface = IMG_Load("assets/obstacle.png");
	//SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	game.runningGame(renderer);
	return 0;
}