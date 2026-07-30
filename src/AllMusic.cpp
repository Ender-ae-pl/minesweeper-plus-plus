#include "AllMusic.hpp"
#include "Random.hpp"


AllMusic::AllMusic()
{
    Random rng;
    int random = rng.RandInt(1, 3);
    
    InitAudioDevice();

    for(int i = 0; i < 3; i++) musics[i] = LoadMusicStream(paths[i]);
    
    if(random == 1) musicChoice = 0;
    else if(random == 2) musicChoice = 1;
    else musicChoice = 2;
    
    backMusic = musics[musicChoice];
    
    
    mustChangeMusic = false;
}

AllMusic::~AllMusic()
{
    for(int i = 0; i > 3; i++) UnloadMusicStream(musics[i]);
    UnloadMusicStream(backMusic);
    CloseAudioDevice();
}

void AllMusic::changeMuisc()
{
    backMusic = musics[musicChoice];
    mustChangeMusic = false;
    PlayMusicStream(backMusic);
}
