#include "board.hpp"
#include "ui.hpp"

class Game
{
    Sound explosion;
    Board board; 
    //Ui ui
    
    public:
        Music backMusic;
        
        Game();
        ~Game();
    
        void explode_board();

        void input();

        void drawAll();
        void updateAll();
        void print();
};