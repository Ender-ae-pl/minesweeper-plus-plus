#include "board.hpp"
#include "ui.hpp"
#include "AllMusic.hpp"

class Game
{
    AllMusic* allmusicptr;
    Sound explosion;
    Board board; 
    //Ui ui;
    
    public:
        Game(AllMusic* allmusicptr=nullptr, int width=0, int height=0, int mines=0);
        ~Game();
    
        void explode_board();

        void input(bool &gameStarted);

        void drawAll();
        void updateAll();
        void print();
};