#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "Random.hpp"
#include "tile.hpp"

using namespace std;

Board::Board(int width, int height, int mines):width(width),height(height),mines(mines){};

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
