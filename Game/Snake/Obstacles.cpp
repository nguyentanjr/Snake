#include "Obstacles.h"
#include<SDL.h>
#include<iostream>
#include<vector>
#include "Snake.h"



void Obstacles::renderObstacles(SDL_Renderer* renderer,std::vector<std::pair<int,int>> obstacles_level) {
	SDL_Surface* tmpSurface = IMG_Load("assets/obstacle.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	for (int i = 0; i < obstacles_level.size(); i++) {
		SDL_Rect desrect = { obstacles_level[i].first * 25 ,obstacles_level[i].second * 25 ,25,25 };
		SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	}
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}


