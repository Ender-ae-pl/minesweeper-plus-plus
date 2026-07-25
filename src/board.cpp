#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

#include "board.hpp"
#include "Random.hpp"
#include "tile.hpp"

using namespace std;

Board::Board(int width, int height, int mines):width(width),height(height),mines(mines){
    screenPos={0,0};
};


int Board::ApplyToAdjacent(tile* CenterTile, std::function<int(tile*)> f){
    int count=0;
    int x=CenterTile->posx;
    int y=CenterTile->posy;
    for(int dx=-1;dx<2;dx++) for(int dy=-1;dy<2;dy++) {
        if(x+dx<0||y+dy<0||x+dx>=width||y+dy>=height){continue;}
        if(dx==0&&dy==0){continue;}
        count+=f(&board[x+dx][y+dy]);
    }

    return count;
}

void Board::generate(int x, int y, map<string,int> props){
    Random rng;
    board = vector<vector<tile>>(width,vector<tile>(height,tile(0,0)));
    //update tile position
    for (int i=0;i<width;i++) for (int j=0;j<height;j++){
        board[i][j].posx=i;
        board[i][j].posy=j;
        board[i][j].boardptr=this;
    }

    
    int rmines = mines;
    if (mines>width*height-9){return;}
    while (rmines>0){
        int rx = rng.RandInt(0,width-1);
        int ry = rng.RandInt(0,height-1);
        if (board[rx][ry].isMine==false && abs(rx-x)>1 && abs(ry-y)>1){
            board[rx][ry].isMine = true;
            board[rx][ry].color = RED;
            //incrase minesArround counter other blocks
            ApplyToAdjacent(&board[rx][ry], [](tile* t){
                t->minesArround++;
                return 0;
            });

            rmines-=1;
        }
    }

    //min. scale
    if ((float)GetScreenWidth()/width*height>=GetScreenHeight()) minscale = (float)GetScreenWidth()/width/cellSize;
    else minscale = (float)GetScreenHeight()/height/cellSize;
    scale = minscale;


}




void Board::move_left()
{
    return;
}

void Board::move_right()
{
    return;
}

void Board::move_up()
{
    return;
}

void Board::move_down()
{
    return;
}

void Board::assign()
{
    int screenx=screenPos.x;
    int screeny=screenPos.y;

    for (int w=0;w<width;w++) for (int h=0;h<height;h++){
        board[w][h].assignRect(cellSize,spaceBetwen,scale,screenx,screeny);
    }
}

void Board::print()
{
    for (int j=0;j<height;j++){
        for (int i=0;i<width;i++){
            cout<<board[i][j].isMine<<" ";
        }
        cout<<endl;
    }
}

void Board::draw(){
    int screenx=screenPos.x;
    int screeny=screenPos.y;

    for (int w=0;w<width;w++) for (int h=0;h<height;h++){
        board[w][h].draw(cellSize,spaceBetwen,scale,screenx,screeny);
    }
}