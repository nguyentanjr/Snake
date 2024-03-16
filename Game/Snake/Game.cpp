#include"Game.h"
#include"Snake.h"

Snake snake = {};

void Game::mainGame(SDL_Renderer* renderer) {
	snake.snakeMove();
	SDL_Delay(30);
	snake.draw(renderer,snake);
	while (SDL_PollEvent(&gameEvent)) {
		if (gameEvent.type == SDL_KEYDOWN) {
			switch (gameEvent.key.keysym.sym) {
			case SDLK_UP:
				snake.turnUp();
				break;
			case SDLK_DOWN:
				snake.turnDown();
				break;
			case SDLK_LEFT:
				snake.turnLeft();
				break;
			case SDLK_RIGHT:
				snake.turnRight();
			}
		}
	}
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}










