#include <iostream>
#include <random>
#include <ctime>



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
                t->grid[i][j] = '.';
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

    for (int i = 0; i < 7; ++i) {
        int x = distX(rng);
        int y = distY(rng);
        t->grid[y][x] = '*';  // place marker
    }
}

