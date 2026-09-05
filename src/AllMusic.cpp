#include "AllMusic.hpp"
#include "Random.hpp"


AllMusic::AllMusic()
{
    Random rng;
    int random = rng.RandInt(0, 3);
    
    InitAudioDevice();

    for(int i = 0; i < 4; i++) musics[i] = LoadMusicStream(paths[i]);
    
    for (int i = 0; i < 4; i++) {if(random == i) musicChoice = i;}
    
    backMusic = musics[musicChoice];
}

AllMusic::~AllMusic()
{
    for(int i = 0; i > 4; i++) UnloadMusicStream(musics[i]);
    UnloadMusicStream(backMusic);
    CloseAudioDevice();
}

void AllMusic::changeMuisc()
{
    musicChoice++;
    if(musicChoice == 4) musicChoice = 0;

    backMusic = musics[musicChoice];
    PlayMusicStream(backMusic);
}
