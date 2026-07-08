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
    int cellSize=30;
    int spaceBetwen=4;
    Vector2 screenPos={0,0};
    float minscale=1;
    float scale=1;
    vector<vector<tile>> board;
    

    public:
        Board(int width, int height, int mines);
        void generate(int x, int y, map<string,int> props={});

        void print();
        void draw(int screenWidth, int screenHeight);
};