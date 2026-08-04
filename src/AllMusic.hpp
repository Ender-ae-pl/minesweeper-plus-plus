#pragma once

#include <raylib.h>

class AllMusic
{
    const char* paths[4] = {"Sounds/popcorn.mp3", "Sounds/tetris.mp3", "Sounds/zsrr.mp3", "Sounds/tetris_phonk.mp3"};
    Music musics[4];

    
    public:
    Music backMusic;
    int musicChoice;
    bool mustChangeMusic;

    AllMusic();
    ~AllMusic();

    void changeMuisc();
};