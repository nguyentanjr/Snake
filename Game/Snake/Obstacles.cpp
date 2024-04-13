#include "Obstacles.h"
#include<SDL.h>
#include<iostream>
#include<vector>
#include "Snake.h"

void Obstacles::renderObstacles(SDL_Renderer* renderer,int obs) {
	SDL_Surface* tmpSurface = IMG_Load("assets/obstacle2.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	if (obs == 1)obstacles_level = obstacles_easy;
	else if (obs == 2)obstacles_level = obstacles_medium;
	else obstacles_level = obstacles_hard;

	for (int i = 0; i < obstacles_level.size(); i++) {
		SDL_Rect desrect = { obstacles_level[i].first * 25 ,obstacles_level[i].second * 25 ,25,25 };
		SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	}
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Obstacles::createObstacles() {
	for (int i = 2; i < 11; i++) {
		obstacles_medium.push_back(std::make_pair(6,i));
		obstacles_medium.push_back(std::make_pair(6, 25-i));
		obstacles_medium.push_back(std::make_pair(12, i));
		obstacles_medium.push_back(std::make_pair(12, 25-i));
		obstacles_medium.push_back(std::make_pair(18, i));
		obstacles_medium.push_back(std::make_pair(18, 25 - i));


	}
	for (int i = 1; i < 24; i+=4) {
		for (int j = 2; j < 24; j+=4) {
			obstacles_hard.push_back(std::make_pair(i,j));
		}
	}
}
