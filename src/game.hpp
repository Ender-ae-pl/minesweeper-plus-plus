#include "board.hpp"
#include "ui.hpp"
#include "AllMusic.hpp"

class Game
{
    AllMusic* allmusicptr;
    Sound explosion;
    Board board; 
    //Ui ui
    
    public:
        Game(AllMusic* allmusicptr);
        ~Game();
    
        void explode_board();

        void input();

        void drawAll();
        void updateAll();
        void print();
};