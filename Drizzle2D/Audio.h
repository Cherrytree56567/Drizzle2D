#pragma once
#include <string>
#include <memory>
#include <SDL_mixer.h>
#include <iostream>
#define D2D_EXPORT
#ifdef D2D_EXPORT
#define Drizzle2D_API __declspec(dllexport)
#else 
#define Drizzle2D_API __declspec(dllimport)
#endif

namespace Drizzle2D {
    Drizzle2D_API void InitAudio(int channels);
    class Drizzle2D_API Audio {
    public:
        Audio(const std::string& path, int volume);
        void play();
        void play(int times);
        void set_volume(int volume);

    private:
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk*)> chunk;
    };
}