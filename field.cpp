#include "field.h"

Field::Field(int x, int y, int bombs):size_x(x), size_y(y), count_field(x+y), bombs(bombs){
    //make x*y field with random bombs
}
