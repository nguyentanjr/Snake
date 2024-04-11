#include"Game.h"
#include"Snake.h"
#include"Cherry.h"
#include"Obstacles.h"
#include"Image.h"
#include"Backround.h"
Snake snake = {};
Cherry cherry = {};
Obstacles obstacles = {};
Image image = {};
Game game = {};
Background background = {};
void Snake::snakeEatCherry(Cherry &cherry,SDL_Renderer* renderer) {
	tailNearHead++;
	tailEnd++;
	tail[tailNearHead % 10000] = pos_head;
	if (cherry.cherryPosX == pos_head.x * 25 && cherry.cherryPosY == pos_head.y * 25) {
		cherry.randomCherry();
		tailEnd--;
		tail_size++;
		game.checkDelay = false;
	}

}
void Game::mainGame(SDL_Renderer* renderer) {
	background.loadBackground(renderer);
	background.drawCell(renderer);
	obstacles.renderObstacles(renderer, obstacles.obs);
	cherry.cherryObs = obstacles.obstacles_level;
	snake.snakeObs = obstacles.obstacles_level;
	snake.snakeMove(); 
	if (snake.tail_size % 10 == 0 && snake.tail_size != 0 && checkDelay == false) {
		delay -= 3;
		checkDelay = true;
	}
	std::cout << delay << std::endl;
	SDL_Delay(delay);
	snake.drawHead(renderer);
	snake.outOfWindow();
	snake.snakeEatCherry(cherry,renderer);
	cherry.printCherry(renderer);
	snake.drawTail(renderer);
	//again = false;
	if (snake.tailCollision() == true) {
		snake.tmp = 0;
		snake.velocity.X = 0;
		snake.velocity.Y = 0;
		again = true;
		while (again) {
			image.playAgainIMG(renderer);
			image.returnToMenu(renderer);
			SDL_RenderPresent(renderer);
			while (SDL_PollEvent(&dieEvent)) {
				if (dieEvent.type == SDL_QUIT) {
					again = false;
					gameRunning = false;
					isRunning = false;
					SDL_Quit();
				}
				if (dieEvent.type == SDL_MOUSEBUTTONDOWN) {
					int dieX = dieEvent.button.x;
					int dieY = dieEvent.button.y;
					if (dieX >= 40 && dieX <= 220 && dieY >= 280 && dieY <= 320)
					{
						again = false;
						game.playAgain();
						game.mainGame(renderer);
					}
					if (dieX >= 360 && dieX <= 540 && dieY >= 280 && dieY <= 320)
					{
						again = false;
						game.playAgain();
						game.runningGame(renderer);
						//SDL_Quit();
					}
				}
			}
		}
	}
	while (SDL_PollEvent(&gameEvent)) {
		if (gameEvent.type == SDL_QUIT) {
			isRunning = false;
			gameRunning = false;
			SDL_Quit();
		}
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


void Game::runningGame(SDL_Renderer* renderer) {
	obstacles.createObstacles();
	while (isRunning == true) {
		image.showMenu(renderer);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&mainEvent)) {
			if (mainEvent.type == SDL_QUIT)isRunning = false;
			if (mainEvent.type == SDL_MOUSEBUTTONDOWN) {
				int posX = mainEvent.button.x;
				int posY = mainEvent.button.y;
				if (posX >= 85 && posX <= 269 && posY >= 419 && posY <= 461) {
					isRunning = true;
					levelRunning = true;
					while (levelRunning == true) {
						image.chooseLevel(renderer);	
						SDL_RenderPresent(renderer);
						while (SDL_PollEvent(&levelEvent)) {
							if (levelEvent.type == SDL_QUIT) {
								isRunning = false;
								levelRunning = false;
							}
							if (levelEvent.type == SDL_MOUSEBUTTONDOWN) {
								int levelX = levelEvent.button.x;
								int levelY = levelEvent.button.y;
								if (levelX >= 102 && levelX <= 498 && levelY >= 117 && levelY <= 176) {
									gameRunning = true;
									obstacles.obs = 1;
									while (gameRunning == true) {
										game.mainGame(renderer);
									}
								}
								else if (levelX >= 102 && levelX <= 498 && levelY >= 246 && levelY <= 305) {
									gameRunning = true;
									obstacles.obs = 2;
									while (gameRunning == true) {
										game.mainGame(renderer);
									}
								}
								else if (levelX >= 102 && levelX <= 498 && levelY >= 375 && levelY <= 434) {
									gameRunning = true;
									obstacles.obs = 3;
									while (gameRunning == true) {
										game.mainGame(renderer);
									}
								}
								else if (levelX >= 202 && levelX <= 398 && levelY >= 518 && levelY <= 562) {
									levelRunning = false;
									std::cout << -1;
								}
							}
						}
					}
				}
				else if (posX >= 334 && posX <= 518 && posY >= 419 && posY <= 461) {
					 insRunning = true;
					while (insRunning == true) {
						image.showInstruction(renderer);
						SDL_RenderPresent(renderer);
						while (SDL_PollEvent(&insEvent)) {
							if (insEvent.type == SDL_QUIT) {
								insRunning = false;
								isRunning = false;
							}
							if (insEvent.type == SDL_MOUSEBUTTONDOWN) {
								int insX = insEvent.button.x;
								int insY = insEvent.button.y;
								if (insX >= 202 && insX <= 398 && insY >= 533 && insY <= 578) {
									insRunning = false;
								}
							}
						}
					}
				}
				else if (posX >= 207 && posX <= 391 && posY >= 498 && posY <= 540)isRunning = false;
			}
			
		}
		
	}
	SDL_RenderClear(renderer);

}

void Game::playAgain() {
	gameRunning = true;
	isRunning = true;
	snake.tmp = 1;
	snake.tail_size = 0;
	snake.tailEnd = 0;
	snake.tailNearHead = 0;
	memset(snake.tail, 0, sizeof(snake.tail));
	snake.pos_head.x = 0;
	snake.pos_head.y = 12;
	snake.velocity.X = 1;
	snake.velocity.Y = 0;
	delay = 70;
}




