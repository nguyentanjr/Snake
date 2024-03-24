#include"Cherry.h"
#include"Snake.h"
void Cherry::randomCherry() {
	srand(time(NULL));
	random_numberX = rand() % 24;
	random_numberY = rand() % 24;
	cherryPosX = random_numberX * 25;
	cherryPosY = random_numberY * 25;
}
void Cherry::printCherry(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("cherry.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = random_numberX * 25;
	desrect.y = random_numberY * 25;
	desrect.w = 20;
	desrect.h = 20;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
}
