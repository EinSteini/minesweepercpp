#include "field.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#define BOMBVALUE 9


Field::Field(int x, int y, int pbombs):size_x(x), size_y(y), count_points(x*y), bombs(pbombs), win_count(pbombs){
    

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

        //std::cout << "rand" << bomb_x << " " << bomb_y << " " << bombsPlanted << std::endl;

        //If the coordinates point to the start location or the neighboring points, skip
        if((abs(bomb_x - start_x) < 2 && abs(bomb_y - start_y) < 2) || field[bomb_x][bomb_y].value == BOMBVALUE){
            continue;
        }
        ++bombsPlanted;
        field[bomb_x][bomb_y].value = BOMBVALUE;

        //Increase value of neighboring points
        if(bomb_x  > 0 && bomb_x < size_x-1){
            field[bomb_x-1][bomb_y].increase();
            field[bomb_x+1][bomb_y].increase();
            if(bomb_y > 0){
                field[bomb_x-1][bomb_y-1].increase();
                field[bomb_x][bomb_y-1].increase();
                field[bomb_x+1][bomb_y-1].increase();
            }
            if(bomb_y < size_y-1){
                field[bomb_x-1][bomb_y+1].increase();
                field[bomb_x][bomb_y+1].increase();
                field[bomb_x+1][bomb_y+1].increase();
            }
        }else if(bomb_x == 0){
            field[bomb_x+1][bomb_y].increase();
            if(bomb_y > 0){
                field[bomb_x][bomb_y-1].increase();
                field[bomb_x+1][bomb_y-1].increase();
            }
            if(bomb_y < size_y-1){
                field[bomb_x][bomb_y+1].increase();
                field[bomb_x+1][bomb_y+1].increase();
            }
        }else if(bomb_x == size_x-1){
            field[bomb_x-1][bomb_y].increase();
            if(bomb_y > 0){
                field[bomb_x][bomb_y-1].increase();
                field[bomb_x-1][bomb_y-1].increase();
            }
            if(bomb_y < size_y-1){
                field[bomb_x][bomb_y+1].increase();
                field[bomb_x-1][bomb_y+1].increase();
            }
        }

    }
    Field::open(start_x, start_y);
}

bool Field::open(int x, int y){
    if(field[x][y].value == BOMBVALUE) return true;
    if(field[x][y].isOpened) return false;
    field[x][y].isOpened = true;
    if(field[x][y].value != 0) return false;
    if(x > 0 && x < size_x-1){
        Field::open(x-1, y);
        Field::open(x+1, y);
        if(y > 0){
            Field::open(x-1, y-1);
            Field::open(x, y-1);
            Field::open(x+1, y-1);
        }
        if(y < size_y-1){
            Field::open(x-1, y+1);
            Field::open(x, y+1);
            Field::open(x+1, y+1);
        }
    }else if(x == 0){
        Field::open(x+1, y);
        if(y > 0){
            Field::open(x, y-1);
            Field::open(x+1, y-1);
        }
        if(y < size_y-1){
            Field::open(x, y+1);
            Field::open(x+1, y+1);
        }
    }else if(x == size_x-1){
        Field::open(x-1, y);
        if(y > 0){
            Field::open(x, y-1);
            Field::open(x-1, y-1);
        }
        if(y < size_y-1){
            Field::open(x, y+1);
            Field::open(x-1, y+1);
        }
    }
    return false;
}

void Field::print(bool final){
    std::cout << std::endl;
    std::string upperNumbers = "     ";
    std::string horizontalLine = "   +-";
    for(auto i=0;i<size_x;++i){
        upperNumbers += (i>9 && i%2 == 1) ? "  " : std::to_string(i);
        if(i<10) upperNumbers += " ";
        horizontalLine += "--";
    }
    std::cout << upperNumbers << std::endl;
    std::cout << horizontalLine << "+" << std::endl;
    for(auto i=0;i<size_y;++i){
        if(i<10) std::cout << "0";
        std::cout << std::to_string(i) << " | ";
        for(auto j=field.begin();j!=field.end();++j){
            if(final){
                (*j)[i].isOpened = true;
                (*j)[i].isMarked = false;
            }
            std::cout << (*j)[i].print() << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << horizontalLine << "+" << std::endl;
    std::cout << std::endl;
}

void Field::mark(int x, int y){
    field[x][y].isMarked = !field[x][y].isMarked;
}
Field::~Field(){}
Field::Point::Point(int x, int y, int value){
    Field::Point::x = x;
    Field::Point::y = y;
    Field::Point::value = value;
    Field::Point::isMarked = false;
    Field::Point::isOpened = false;
}

void Field::Point::increase(){
    //std::cout << "increase " << this->x << " " << this->y << " " << this->value << std::endl;
    if(this->value != BOMBVALUE){
        this->value++;
    }
}

char Field::Point::print(){
    if(this->isMarked){
        return '>';
    }
    if(!this->isOpened){
        return 'X';
    }
    if(this->value == BOMBVALUE){
        return 'B';
    }
    return std::to_string(this->value)[0];
}
