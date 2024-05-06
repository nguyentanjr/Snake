#include "Sound.h"


void Sound::playMusic(std::string path) {
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    Mix_PlayMusic(music, -1);
}

void Sound::playSound(std::string path) {
    Mix_Chunk* sound = Mix_LoadWAV(path.c_str());
    Mix_PlayChannel(-1, sound, 0);
    Mix_FreeChunk(sound);
}

void Sound::stopMusic() {
    Mix_HaltMusic();
}
