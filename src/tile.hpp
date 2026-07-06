#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>

class tile {
public:
    bool state;
    bool isMine;
    int adjminesnormal;

    tile();

    void open();
    void flag();

};