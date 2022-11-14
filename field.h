#ifndef FIELD_H
#define FIELD_H
#include <vector>



class Field {
private:
    class Point{
    public:
        int x, y, value;
        bool isMarked, isOpened;
        Point(int x, int y, int value);
    };

public:
    int size_x, size_y, bombs, count_points;
    std::vector< std::vector<Point> > field;
    Field(int x, int y, int bombs);
    ~Field();
    void setup(int start_x, int start_y);

};

#endif