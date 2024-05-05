#include"Backround.h"

void Background::drawCell(SDL_Renderer* renderer) {
	int res = 0;
	for (int i = 0; i <= 600; i += 25) {
		for (int j = 0; j <= 600; j += 25) {
			SDL_Rect desrect = { i,j,25,25 };
			SDL_SetRenderDrawColor(renderer, 141, 140, 137, 1);
			SDL_RenderDrawRect(renderer, &desrect);
		}
	}

	for (int i = 0; i <= 600; i += 25) {
		for (int j = 0; j <= 25; j += 25) {
			SDL_Rect desrect = { i,j,25,25 };
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(renderer, &desrect);
		}
	}
}