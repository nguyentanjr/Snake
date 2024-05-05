#ifndef _IMAGE__H
#define _IMAGE__H
#include<SDL.h>
#include<SDL_image.h>
const int WIDTH = 600;
const int HEIGHT = 600;
class Image {
public:
	void showMenu(SDL_Renderer* renderer);
	void showInstruction(SDL_Renderer* renderer);
	void chooseLevel(SDL_Renderer* renderer);
	void resetIMG(SDL_Renderer* renderer);
	void renderReturnMenu(SDL_Renderer* renderer);
	void renderIcon(SDL_Renderer* renderer);
	void renderTip(SDL_Renderer* renderer);
	void renderTipIMG(SDL_Renderer* renderer);
	void renderBackButton(SDL_Renderer* renderer);
	void loadImage(SDL_Renderer* renderer, const char* path, int x, int y);
	void loadImageWithSize(SDL_Renderer* renderer, const char* path, int x, int y, int w, int h);
};


#endif