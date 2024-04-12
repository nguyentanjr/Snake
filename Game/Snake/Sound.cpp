#include"Sound.h"

void Sound::playSound(std::string path) {
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_Music* sound;
	sound = Mix_LoadMUS(path.c_str());
	Mix_PlayMusic(sound, -1);
}

void Sound::freeSoundBefore() {
	Mix_HaltMusic();

}