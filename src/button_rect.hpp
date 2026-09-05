#pragma once
#include <raylib.h>
#include <string>

class Button_rect
{
    protected:
    Color rectColor;
    
    Color textColor;
    int textSize;
    int textWidth;
    
    bool IsClicked;
    
    void DrawTextInside();
    
    public:
    std::string text;
    bool IsHovered;
    Rectangle rect;


    Button_rect(std::string text, float width, float height, bool doCenter, Vector2 offset, Color rectColor, int textSize, Color textColor);

    void ChangeColor(int value);
    bool IsPressd(Vector2 mousePosicion, bool mousePressed);
    Vector2 GetCenterPosicion(int width, int height);

    void Draw();
};