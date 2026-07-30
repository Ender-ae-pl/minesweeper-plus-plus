#pragma once

#include <raylib.h>

class AllMusic
{
    const char* paths[3] = {"Sounds/wietnam.mp3", "Sounds/tetris.mp3", "Sounds/zsrr.mp3"};
    Music musics[3];

    
    public:
    Music backMusic;
    int musicChoice;
    bool mustChangeMusic;

    AllMusic();
    ~AllMusic();

    void changeMuisc();
};