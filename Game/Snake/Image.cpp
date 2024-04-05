#include"Image.h"

void Image::showMenu(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/menu.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect = { 0,0,600,600 };
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}


void Image::showInstruction(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/instruction.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect = { 0,0,600,600 };
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::chooseLevel(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/level.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect = { 0,0,600,600 };
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}
