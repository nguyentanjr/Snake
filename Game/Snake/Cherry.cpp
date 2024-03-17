#include"Cherry.h"


void Cherry::randomCherry(SDL_Renderer* renderer) {
	srand(time(NULL));
	SDL_Surface* tmpSurface = IMG_Load("cherry.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	int random_numberX = rand() % 25;
	int random_numberY = rand() % 25;
 	desrect.x = random_numberX * 25;
	desrect.y = random_numberY * 25;
	desrect.w = 20;
	desrect.h = 20;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
}