#include <iostream>
#include <random>
#include <ctime>

#include "Terrain.h"


int main() {
    
    int GameStart = 1;
    char c;

    while(GameStart == 1){

        std::srand(std::time(nullptr));  // seed RNG with current time
    
        unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
        std::cout << "Seed used: " << seed << std::endl;

        Terrain *T = (Terrain*)malloc(sizeof(Terrain));
        setup(T);
        placeSeeds(seed, T);
        printGrid(T);
        growSeeds(T);

        std::cout << "Enter Action: ";
        std::cin >> c;
        if(c == 'Q'){
            GameStart = 0;
        }
    }


    return 0;
}