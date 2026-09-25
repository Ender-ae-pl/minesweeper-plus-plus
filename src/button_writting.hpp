#pragma ocne
#include <string>

#include "button_rect.hpp"

class Button_writting :public Button_rect
{
    std::string textUp;
    bool onlyNumbers;

    
    public:
    bool isWrong;
    
    Button_writting(float width, float height, bool doCenter, Vector2 offset = {0, 0}, Color rectColor = WHITE, bool onlyNumbers = false, int textSize = 10, Color textColor = BLACK, std::string textUp = "");

    void wrongInput() {if(!isWrong) {rectColor.g -= 100; rectColor.b -= 100; isWrong = true;}}
    void UnWrongInput() {isWrong = false; rectColor = WHITE;}

    void Input();
    void Draw();
    void DrawLine();
    void DrawTextUp();
};