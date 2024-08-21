#include "../header/Map.h"
#include "../header/MapSketch.h"
#include "../header/object.h"
#include "../header/pacman.h"
#include <iostream>

using namespace std;

void Map::draw_Map(sf::RenderWindow &window) {
    sf::RectangleShape square(sf::Vector2f(square_size, square_size));
    sf::RectangleShape Door(sf::Vector2f(square_size, square_size));

    Door.setFillColor(sf::Color::White);
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Yellow);
    circle.setRadius(square_size);
    float center_offset_pellets = (square_size - circle.getRadius()/6 * 2) / 2.0f;
    float center_offset_energizers = (square_size - circle.getRadius()/4 * 2) / 2.0f;
    sf::Texture texture;
    if(!texture.loadFromFile("extraFiles/pacman_map_graph.png")){
        cout << "load failed" << endl;
    }
    sf::Texture gate_texture;
    if(!gate_texture.loadFromFile("extraFiles/pacman_map_images.png")){
        cout << "load failed" << endl;
    }
    sf::Sprite sprite(texture);
    sf::Sprite gate_sprite(gate_texture);
    for (int i = 0; i < MAP_HEIGHT1; ++i) 
    {
        for (int j = 0; j < MAP_WIDTH1; ++j) 
        {
            square.setPosition(j * square_size, i * square_size);
            sprite.setPosition(j * square_size, i * square_size);
            gate_sprite.setPosition(j * square_size, i * square_size);
            char current_char = map_sketch[i][0][j];
            
            //Walls
            if (current_char == '#') { 
                square.setFillColor(sf::Color::Blue);
                window.draw(square);
            //Pacman
            } else if (current_char == 'J') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(250, 5, 30, square_size));
                window.draw(sprite);

            } else if (current_char == 'V') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(197, 40, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'E') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(226, 5, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'R') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(294, 5, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'W') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(133, 5, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'A') { 
                square.setFillColor(sf::Color::Blue);
                sprite.setTextureRect(sf::IntRect(165, 5, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'T') { 
                sprite.setTextureRect(sf::IntRect(101, 5, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'K') { 
                sprite.setTextureRect(sf::IntRect(165, 69, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'L') { 
                sprite.setTextureRect(sf::IntRect(101, 69, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'S') { 
                sprite.setTextureRect(sf::IntRect(165, 37, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'D') { 
                sprite.setTextureRect(sf::IntRect(101, 37, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'B') { 
                sprite.setTextureRect(sf::IntRect(197, 5, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'M') { 
                sprite.setTextureRect(sf::IntRect(197, 70, square_size + 1, square_size));
                window.draw(sprite);

            } else if (current_char == 'Q') { 
                sprite.setTextureRect(sf::IntRect(133, 69, square_size, square_size));
                window.draw(sprite);

            } else if (current_char == 'P') { //Pacman
                pac_location.x = short(square_size*j);
                pac_location.y = short(square_size*i);

            } else if (current_char == '.') { //DOTS
                circle.setPosition(j*square_size+center_offset_pellets,i * square_size+center_offset_pellets);
                circle.setFillColor(sf::Color::Yellow);
                circle.setRadius(square_size/6);
                gate_sprite.setTextureRect(sf::IntRect(-3, 14, square_size, square_size - 5));
                window.draw(gate_sprite);

            } else if (current_char == 'o') { //Energizers
                circle.setPosition(j* square_size+center_offset_energizers,i * square_size+center_offset_energizers);
                circle.setRadius(square_size/4);
                circle.setFillColor(sf::Color::Yellow);
                gate_sprite.setTextureRect(sf::IntRect(12, 16, square_size - 5, square_size - 5));
                window.draw(gate_sprite);

            } else if (current_char == '=') { //Gate
                circle.setPosition(j*square_size + center_offset_energizers, i*square_size + center_offset_energizers);
                circle.setRadius(square_size/4);
                circle.setFillColor(sf::Color::Yellow);
                gate_sprite.setTextureRect(sf::IntRect(28, 15, square_size, square_size));
                window.draw(gate_sprite);
                Door.setPosition(j * square_size, i * square_size);
                door_position.x = j * square_size;
                door_position.y = i * square_size;


            } else if (current_char == '0') { 
                red_ghost_location.x = j*square_size;
                red_ghost_location.y = i*square_size;

            } else if (current_char == '1') { 
               blue_ghost_location.x = j*square_size;
                blue_ghost_location.y = i*square_size;

            }else if (current_char == '2') { 
                orange_ghost_location.x = j*square_size;
                orange_ghost_location.y = i*square_size;

            } else if (current_char == '3') { 
                pink_ghost_location.x = j*square_size;
                pink_ghost_location.y = i*square_size;

            }
            else if (current_char == '=') 
            { 
                Door.setPosition(j*square_size,i*square_size);
                door_position.x = j*square_size;
                door_position.y = i*square_size;
                window.draw(Door);
            }
          
          
        }
    }
}


float Map::getRow() {
    return row;
}

void Map::modifyMap(int x, int y, char newContent) {
    map_sketch[y][0][x] = newContent;
}

float Map::getCol() {
    return col;
}

std::vector<std::vector<std::string>> Map::GetMap()
{
    return map_sketch;
}



void Map::set_Map(int m) {
    if (m == 1) {
        map_sketch = map1;
    }
    if (m == 2) {
        map_sketch = map2;
    }
    if (m == 3) {
        map_sketch = completedMap;
    }
}


void Map::set_Score_Map(vector<vector<string>> inputMap) {
    map_sketch = inputMap;
}