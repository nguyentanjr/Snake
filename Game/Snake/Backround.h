#ifndef _BACKGROUND__H
#define _BACKGROUND__H
#include<SDL.h>
#include<SDL_image.h>
class Background {
public:
	void loadBackground(SDL_Renderer* renderer);
	void drawCell(SDL_Renderer* renderer);
};



#endif