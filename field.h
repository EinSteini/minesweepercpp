#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <string>


class Field {
private:
    class Point{
    public:
        int x, y, value;
        bool isMarked, isOpened;
        Point(int x, int y, int value);
        void increase();
        char print();
    };

public:
    int size_x, size_y, bombs, count_points;
    std::vector< std::vector<Point> > field;
    Field(int x, int y, int bombs);
    ~Field();
    void setup(int start_x, int start_y);
    void open(int x, int y);
    void print(); 
};

#endif