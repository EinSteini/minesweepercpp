#include "field.h"
#include <stdio.h>
#include <iostream>

int main(){
    Field field(8, 8, 10);
    std::cout << "before" << std::endl;

    field.setup(1, 1);
    std::cout << "before" << std::endl;
    for(auto i=field.field.begin();i!=field.field.end();++i){
        for(auto j=(*i).begin();j!=(*i).end();++j){
            std::cout << std::to_string((*j).value) << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}