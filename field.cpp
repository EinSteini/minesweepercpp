#include "field.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define BOMBVALUE 9

Field::Field(int x, int y, int bombs):size_x(y), size_y(x), count_points(x*y), bombs(bombs){
    if(count_points <= bombs*4 || bombs < 1){
        //std::cout << "Bombs have been set to a quarter of all nodes due to the the amount being too large" << std::endl;
        bombs = count_points / 5;
    }
    size_x = size_x < 4 ? 4 : size_x;
    size_y = size_y < 4 ? 4 : size_y;

    //make point vector with default values
    for(auto i=0; i < size_x; ++i){
        std::vector<Point> column;
        field.push_back(column);
        for(auto j=0; j < size_y; ++j){
            Point point(i, j, 0);
            field[i].push_back(point);
        }
    }

}
void Field::setup(int start_x, int start_y){
    srand (time(NULL));
    auto bombsPlanted = 0;
    while(bombsPlanted < bombs){
        auto bomb_x = rand() % size_x;
        auto bomb_y = rand() % size_y;
        if((abs(bomb_x - start_x) < 2 && abs(bomb_y - start_y) < 2) || field[bomb_x][bomb_y].value == BOMBVALUE){
            continue;
        }else{
            ++bombsPlanted;
            field[bomb_x][bomb_y].value = BOMBVALUE;
        }
        
    }
}
Field::~Field(){}
Field::Point::Point(int x, int y, int value){
    Field::Point::x = x;
    Field::Point::y = y;
    Field::Point::value = value;
}
