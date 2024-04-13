#ifndef _SOUND__H
#define _SOUND__H
#include <SDL_mixer.h>
#include <SDL.h>
#include<iostream>
class Sound {
public:
	void playMusic(std::string path);
	void playSound(std::string path);
	void freeSoundBefore();

};


#endif