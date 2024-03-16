#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Snake.h"
#include "Game.h"
Uint32 frameStart;
int frameTime;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
Game game = {};
int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		if (window != NULL) {
			std::cout << "Window created!";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != NULL) {
				std::cout << "Renderer created!";
			}
		}
	}
	while(true)
	game.mainGame(renderer);
	
	//SDL_Delay(100000);
	return 0;
}