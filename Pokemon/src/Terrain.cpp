#include <iostream>
#include <random>
#include <ctime>

#include "queue.h"



class Terrain {
public:
    char grid[21][80];
};

// Use Terrain* (uppercase T) for the pointer type
void setup(Terrain *t) {
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 80; ++j) {
            // Set border cells to '%', others to '.'
            if (i == 0 || i == 20 || j == 0 || j == 79) {
                t->grid[i][j] = '%';
            } else {
                t->grid[i][j] = '_';
            }
        }
    }
}

void printGrid(Terrain *t) {
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 80; ++j) {
            std::cout << t->grid[i][j];
        }
        std::cout << '\n';
    }
}

void placeSeeds(int Seed, Terrain *t){

    std::mt19937 rng(Seed);

    std::uniform_int_distribution<int> distX(1, 78);  // avoid edges
    std::uniform_int_distribution<int> distY(1, 19);

    for (int i = 0; i < 8; ++i) {
        int x = distX(rng);
        int y = distY(rng);
        if(i == 0 || i == 1){
            t->grid[y][x] = '.';  // place marker
        }
        if(i == 2 || i == 3){
            t->grid[y][x] = ':';  // place marker
        }
        if(i == 4){
            t->grid[y][x] = '^';  // place marker
        }
        if(i == 5){
            t->grid[y][x] = '%';  // place marker
        }
        if(i == 6 || i == 7){
            t->grid[y][x] = '~';  // place marker
        }
    }
}

void growSeeds(Terrain *t){
    
    Queue q;

    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 79; j++){
            if(t->grid[i][j] != '_'){
                q.enqueue(i, j, t->grid[i][j]);
            }
        }
    }

    while(q.isEmpty() == false){
        Node* temp = q.peek();
        
    }
}

