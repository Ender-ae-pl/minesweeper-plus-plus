#include "board.hpp"
#include "ui.hpp"

class Game
{
    Board board;
    //Ui ui
    
    public:
        Game();

        void input();

        void drawAll();
        void updateAll();
        void print();
};