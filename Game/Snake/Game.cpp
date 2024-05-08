#include"Game.h"
#include <chrono>
#include <thread>
Cherry cherry = {};
Snake snake = {};
Obstacles obstacles = {};
void Game::loadSound() {
	eat.loadSound("assets/sound/eatCherry.wav");
	click.loadSound("assets/sound/click.wav");
	crash.loadSound("assets/sound/hitCollision.wav");
}
void Game::mainGame(SDL_Renderer* renderer) {
	background.loadImage(renderer, "assets/images/background.jpg", 0, 50);
	scoreboard.loadImageWithSize(renderer, "assets/images/scoreboard.png", 0, 0,600,50);
	if(snake.pause == true)
		pauseButton.loadImageWithSize(renderer, "assets/images/pause.png", 4, 5, 40, 40);
	else
		playButton.loadImageWithSize(renderer, "assets/images/pausen't.png", 4, 5, 40, 40);
	obstacles.renderObstacles(renderer, obstacles.level);
	cherry.getObstaclesLevel = obstacles.obstacles_level;
	snake.getObstaclesLevel = obstacles.obstacles_level;
	renderText(renderer, 70, 8, "Level:");
	if (obstacles.level == "easy") {
		level = "Easy";
	}
	else if (obstacles.level == "medium") {
		level = "Med";
	}
	else level = "Hard";
	renderText(renderer, 143, 8, level);
	renderText(renderer, 260, 8, "Score:");
	renderNumber(renderer, 353, 8, snake.tail_size);
	renderText(renderer, 445, 8, "Dead:");
	renderNumber(renderer, 521, 8, dead);
	snake.Move();
	snake.goOutOfWindow();
	cherry.printCherry(renderer);
	if (snake.eatCherry(cherry, renderer)) {
		checkDelay = false;
		eat.playSound();
	}
	snake.drawTail(renderer);
	snake.drawHead(renderer);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	//every 10 points
	if (snake.tail_size % 10 == 0 && snake.tail_size != 0 && checkDelay == false && delay > 0) {
		delay -= 3;
		checkDelay = true;
	}
	if (snake.tailCollision() == true) {
		crash.playSound();
		dead++;
		snake.stopMoving();
		again = true;
		while (again) {	
			if (tip == false) {
				playAgain.loadImage(renderer, "assets/images/playagain.png", HEIGHT / 15, (WIDTH / 2) - (40 / 2));
				returnMenu.loadImage(renderer, "assets/images/returntomenu.png", HEIGHT / 15 + 320, (WIDTH / 2) - (40 / 2));
				renderTip.loadImage(renderer, "assets/images/tip.png", 200, 200);
			}
			SDL_RenderPresent(renderer);
			while (SDL_PollEvent(&deadEvent)) {
				if (deadEvent.type == SDL_QUIT) {
					again = false;
					gameRunning = false;
					isRunning = false;
					SDL_Quit();
				}
				if (deadEvent.type == SDL_MOUSEBUTTONDOWN) {
					int deadX = deadEvent.button.x;
					int deadY = deadEvent.button.y;
					//play again
					if (deadX >= 40 && deadX <= 220 && deadY >= 280 && deadY <= 320)
					{
						again = false;
						click.playSound();
						reset();
						mainGame(renderer);
					}
					//back to menu
					if (deadX >= 360 && deadX <= 540 && deadY >= 280 && deadY <= 320)
					{
						again = false;
						dead = 0;
						click.playSound();
						reset();
						runningGame(renderer);
					}
					if (deadX >= 200 && deadX <= 380 && deadY >= 200 && deadY <= 240) {
						tip = true;
							click.playSound();
							TipIMG.loadImage(renderer, "assets/images/tipIMG.png", 0, 0);
							backButton.loadImageWithSize(renderer, "assets/images/back.png", 0, 0, 50, 50);
							SDL_RenderPresent(renderer);
						SDL_Event backEvent;
						while (tip == true) {				
							while (SDL_PollEvent(&backEvent)) {
								if (backEvent.type == SDL_QUIT) {
									SDL_Quit();
								}
								if (backEvent.type == SDL_MOUSEBUTTONDOWN) {
									int backX = backEvent.button.x;
									int backY = backEvent.button.y;
									if (backX >= 0 && backX <= 50 && backY >= 0 && backY <= 50) {
										renderAfterClickBackButton(renderer);
									}
								}
							}
						}
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
				break;
			case SDLK_p:
				if (snake.pause == false)
				snake.trick = true;
				break;
			case SDLK_c:
				if(snake.pause == false)
				snake.trick = false;
				break;
			case SDLK_ESCAPE:
				if(snake.trick == false)
				if (checkESC == false) {
					snake.pause = !snake.pause;
				}
				else {
					checkESC = false;
				}
				break;
			}
		}
	}
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void Game::renderAfterClickBackButton(SDL_Renderer* renderer) {
	click.playSound();
	tip = false;
	SDL_RenderClear(renderer);
	background.loadImage(renderer, "assets/images/background.jpg", 0, 50);
	scoreboard.loadImageWithSize(renderer, "assets/images/scoreboard.png", 0, 0, 600, 50);
	pauseButton.loadImageWithSize(renderer, "assets/images/pause.png", 4, 5, 40, 40);
	obstacles.renderObstacles(renderer, obstacles.level);
	renderText(renderer, 70, 8, "Level:");
	renderText(renderer, 143, 8, level);
	renderText(renderer, 260, 8, "Score:");
	renderNumber(renderer, 353, 8, snake.tail_size);
	renderText(renderer, 445, 8, "Dead:");
	renderNumber(renderer, 521, 8, dead);
	cherry.printCherry(renderer);
	snake.drawHead(renderer);
	snake.drawTail(renderer);
	SDL_RenderPresent(renderer);
}

void Game::runningGame(SDL_Renderer* renderer) {
	obstacles.createObstacles();
	crash.playMusic("assets/sound/menuMusic.ogg");
	while (isRunning == true) {
		menu.loadImage(renderer, "assets/images/menu.png", 0, 0);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&mainEvent)) {
			if (mainEvent.type == SDL_QUIT)isRunning = false;
			if (mainEvent.type == SDL_MOUSEBUTTONDOWN) {
				int posX = mainEvent.button.x;
				int posY = mainEvent.button.y;
				//level
				if (posX >= 85 && posX <= 269 && posY >= 419 && posY <= 461) {
					isRunning = true;
					levelRunning = true;
					crash.stopMusic();
					click.playSound();
					while (levelRunning == true) {
						chooseLevel.loadImage(renderer, "assets/images/level.png", 0, 0);
						SDL_RenderPresent(renderer);
						while (SDL_PollEvent(&levelEvent)) {
							if (levelEvent.type == SDL_QUIT) {
								isRunning = false;
								levelRunning = false;
							}
							if (levelEvent.type == SDL_MOUSEBUTTONDOWN) {
								int levelX = levelEvent.button.x;
								int levelY = levelEvent.button.y;
								//easy
								if (levelX >= 102 && levelX <= 498 && levelY >= 117 && levelY <= 176) {
									click.playSound();
									crash.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "easy";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//medium
								else if (levelX >= 102 && levelX <= 498 && levelY >= 246 && levelY <= 305) {
									click.playSound();
									crash.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "medium";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//hard
								else if (levelX >= 102 && levelX <= 498 && levelY >= 375 && levelY <= 434) {
									click.playSound();
									crash.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "hard";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//quit
								else if (levelX >= 202 && levelX <= 398 && levelY >= 518 && levelY <= 562) {
									click.playSound();
									levelRunning = false;
								}
							}
						}
					}
				}
				//instruction
				else if (posX >= 334 && posX <= 518 && posY >= 419 && posY <= 461) {
					insRunning = true;
					click.playSound();
					while (insRunning == true) {
						instruction.loadImage(renderer, "assets/images/instruction.png", 0, 0);
						SDL_RenderPresent(renderer);
						while (SDL_PollEvent(&insEvent)) {
							if (insEvent.type == SDL_QUIT) {
								insRunning = false;
								isRunning = false;
							}
							if (insEvent.type == SDL_MOUSEBUTTONDOWN) {
								int insX = insEvent.button.x;
								int insY = insEvent.button.y;
								//back to menu
								if (insX >= 202 && insX <= 398 && insY >= 533 && insY <= 578) {
									click.playSound();
									insRunning = false;
								}
							}
						}
					}
				}
				//quit
				else if (posX >= 207 && posX <= 391 && posY >= 498 && posY <= 540) {
					click.playSound();
					isRunning = false;
					SDL_Quit();
				}
			}
		}
	}
	SDL_RenderClear(renderer);

}

void Game::renderNumber(SDL_Renderer* renderer, int x, int y, int var) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("font2.ttf", 27);
	SDL_Color color = { 0, 0, 0 };
	std::string text;
	std::stringstream value;
	value << var;
	text = value.str();
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void Game::renderText(SDL_Renderer* renderer, int x, int y, std::string text) {
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("font2.ttf", 27);
	SDL_Color color = { 0, 0, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_Rect dstRect = { x, y, textSurface->w, textSurface->h };
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
}

void Game::reset() {
	gameRunning = true;
	isRunning = true;
	snake.tail_size = 0;
	snake.lastTail = 0;
	snake.firstTail = 0;
	snake.headAngle = 0;
	snake.checkDuplicateDirectionDown = 0;
	snake.checkDuplicateDirectionUp = 0;
	snake.checkDuplicateDirectionLeft = 0;
	cherry.random_numberX = 12;
	cherry.random_numberY = 12;
	memset(snake.tail, 0, sizeof(snake.tail));
	memset(snake.checkDirection, 0, sizeof(snake.checkDirection));
	memset(snake.checkCorner, 0, sizeof(snake.checkCorner));
	snake.pos_head.x = 0;
	snake.pos_head.y = 12;
	snake.velocity.X = 1;
	snake.velocity.Y = 0;
	delay = 33;

}




