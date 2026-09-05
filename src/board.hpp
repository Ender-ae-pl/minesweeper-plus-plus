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

        Texture2D flag;
        Texture2D bomb;

        bool isBoardExploded;
        bool winGame;
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
        int countOpens();

        int ApplyToAdjacent(tile* CenterTile, std::function<int(tile*)> f);

        void assign();
        void print();
        void update();
        void draw();
};