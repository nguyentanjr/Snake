#include "Snake.h"
#include<SDL.h>
#include<SDL_image.h>
#include "Game.h"


void Snake::snakeMove() {
	pos_head.x += velocity.X;
	pos_head.y += velocity.Y;
}	

void Snake::drawHead(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/snake_head.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 25 * pos_head.x;
	desrect.y = 25 * pos_head.y;
	desrect.h = snakeWidth;
	desrect.w = snakeHeight;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
}

void Snake::turnUp() {
	if (velocity.Y != 1) {
		velocity.X = 0;
		velocity.Y = -1;
	}
}
void Snake::turnDown() {
	if (velocity.Y != -1) {
		velocity.X = 0;
		velocity.Y = 1;
	}
}
void Snake::turnRight() {
	if (velocity.X != -1) {
		velocity.X = 1;
		velocity.Y = 0;
	}
}
void Snake::turnLeft() {
	if (velocity.X != 1) {
		velocity.X = -1;
		velocity.Y = 0;
	}
}

void Snake::outOfWindow() {
	if (pos_head.x < 0)pos_head.x = WIDTH / 25;
	if (pos_head.x > WIDTH / 25)pos_head.x = 0;
	if (pos_head.y < 0)pos_head.y = HEIGHT / 25;
	if (pos_head.y > HEIGHT / 25)pos_head.y = 0;
}


void Snake::draw(SDL_Renderer* renderer, Snake& snake) {
	snake.drawHead(renderer);
}