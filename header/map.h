#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <array>
#include <vector>
#include <string>
using namespace std;
class Map {
public:
    const int font = 16;
    const int square_size = 21.0f;
    void draw_Map(sf::RenderWindow &window);
    void set_Map(int);
    void set_Score_Map(vector<vector<string>>);
    vector<vector<string>> GetMap();
    int map_selection;
    float getRow();
    float getCol();
    void modifyMap(int x, int y, char newContent);
    sf::Vector2f pac_location;
    sf::Vector2f red_ghost_location;
    sf::Vector2f orange_ghost_location;
    sf::Vector2f blue_ghost_location;
    sf::Vector2f pink_ghost_location;
    sf::Vector2f door_position;

private:
    int row;
    int col;
    int map_select;
    std::vector<std::vector<std::string>> map_sketch;
};

// The map will consist of tiles that can be walls, empty, etc.
enum Tile {
    Empty,
    Pellet,
    PowerUp,
    Fruit,
    Wall,
    Door,
};

#endif // MAP_H