#include"Cherry.h"
#include"Snake.h"
void Cherry::randomCherry(int a,int b,int check,SDL_Renderer* renderer) {
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
	//cherryPosX = desrect.x;
	//cherryPosY = desrect.y;
	if (check == 1) {
		SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	}
	else {
		desrect.x = a;
		desrect.y = b;
		SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	}
	
}
