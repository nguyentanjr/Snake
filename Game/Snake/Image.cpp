#include"Image.h"
#include"Game.h"

void Image::loadImage(SDL_Renderer* renderer, const char* path, int x, int y) {
	SDL_Surface* tmpSurface = IMG_Load(path);
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = x;
	desrect.y = y;
	desrect.w = tmpSurface->w;
	desrect.h = tmpSurface->h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::loadImageWithSize(SDL_Renderer* renderer, const char* path, int x, int y, int w, int h) {
	SDL_Surface* tmpSurface = IMG_Load(path);
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = x;
	desrect.y = y;
	desrect.w = w;
	desrect.h = h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

