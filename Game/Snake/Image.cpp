#include"Image.h"
#include"Game.h"

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

void Image::playAgainIMG(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/playagain.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = WIDTH / 15;
	desrect.y = (HEIGHT / 2) - (tmpSurface->h / 2);
	desrect.w = tmpSurface->w;
	desrect.h = tmpSurface->h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::returnToMenu(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/returntomenu.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = HEIGHT / 15 + 320;
	desrect.y = (WIDTH / 2) - (tmpSurface->h / 2);
	desrect.w = tmpSurface->w;
	desrect.h = tmpSurface->h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::renderTip(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/tip.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 200;
	desrect.y = 200;
	desrect.w = tmpSurface->w;
	desrect.h = tmpSurface->h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::renderTipIMG(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/tipIMG.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 0;
	desrect.y = 0;
	desrect.w = tmpSurface->w;
	desrect.h = tmpSurface->h;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

void Image::renderBackButton(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/back.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 0;
	desrect.y = 0;
	desrect.w = 50;
	desrect.h = 50;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}
void Image::renderIcon(SDL_Renderer* renderer) {
	SDL_Surface* tmpSurface = IMG_Load("assets/icon.png");
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_Rect desrect;
	desrect.x = 0;
	desrect.y = 0;
	desrect.w = 50;
	desrect.h = 50;
	SDL_RenderCopy(renderer, tmpTexture, NULL, &desrect);
	SDL_DestroyTexture(tmpTexture);
	SDL_FreeSurface(tmpSurface);
}

