#include "field.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

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
        std::cout << std::endl << "Welcome to Minesweeper!" << std::endl;

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

        field.print(false);

        auto start_x = 0;
        auto start_y = 0;
        while(true){
            std::string input = "";
            std::cout << "Where do you want to start? (Enter x,y) ";
            std::cin >> input;
            std::stringstream ss(input);
            std::vector<std::string> args;
            while( ss.good() )
            {
                std::string substr;
                std::getline( ss, substr, ',' );
                args.push_back( substr );
            }
            if(args.size() != 2){
                std::cout << "Please a enter valid input (\"x,y\")" << std::endl;
                continue;
            }
            try{
                start_x = std::stoi(args[0]);
            }catch(std::invalid_argument){
                std::cout << "Please a enter valid input (\"x,y\")" << std::endl;
                continue;
            }catch(std::out_of_range){
                std::cout << "Please enter a number in between " << 0 << " and " << width-1 << "for x." << std::endl;
                continue;
            }
            if(start_x < 0 || start_x >= width){
                std::cout << "Please enter a number in between " << 0 << " and " << width-1 << "for x." << std::endl;
                continue;
            }
            try{
                start_y = std::stoi(args[1]);
            }catch(std::invalid_argument){
                std::cout << "Please a enter valid input (\"x,y\")" << std::endl;
                continue;
            }catch(std::out_of_range){
                std::cout << "Please enter a number in between " << 0 << " and " << height-1 << " for y." << std::endl;
                continue;
            }
            if(start_y < 0 || start_y >= height){
                std::cout << "Please enter a number in between " << 0 << " and " << height-1 << " for y." << std::endl;
                continue;
            }
            field.setup(start_y, start_x);
            field.print(false);
            break;
        }

            while(true){
                auto x = 0;
                auto y = 0;
                std::string input = "";
                std::cout << "What point do you want to open? (Enter m,x,y; m for mode: f for flag, o for open) ";
                std::cin >> input;
                std::stringstream ss(input);
                std::vector<std::string> args;
                while( ss.good() )
                {
                    std::string substr;
                    std::getline( ss, substr, ',' );
                    args.push_back( substr );
                }
                if(args.size() != 3){
                    std::cout << "Please a enter valid input (\"m,x,y\")" << std::endl;
                    continue;
                }
                try{
                    x = std::stoi(args[1]);
                }catch(std::invalid_argument){
                    std::cout << "Please a enter valid input (\"m,x,y\")" << std::endl;
                    continue;
                }catch(std::out_of_range){
                    std::cout << "Please enter a number in between " << 0 << " and " << width-1 << " for x." << std::endl;
                    continue;
                }
                if(x < 0 || x >= width){
                    std::cout << "Please enter a number in between " << 0 << " and " << width-1 << " for x." << std::endl;
                    continue;
                }
                try{
                    y = std::stoi(args[2]);
                }catch(std::invalid_argument){
                    std::cout << "Please a enter valid input (\"m,x,y\")" << std::endl;
                    continue;
                }catch(std::out_of_range){
                    std::cout << "Please enter a number in between " << 0 << " and " << height-1 << " for y." << std::endl;
                    continue;
                }
                if(y < 0 || y >= height){
                    std::cout << "Please enter a number in between " << 0 << " and " << height-1 << " for y." << std::endl;
                    continue;
                }
                if(args[0] == "f"){
                    field.mark(x, y);
                }else if(args[0] == "o"){
                    if(field.open(x, y)){
                        field.print(true);
                        std::cout << "That's a bomb! Try again below or quit by pressing Ctrl+C!" << std::endl;
                        break;
                    }
                }
                field.print(false);
            }
        
        
    }

    return 0;
}