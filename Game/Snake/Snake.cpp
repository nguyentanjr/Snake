#include "Snake.h"
#include<SDL.h>
#include<SDL_image.h>



void Snake::snakeMove() {
	pos_head.x += velocity.X;
	pos_head.y += velocity.Y;
}	

void Snake::drawHead(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/snake_head.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 10 * pos_head.x;
	desrect.y = 10 * pos_head.y;
	desrect.h = 15;
	desrect.w = 15;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
}

void Snake::turnUp() {
	velocity.X = 0;
	velocity.Y = -1;
}
void Snake::turnDown() {
	velocity.X = 0;
	velocity.Y = 1;
}
void Snake::turnRight() {
	velocity.X = 1;
	velocity.Y = 0;
}
void Snake::turnLeft() {
	velocity.X = -1;
	velocity.Y = 0;
}

void Snake::draw(SDL_Renderer* renderer, Snake& snake) {
	snake.drawHead(renderer);
}