#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

#include "board.hpp"
#include "tile.hpp"

tile::tile(int posx, int posy){
    this->posx=posx;
    this->posy=posy;
    isMine=false;
};

void tile::draw(int cellSize, int spaceBetwen, float scale,int screenx,int screeny){
    Color color;
    Color color2=GRAY;
    if(isMine) color = RED;
    else color=BLUE;
    DrawRectangle(scale *  (posx * cellSize)  -screenx,scale *  (posy * cellSize)  -screeny, (cellSize)*scale, (cellSize)*scale,color2);
    cout<<posx<<" "<<scale * 100<<endl;
    DrawRectangle(scale * (spaceBetwen/2 + posx * cellSize)  -screenx,scale *  (spaceBetwen/2 + posy * cellSize)  -screeny, (cellSize - spaceBetwen)*scale, (cellSize - spaceBetwen)*scale, color);
};