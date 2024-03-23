#include"Game.h"
#include"Snake.h"
#include"Cherry.h"
Snake snake = {};
Cherry cherry = {};

void Snake::snakeEatCherry(Cherry &cherry,SDL_Renderer* renderer) {
	tailNearHead++;
	tailEnd++;
	tail[tailNearHead] = pos_head;
	if (cherry.cherryPosX == pos_head.x*25 && cherry.cherryPosY == pos_head.y*25) {
		cherry.randomCherry(cherry.cherryPosX, cherry.cherryPosY,1, renderer);
	}
	else {
		cherry.randomCherry(cherry.cherryPosX, cherry.cherryPosY,0, renderer);
	}

}
void Game::mainGame(SDL_Renderer* renderer) {
	snake.snakeMove();
	SDL_Delay(30);
	snake.draw(renderer,snake);
	snake.outOfWindow();
	snake.snakeEatCherry(cherry,renderer);
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










