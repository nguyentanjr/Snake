#include"Sound.h"

void Sound::playMusic(std::string path) {
	Mix_Music* sound;
	sound = Mix_LoadMUS(path.c_str());
	Mix_PlayMusic(sound, -1);
}

void Sound::playSound(std::string path) {
	Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
	Mix_PlayChannel(-1, chunk, 0);
}

void Sound::freeSoundBefore() {
	Mix_HaltMusic();

}