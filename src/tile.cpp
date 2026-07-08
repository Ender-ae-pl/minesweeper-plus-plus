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
    DrawRectangle(scale * posx * (cellSize + spaceBetwen)-screenx,scale * posy * (cellSize + spaceBetwen)-screeny, (cellSize+spaceBetwen)*scale, (cellSize+spaceBetwen)*scale,color2);
    DrawRectangle(spaceBetwen+ scale * posx * (cellSize + spaceBetwen)-screenx,spaceBetwen+ scale * posy * (cellSize + spaceBetwen)-screeny, (cellSize - spaceBetwen)*scale, (cellSize - spaceBetwen)*scale, color);
};