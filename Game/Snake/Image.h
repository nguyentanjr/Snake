#ifndef _IMAGE__H
#define _IMAGE__H
#include<SDL.h>
#include<SDL_image.h>
class Image {
public:
	void showMenu(SDL_Renderer* renderer);
	void showInstruction(SDL_Renderer* renderer);
	void exitGame(SDL_Renderer* renderer);
	void chooseLevel(SDL_Renderer* renderer);
};


#endif