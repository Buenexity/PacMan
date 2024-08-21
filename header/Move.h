#pragma once
#include <string>
#include <vector>
#include "map.h"
#include "pacman.h"
using namespace std;
class Pacman;

class PacmanMovable 
{
public:
    virtual void move(vector<vector<string>> &i_map, Map &m) = 0;
};


enum Directions {
    None,
    Up,
    Down,
    Left,
    Right,
};




class GhostMovable 
{
public:
    virtual void target(float pacmanX, float pacmanY, Map m, Pacman &p) = 0;
    virtual void guard(Map m,int corner,Pacman &p) = 0;
    virtual void scatter(Map m) = 0;
};
