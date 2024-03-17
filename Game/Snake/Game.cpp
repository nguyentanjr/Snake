#include"Game.h"
#include"Snake.h"
#include"Cherry.h"
Snake snake = {};
Cherry cherry = {};

void Game::snakeEatCherry(SDL_Renderer* renderer) {

}
void Game::mainGame(SDL_Renderer* renderer) {
	snake.snakeMove();
	SDL_Delay(30);
	snake.draw(renderer,snake);
	snake.outOfWindow();
	cherry.randomCherry(renderer);
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










