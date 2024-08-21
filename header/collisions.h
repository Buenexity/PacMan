#pragma once

#include "../header/map.h"
#include <vector>
#include <string>
using namespace std;

constexpr unsigned int mapHeight = 21; // will vary for the different maps
constexpr unsigned int mapWidth = 21;
constexpr unsigned int tileSize = 21;

class collisions {
public:
    bool map_collision(bool eatingPellets, bool usingDoor, short x, short y, vector<vector<string>>& i_map, Map &m);
};