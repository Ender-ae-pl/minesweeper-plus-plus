#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include "tile.hpp"


using namespace std;

class Board {
    int width;
    int height;
    int mines;
    int cellSize;
    int spaceBetwen;
    vector<vector<tile>> board;
    

    public:
        Board(int width, int height, int mines, int cellSize, int spaceBetwen);
        void generate(int x, int y, map<string,int> props={});

        void print();
        void draw(int screenWidth, int screenHeight);
};