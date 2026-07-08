#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "Random.hpp"
#include "tile.hpp"

using namespace std;

Board::Board(int width, int height, int mines, int cellSize, int spaceBetwen):width(width),height(height),mines(mines),cellSize(cellSize),spaceBetwen(spaceBetwen){};

void Board::generate(int x, int y, map<string,int> props){
    Random rng;
    board = vector<vector<tile>>(width,vector<tile>(height));
    int rmines = mines;
    if (mines>width*height-9){return;}
    while (rmines>0){
        int rx = rng.RandInt(0,width-1);
        int ry = rng.RandInt(0,height-1);
        if (board[rx][ry].isMine==false && abs(rx-x)>1 && abs(ry-y)>1){
            board[rx][ry].isMine = true;
            rmines-=1;
        }
    }
}

void Board::print(){
    for (int i=0;i<width;i++){
        for (int j=0;j<height;j++){
            cout<<board[i][j].isMine<<" ";
        }
        cout<<endl;
    }
}

void Board::draw(int screenWidth, int screenHeight){
    int BordSizeX = (width * cellSize) + spaceBetwen * (width - 1);
    int BordSizeY = (height * cellSize) + spaceBetwen * (height - 1);
    Color color;
    
    for (int w=0;w<width;w++) for (int h=0;h<height;h++){
        if(board[w][h].isMine) color = RED;
        else color=BLUE;
        DrawRectangle(w * (cellSize + spaceBetwen) + (screenWidth/2 - BordSizeX/2), h * (cellSize + spaceBetwen) + (screenHeight/2 - BordSizeY/2), cellSize - spaceBetwen, cellSize - spaceBetwen, color);
    }
}