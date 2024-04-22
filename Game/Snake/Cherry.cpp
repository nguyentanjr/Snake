#include"Cherry.h"
#include"Snake.h"
#include"Obstacles.h"


void Cherry::randomCherry() {
	srand(time(NULL));
	while(true){
		random_numberX = rand() % 22 + 2;
		random_numberY = rand() % 22 + 2;
		bool check = true;
		for (int i = 0; i < cherryObs.size(); i++) {
			if (random_numberX == cherryObs[i].first && random_numberY == cherryObs[i].second) {
				check = false;
				break;
			}
		}
		if (check == true)break;
	}
	cherryPosX = random_numberX * 25;
	cherryPosY = random_numberY * 25;

}
void Cherry::printCherry(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/cherry.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = random_numberX * 25;
	desrect.y = random_numberY * 25;
	cherryPosX = random_numberX * 25;
	cherryPosY = random_numberY * 25;
	desrect.w = 25;
	desrect.h = 25;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}
