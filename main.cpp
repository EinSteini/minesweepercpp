#include "field.h"
#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_X 100
#define MAX_Y 100
#define MAX_BOMBS MAX_X * MAX_Y / 5 
#define MIN_X 4
#define MIN_Y 4
#define MIN_BOMBS 1

int main(){
    int width = 8;
    int height = 8;
    int bombs = 10;
    while(true){
        std::cout << "Welcome to Minesweeper!" << std::endl;

        while(true){
            std::string input = "";
            std::cout << "Please specify the desired width of the field: ";
            std::cin >> input;
            try{
                width = std::stoi(input);
            }catch(std::invalid_argument){
                std::cout << "Please enter a number" << std::endl;
                continue;
            }catch(std::out_of_range){
                std::cout << "Please enter a number in between " << MIN_X << " and " << MAX_X << std::endl;
                continue;
            }
            if(width > MAX_X || width < MIN_X){
                std::cout << "Please enter a number in between " << MIN_X << " and " << MAX_X << std::endl;
                continue;
            }
            break;
        
        }

        while(true){
            std::string input = "";
            std::cout << "Please specify the desired height of the field: ";
            std::cin >> input;
            try{
                height = std::stoi(input);
            }catch(std::invalid_argument){
                std::cout << "Please enter a number" << std::endl;
                continue;
            }catch(std::out_of_range){
                std::cout << "Please enter a number in between " << MIN_Y << " and " << MAX_Y << std::endl;
                continue;
            }
            if(height > MAX_Y || height < MIN_Y){
                std::cout << "Please enter a number in between " << MIN_Y << " and " << MAX_Y << std::endl;
                continue;
            }
            break;
        
        }

        int maxbombs = height*width/5;

        while(true){
            std::string input = "";
            std::cout << "Please specify the desired count of bombs: ";
            std::cin >> input;
            try{
                bombs = std::stoi(input);
            }catch(std::invalid_argument){
                std::cout << "Please enter a number" << std::endl;
                continue;
            }catch(std::out_of_range){
                std::cout << "Please enter a number in between " << MIN_BOMBS << " and " << maxbombs << std::endl;
                continue;
            }
            if(bombs > maxbombs || bombs < MIN_BOMBS){
                std::cout << "Please enter a number in between " << MIN_BOMBS << " and " << maxbombs << std::endl;
                continue;
            }
            break;
        
        }
        Field field(height, width, bombs);

        field.print();

        // field.setup(0, 0);
        // field.open(3, 3);
        //printField(field);


        break;
        
    }

    return 0;
}