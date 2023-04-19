#include "Audio.h"

namespace Drizzle2D {
    void InitAudio(int channels) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
            std::cout << "Error Initializing Audio" << std::endl;
        }
        Mix_AllocateChannels(channels);
    }
    Audio::Audio(const std::string& path, int volume)
        : chunk(Mix_LoadWAV(path.c_str()), Mix_FreeChunk) {
        if (!chunk.get()) {
            std::cout << "Couldn't load audio sample: " << path << std::endl;
        }

        Mix_VolumeChunk(chunk.get(), volume);
    }

    void Audio::play() {
        Mix_PlayChannel(-1, chunk.get(), 0);
    }

    void Audio::play(int times) {
        Mix_PlayChannel(-1, chunk.get(), times - 1);
    }

    void Audio::set_volume(int volume) {
        Mix_VolumeChunk(chunk.get(), volume);
    }
}