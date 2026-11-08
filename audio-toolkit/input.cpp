#include "input.h"
#include <iostream>
#include <limits>

// Type and range check for int input
int readInt(int lowerLimit, int upperLimit){
    int input {};    

    while(!(std::cin >> input) || input > upperLimit || input < lowerLimit){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter a number between " << lowerLimit << " and " << upperLimit << '\n' << std::endl;
              }
    return input;
}

// Type and range check for double input
double readDouble(double lowerLimit, double upperLimit){
    double input {};    

    while(!(std::cin >> input) || input > upperLimit || input < lowerLimit){

                if(std::cin.fail()){
                   std::cin.clear();
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter a numeric value between " << lowerLimit << " and " << upperLimit << '\n' << std::endl;
              }
    return input;
}