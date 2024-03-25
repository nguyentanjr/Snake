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
void drawPixel(int x, int y)
{
	SDL_Rect pixelRect = { x, y, 25, 25 };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &pixelRect);
}
int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow("Pong Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
		if (window != NULL) {
			std::cout << "Window created!";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != NULL) {
				std::cout << "Renderer created!";
			}
		}
	}
	while (game.isRunning == true) {
		std::cout << game.isRunning;
		game.mainGame(renderer);
		SDL_Delay(30);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		for (int x = 0; x < 600; x += 25)
		{
			for (int y = 0; y < 600; y += 25)
			{
				drawPixel(x, y);
			}
		}

	}
	return 0;
}