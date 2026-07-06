#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include "tile.hpp"


using namespace std;

class Board {
    public:
        int width;
        int height;
        int mines;
        vector<vector<tile>> board;

        Board(int width, int height, int mines);
        
        void generate(int x, int y, map<string,int> props={});




        void print();
};