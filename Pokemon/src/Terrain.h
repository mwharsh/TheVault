#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain {
public:
    char grid[21][80];
};

void setup(Terrain *t);
void printGrid(Terrain *t);
void placeSeeds(int Seed, Terrain *T);
void growSeeds(Terrain *t);

#endif