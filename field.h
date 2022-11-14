#ifndef FIELD_H
#define FIELD_H

class Field {
public:
    const int size_x, size_y, bombs, count_field;
    Field(int x, int y, int bombs);

private:
    class Point{
    public:
        const int x, y, value;
        bool isMarked, isOpened;
        Point(int x, int y, int value);
    };
};

#endif