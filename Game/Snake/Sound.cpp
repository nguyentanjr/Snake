#include "Sound.h"


void Sound::loadSound(std::string path) {
    sound = Mix_LoadWAV(path.c_str());
}

void Sound::playMusic(std::string path) {
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    Mix_PlayMusic(music, -1);
}

void Sound::playSound() {
    Mix_PlayChannel(-1, sound, 0);
}

void Sound::stopMusic() {
    Mix_HaltMusic();
}
