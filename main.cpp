#include "field.h"
#include <stdio.h>
#include <iostream>

int main(){
    Field field(20, 20, 100);

    field.setup(10, 10);
    
    for(auto i=field.field.begin();i!=field.field.end();++i){
        for(auto j=(*i).begin();j!=(*i).end();++j){
            std::cout << (*j).print() << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}