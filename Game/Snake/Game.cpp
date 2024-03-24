#include"Game.h"
#include"Snake.h"
#include"Cherry.h"
Snake snake = {};
Cherry cherry = {};

void Snake::snakeEatCherry(Cherry &cherry,SDL_Renderer* renderer) {
	tailNearHead++;
	tailEnd++;
	tail[tailNearHead % 10000] = pos_head;
	if (cherry.cherryPosX == pos_head.x * 25 && cherry.cherryPosY == pos_head.y * 25) {
	//	std::cout << 1 << std::endl;
		cherry.randomCherry();
		tailEnd--;
		tail_size++;
	}

}
void Game::mainGame(SDL_Renderer* renderer) {
	snake.snakeMove();
	SDL_Delay(60);
	snake.drawHead(renderer);
	snake.outOfWindow();
	snake.snakeEatCherry(cherry,renderer);
	cherry.printCherry(renderer);
	snake.drawTail(renderer);
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










