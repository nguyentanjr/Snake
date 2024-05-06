#ifndef _SOUND__H
#define _SOUND__H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

class Sound {
public:
	void playMusic(std::string path);
	void playSound(std::string path);
	void stopMusic();
	void freeMusic();
};

#endif 