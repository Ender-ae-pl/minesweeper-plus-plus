#include "menu.hpp"
#include "board.hpp"
#include "ui.hpp"
#include "AllMusic.hpp"

class Game
{
    Menu menu;

    AllMusic* allmusicptr;
    Sound explosion;
    Board* boardptr; 
    //Ui ui;
    bool gameStarted;
    
    public:
        Game(AllMusic* allmusicptr=nullptr);
        ~Game();
    
        void explode_board();

        void input();

        void drawAll();
        void updateAll();
        void print();
};