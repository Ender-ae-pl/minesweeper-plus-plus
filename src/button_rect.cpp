#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "button_rect.hpp"

Button_rect::Button_rect(std::string text, float width, float height, bool doCenter, Vector2 offset, Color rectColor, int textSize, Color textColor)
{
    if(doCenter) rect = Rectangle{Vector2Add(GetCenterPosicion(width, height), offset).x, Vector2Add(GetCenterPosicion(width, height), offset).y, width, height};
    else rect = Rectangle{offset.x, offset.y, width, height};

    this -> text = text;
    this -> rectColor = rectColor;
    this -> textSize = textSize;
    this -> textColor = textColor;
    textWidth = MeasureText(text.c_str(), textSize);
    IsHovered = false;
}

void Button_rect::ChangeColor(int value)
{
    //Changign color, but color valure always will by 0-255
    
    if(rectColor.r + value >= 0) {
        if(rectColor.r + value <= 255) rectColor.r += value;
        else rectColor.r = 255;
    }
    else rectColor.r = 0;

    if(rectColor.g + value >= 0) {
        if(rectColor.g + value <= 255) rectColor.g += value;
        else rectColor.g = 255;
    }
    else rectColor.g = 0;

    if(rectColor.b + value >= 0) {
        if(rectColor.b + value <= 255) rectColor.b += value;
        else rectColor.b = 255;
    }
    else rectColor.b = 0;
}

bool Button_rect::IsPressd(Vector2 mousePosicion, bool mousePressed)
{
    if(CheckCollisionPointRec(mousePosicion, rect) && mousePressed) return true;
    return false;
}

void Button_rect::DrawTextInside()
{
    DrawText(text.c_str(), rect.x + (rect.width - textWidth)/2, rect.y + (rect.height - textSize)/2, textSize, textColor);
}

Vector2 Button_rect::GetCenterPosicion(int width, int height)
{
    float withCenter = (GetScreenWidth() - width)/2;
    float heightCenter = (GetScreenHeight() - height)/2;

    return {withCenter, heightCenter};
}

void Button_rect::Draw()
{
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, rectColor);
    DrawTextInside();
}
