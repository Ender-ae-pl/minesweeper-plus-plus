#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

class Game;
#include "tile.hpp"

using namespace std;

class Board {
    public:
        Game* gameptr;

        int spaceBetwen=4;
        float minscale=1;
        float scale=1;
        int cellSize=30;
        int mines;
        Vector2 screenPos;
        vector<vector<tile>> board;
        int width;
        int height;
        Board(int width, int height, int mines);
        void generate(int x, int y, map<string,int> props={});

        int ApplyToAdjacent(tile* CenterTile, std::function<int(tile*)> f);
        void move_left();
        void move_right();
        void move_up();
        void move_down();

        void assign();
        void print();
        void draw(Texture2D flag);
};