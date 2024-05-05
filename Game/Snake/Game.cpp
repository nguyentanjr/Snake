#include"Game.h"
#include <chrono>
#include <thread>
Cherry cherry = {};
Snake snake = {};
Obstacles obstacles = {};

void Game::mainGame(SDL_Renderer* renderer) {
	std::cout<<delay<<std::endl;
	background.loadImage(renderer, "assets/images/background.jpg", 0, 50);
	scoreboard.loadImageWithSize(renderer, "assets/images/scoreboard.png", 0, 0,600,50);
	//background.drawCell(renderer);
	obstacles.renderObstacles(renderer, obstacles.level);
	cherry.cherryObs = obstacles.obstacles_level;
	snake.snakeObs = obstacles.obstacles_level;
	
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
	if(snake.eatCherry(cherry, renderer))checkDelay = false;
	cherry.printCherry(renderer);
	snake.drawHead(renderer);
	snake.drawTail(renderer);
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	
	//every 10 points
	if (snake.tail_size % 10 == 0 && snake.tail_size != 0 && checkDelay == false && delay > 0) {
		//std::cout << delay << std::endl;
		delay -= 3;
		checkDelay = true;
	}
	//SDL_Delay(delay);
	if (snake.tailCollision() == true) {
		crash.playSound("assets/sound/hitCollision.wav");
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
					//	sound.playSound("assets/sound/click.wav");
						reset();
						mainGame(renderer);
					}
					//back to menu
					if (deadX >= 360 && deadX <= 540 && deadY >= 280 && deadY <= 320)
					{
						again = false;
						dead = 0;
						//sound.playSound("assets/sound/click.wav");
						reset();
						runningGame(renderer);
					}
					if (deadX >= 200 && deadX <= 380 && deadY >= 200 && deadY <= 240) {
						tip = true;
							///sound.playSound("assets/sound/click.wav");
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
				snake.pause = true;
				break;
			case SDLK_c:
				snake.pause = false;
				break;
			}
		}
	}
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void Game::renderAfterClickBackButton(SDL_Renderer* renderer) {
	///sound.playSound("assets/sound/click.wav");
	tip = false;
	SDL_RenderClear(renderer);
	background.loadImage(renderer, "assets/images/background.jpg", 0, 50);
	scoreboard.loadImageWithSize(renderer, "assets/images/scoreboard.png", 0, 0, 600, 50);
	obstacles.renderObstacles(renderer, obstacles.level);
	icon.loadImageWithSize(renderer, "assets/images/icon.png", 0, 0, 50, 50);
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
	//sound.playMusic("assets/sound/menuMusic.ogg");
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
					//sound.freeSoundBefore();
				//	sound.playSound("assets/sound/click.wav");
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
							//	sound.freeSoundBefore();
								//easy
								if (levelX >= 102 && levelX <= 498 && levelY >= 117 && levelY <= 176) {
									//sound.playSound("assets/sound/click.wav");
									//sound.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "easy";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//medium
								else if (levelX >= 102 && levelX <= 498 && levelY >= 246 && levelY <= 305) {
									//sound.playSound("assets/sound/click.wav");
									//sound.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "medium";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//hard
								else if (levelX >= 102 && levelX <= 498 && levelY >= 375 && levelY <= 434) {
									//sound.playSound("assets/sound/click.wav");
									//sound.playMusic("assets/sound/mainGame.ogg");
									gameRunning = true;
									obstacles.level = "hard";
									while (gameRunning == true) {
										mainGame(renderer);
									}
								}
								//quit
								else if (levelX >= 202 && levelX <= 398 && levelY >= 518 && levelY <= 562) {
									//sound.playSound("assets/sound/click.wav");
									levelRunning = false;
								}
							}
						}
					}
				}
				//instruction
				else if (posX >= 334 && posX <= 518 && posY >= 419 && posY <= 461) {
					insRunning = true;
					//sound.playSound("assets/sound/click.wav");
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
									//sound.playSound("assets/sound/click.wav");
									insRunning = false;
								}
							}
						}
					}
				}
				//quit
				else if (posX >= 207 && posX <= 391 && posY >= 498 && posY <= 540) {
					//sound.playSound("assets/sound/click.wav");
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
	//snake.tmp = 1;
	snake.tail_size = 0;
	snake.tailEnd = 0;
	snake.tailNearHead = 0;
	snake.headAngle = 0;
	snake.checkDuplicateDirectionDown = 0;
	snake.checkDuplicateDirectionUp = 0;
	snake.checkDuplicateDirectionLeft = 0;
	memset(snake.tail, 0, sizeof(snake.tail));
	memset(snake.checkDirection, 0, sizeof(snake.checkDirection));
	memset(snake.checkCorner, 0, sizeof(snake.checkCorner));
	snake.pos_head.x = 0;
	snake.pos_head.y = 12;
	snake.velocity.X = 1;
	snake.velocity.Y = 0;
	delay = 43;

}




