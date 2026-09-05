#pragma ocne
#include <string>

#include <button_rect.hpp>

class Button_writting :public Button_rect
{
    std::string textUp;
    bool onlyNumbers;
    
    public:
    
    Button_writting(float width, float height, bool doCenter, Vector2 offset = {0, 0}, Color rectColor = WHITE, bool onlyNumbers = false, int textSize = 10, Color textColor = BLACK, std::string textUp = "");


    void Input();
    void Draw();
    void DrawLine();
    void DrawTextUp();
};