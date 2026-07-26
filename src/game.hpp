#include "board.hpp"
#include "ui.hpp"

class Game
{
    Sound explosion;
    Board board; 
    //Ui ui
    
    public:
        Music backMusic1;
        Music backMusic2;
        Music backMusic3;
        Texture2D flag;
        
        Game();
        ~Game();
        
        void input();
        void explode();

        void drawAll();
        void updateAll();
        void print();
};