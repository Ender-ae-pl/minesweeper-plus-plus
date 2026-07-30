#include "button.hpp"

#include <iostream>
#include <raymath.h>

void Button::ChangeMusic()
{
    allmusicptr ->musicChoice++;
    if(allmusicptr->musicChoice == 3) allmusicptr->musicChoice = 0;
    
    this->music = allmusicptr->musicChoice;
    allmusicptr ->mustChangeMusic = true;
}

Button::Button(const char *imagePath, float scale, bool doCenter, Vector2 offset,AllMusic* allmusicptr, Color rectArowndClolor)
{
    Image image = LoadImage(imagePath);
    
    int newWidth = static_cast<int>(image.width * scale);
    int newHeight = static_cast<int>(image.height * scale);
    
    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    
    if(doCenter) posicion = Vector2Add(GetCenterPosicion(), offset);
    else posicion = offset;
    
    IsClicked = false;
    
    ///Specyfic for music button
    if(allmusicptr != nullptr) {
        this->allmusicptr = allmusicptr;
        this->rectArowndClolor = rectArowndClolor;
        this->music = allmusicptr->musicChoice;
    }
}

Button::~Button()
{
    UnloadTexture(texture);
}

bool Button::IsPressd(Vector2 mousePosicion, bool mousePressed)
{
    Rectangle rect = {posicion.x, posicion.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};

    if(CheckCollisionPointRec(mousePosicion, rect) && mousePressed) return true;
    return false;
}

Vector2 Button::GetCenterPosicion()
{
    float withCenter = (GetScreenWidth() - texture.width)/2;
    float heightCenter = (GetScreenHeight() - texture.height)/2;

    return {withCenter, heightCenter};
}

void Button::DrawRectangleArownd()
{
    if(music == 0) rectArowndClolor = RED;
    else if(music == 1) rectArowndClolor = BLUE;
    else if(music == 2) rectArowndClolor = GREEN;
    int offset = 3; //How many bigger than texture
    DrawRectangle(posicion.x - offset + 1.5f, posicion.y - offset, texture.width + offset * 2, texture.height + offset * 2, rectArowndClolor);
}


void Button::Draw()
{
    DrawTextureV(texture, posicion, WHITE);
}
