#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include "tile.hpp"


using namespace std;

class Board {
    int mines;
    int cellSize=30;
    int spaceBetwen=4;
    Vector2 screenPos={0,0};
    float minscale=1;
    float scale=1;
    
    
    public:
        vector<vector<tile>> board;
        int width;
        int height;
        Board(int width, int height, int mines);
        void generate(int x, int y, map<string,int> props={});

        void move_left();
        void move_right();
        void move_up();
        void move_down();

        void assign();
        void print();
        void draw();
};