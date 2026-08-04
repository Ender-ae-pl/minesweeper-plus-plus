#include "button_music.hpp"

Button_music::Button_music(const char *imagePath, float scale, bool doCenter, Vector2 offset, AllMusic *allmusicptr, Color rectArowndClolor)
: Button(imagePath, scale, doCenter, offset)
{
    this->allmusicptr = allmusicptr;
    this->rectArowndClolor = rectArowndClolor;
    this->music = allmusicptr->musicChoice;
}

Button_music::~Button_music()
{
    allmusicptr = nullptr;
}

void Button_music::ChangeMusic()
{
    allmusicptr ->musicChoice++;
    if(allmusicptr->musicChoice == 4) allmusicptr->musicChoice = 0;
    
    this->music = allmusicptr->musicChoice;
    allmusicptr ->mustChangeMusic = true;
}

void Button_music::DrawRectangleArownd()
{
    if(music == 0) rectArowndClolor = GREEN;
    else if(music == 1) rectArowndClolor = BLUE;
    else if(music == 2) rectArowndClolor = RED;
    else if(music == 3) rectArowndClolor = PURPLE;
    int offset = 3; //How many bigger than texture
    DrawRectangle(posicion.x - offset + 1.5f, posicion.y - offset, texture.width + offset * 2, texture.height + offset * 2, rectArowndClolor);
}
