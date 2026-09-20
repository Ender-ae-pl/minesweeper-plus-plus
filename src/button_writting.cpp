#include <iostream>
#include <raylib.h>

#include "button_writting.hpp"

Button_writting::Button_writting(float width, float height, bool doCenter, Vector2 offset, Color rectColor, bool onlyNumbers, int textSize, Color textColor, std::string textUp)
:Button_rect("", width, height, doCenter, offset, rectColor, textSize, textColor)
{
    this -> onlyNumbers = onlyNumbers;
    this -> textUp = textUp;
}

void Button_writting::Input()
{
    int key = GetCharPressed();

    while(key > 0)
    {
        if(key >= 32 && key <= 126 && !onlyNumbers) text += (char)key;
        else if(key >= 48 && key <= 57 && onlyNumbers) text += (char)key;
        key = GetCharPressed();
    }

    //Backspace
    if(IsKeyPressed(KEY_BACKSPACE) && !text.empty()) text.pop_back();

    //Counting text width
    textWidth = MeasureText(text.c_str(), textSize);

    //If text is too big
    //if(textWidth > rect.width - 10) { text.pop_back(); textWidth = MeasureText(text.c_str(), textSize); }
    if(text.size() > 3) { text.pop_back(); textWidth = MeasureText(text.c_str(), textSize); }
}

void Button_writting::Draw()
{
    DrawRectangle(rect.x - 5, rect.y - 5, rect.width + 10, rect.height + 10, PURPLE); // purple arownd rectangle
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, rectColor); //place to type
    DrawText(text.c_str(), rect.x + 10, rect.y + 15, textSize, textColor); //text
    DrawTextUp();
}

void Button_writting::DrawLine()
{
    DrawRectangle(rect.x + 15 + textWidth, rect.y + 10, 3, rect.height - 20, BLACK);
}

void Button_writting::DrawTextUp()
{
    DrawText(textUp.c_str(), rect.x, rect.y - 35, 20, BLACK);
}
