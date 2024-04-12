#include "Snake.h"
#include<SDL.h>
#include<SDL_image.h>
#include "Game.h"
#include"Obstacles.h"	

void Snake::snakeMove() {
	pos_head.x += velocity.X;
	pos_head.y += velocity.Y;
}	

//snake_storage();
void Snake::drawHead(SDL_Renderer* renderer	) {
	SDL_Surface* tmpSurface = IMG_Load("assets/snake_head.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 25 * pos_head.x;
	desrect.y = 25 * pos_head.y;
	desrect.h = snakeWidth;
	desrect.w = snakeHeight;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Snake::drawTail(SDL_Renderer* renderer) {
	if (tmp == 0)tail_size = 0;
	SDL_Rect desrect;
	for (int i = 0; i < tail_size; i++) {
		//std::cout << i << " ";
		pos tail_pos = tail[(tailEnd + i) % 10000];
		SDL_Surface* tmpSurface = IMG_Load("assets/snake_horizontal.png");
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		desrect.x = tail_pos.x * 25;
		desrect.y = tail_pos.y * 25;
		desrect.h = snakeWidth;
		desrect.w = snakeHeight;
		SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
		SDL_DestroyTexture(tmpTexture);
		SDL_FreeSurface(tmpSurface);
	}
	
	
}

bool Snake::tailCollision() {
	for (int i = 0; i < tail_size; i++) {
		pos tail_pos = tail[(tailEnd + i) % 10000];
		if (pos_head.x == tail_pos.x && pos_head.y == tail_pos.y) {
			return true;
		}
	}
	for (int j = 0; j < snakeObs.size(); j++) {
		if (pos_head.x == snakeObs[j].first && pos_head.y == snakeObs[j].second) {
			return true;
		}
	}
	return false;
}
void Snake::turnUp() {
	SDL_Delay(1);
	if (velocity.Y != 1 && tmp != 0) {
		velocity.X = 0;
		velocity.Y = -1;
	}
	direction = 1;
}
void Snake::turnDown() {
	if (velocity.Y != -1 && tmp != 0 ) {
		velocity.X = 0;
		velocity.Y = 1;
	}
	direction = 1;
}
void Snake::turnRight() {
	if (velocity.X != -1 && tmp != 0) {
		velocity.X = 1;
		velocity.Y = 0;
	}
	direction = 0;
}
void Snake::turnLeft() {
	if (velocity.X != 1 && tmp != 0) {
		velocity.X = -1;
		velocity.Y = 0;
	}
	direction = 0;
}

void Snake::outOfWindow() {
	if (pos_head.x < 0)pos_head.x = (WIDTH / 25) - 1;
	if (pos_head.x >= WIDTH / 25)pos_head.x = 0;
	if (pos_head.y < 2)pos_head.y = (HEIGHT / 25)-1;
	if (pos_head.y >= HEIGHT / 25)pos_head.y = 2;
}


void Snake::draw(SDL_Renderer* renderer, Snake& snake) {
	//if (tail_size > 0)
		snake.drawTail(renderer);
}