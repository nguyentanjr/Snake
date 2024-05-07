#ifndef _SOUND__H
#define _SOUND__H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include<map>

class Sound {
public:
	void loadSound(std::string path);
	void playMusic(std::string path);
	void playSound();
	void stopMusic();
	void freeMusic();
	Mix_Chunk* sound;
private:
	std::map<std::string, Mix_Chunk*> sounds;
};

#endif 