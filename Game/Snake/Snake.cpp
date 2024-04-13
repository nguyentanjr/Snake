#include "Snake.h"
#include<SDL.h>
#include<SDL_image.h>
#include "Game.h"
#include"Obstacles.h"	

void Snake::snakeMove() {
	pos_head.x += velocity.X;
	pos_head.y += velocity.Y;
}

void Snake::renderAngle(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int w, int h, int angle) {
	SDL_Rect dstRect = { x, y, w, h };
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
}

//snake_storage();
void Snake::drawHead(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/snake_head1.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 25 * pos_head.x;
	desrect.y = 25 * pos_head.y;
	desrect.h = snakeWidth;
	desrect.w = snakeHeight;
	renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, headAngle);
	changeDirection = 0;
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Snake::turnUp() {
	changeDirection = 1;
	if (velocity.Y != 1 && tmp != 0) {
		velocity.X = 0;
		velocity.Y = -1;
		headAngle = -90;
		checkDirection[tailNearHead % 10000] = 1;
		checkCorner[tailNearHead % 10000] = 1;
	}

}

void Snake::turnDown() {
	changeDirection = 1;
	if (velocity.Y != -1 && tmp != 0) {
		velocity.X = 0;
		velocity.Y = 1;
		headAngle = 90;
		checkDirection[tailNearHead % 10000] = 1;
		checkCorner[tailNearHead % 10000] = 2;
	}
}

void Snake::turnRight() {
	changeDirection = 1;
	if (velocity.X != -1 && tmp != 0) {
		velocity.X = 1;
		velocity.Y = 0;
		headAngle = 0;
		checkDirection[tailNearHead % 10000] = 3;
		checkCorner[tailNearHead % 10000] = 3;
	}
}

void Snake::turnLeft() {
	changeDirection = 1;
	if (velocity.X != 1 && tmp != 0) {
		velocity.X = -1;
		velocity.Y = 0;
		headAngle = 180;
		checkDirection[tailNearHead % 10000] = 4;
		checkCorner[tailNearHead % 10000] = 4;
	}
}

void Snake::drawTail(SDL_Renderer* renderer) {
	if (tmp == 0)tail_size = 0;
	SDL_Rect desrect;
	for (int i = 1; i < tail_size; i++) {
		//std::cout << i << " ";
		pos tail_pos = tail[(tailEnd + i) % 10000];
		SDL_Surface* tmpSurface = IMG_Load("assets/snakee.png");
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		desrect.x = tail_pos.x * 25;
		desrect.y = tail_pos.y * 25;
		desrect.h = snakeHeight;
		desrect.w = snakeWidth;
		if (checkDirection[(tailEnd + i) % 10000] == 1) 
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 90);																		
		else
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 0);
		SDL_DestroyTexture(tmpTexture);
		SDL_FreeSurface(tmpSurface);

	}
	if(tail_size > 0)
	for (int i = 0; i < 1; i++) {
		pos tail_pos = tail[(tailEnd + i) % 10000];
		SDL_Surface* tmpSurface = IMG_Load("assets/tail.png");
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		desrect.x = tail_pos.x * 25;
		desrect.y = tail_pos.y * 25;
		desrect.h = 25;
		desrect.w = snakeHeight;
		//tailHandle
		if (checkDirection[(tailEnd + i) % 10000] == 2 && (tail[(tailEnd + i + 1) % 10000].x < tail[(tailEnd + i) % 10000].x))
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 180);
		else if (checkDirection[(tailEnd + i) % 10000] == 2 && (tail[(tailEnd + i + 1) % 10000].x > tail[(tailEnd + i) % 10000].x))
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 0);
		else if (checkDirection[(tailEnd + i) % 10000] == 1 && (tail[(tailEnd + i + 1) % 10000].y > tail[(tailEnd + i) % 10000].y))
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, 90);
		else if (checkDirection[(tailEnd + i) % 10000] == 1 && (tail[(tailEnd + i + 1) % 10000].y < tail[(tailEnd + i) % 10000].y))
			renderAngle(renderer, tmpTexture, desrect.x, desrect.y, desrect.w, desrect.h, -90);
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