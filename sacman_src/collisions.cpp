#include <cmath>
#include <array>

#include "../header/collisions.h"
#include "../header/map.h"
#include "../header/pacman.h"

bool collisions::map_collision(bool eatingPellets, bool usingDoor, short x, short y, vector<vector<string>>& i_map, Map &m) 
{
    
    bool collision = false;

    // get the exact position in tiles
    float tileX = x / static_cast<float>(tileSize);
    float tileY = y / static_cast<float>(tileSize);

    // a character can only go into 4 tiles max
    int currentTileX = 0;
    int currentTileY = 0;

    for (unsigned int i = 0; i < 4; i++) {
        switch(i) {
            case 0: // top left tile
                currentTileX = static_cast<int>(floor(tileX));
                currentTileY = static_cast<int>(floor(tileY));
                break;
            case 1: // top right tile
                currentTileX = static_cast<int>(ceil(tileX));
                currentTileY = static_cast<int>(floor(tileY));
                break;
            case 2: // bottom right tile
                currentTileX = static_cast<int>(ceil(tileX));
                currentTileY = static_cast<int>(ceil(tileY));
                break;
            case 3: // bottom left tile
                currentTileX = static_cast<int>(floor(tileX));
                currentTileY = static_cast<int>(ceil(tileY));
                break;
        }




		// make sure the position is in the map
		if ((0 <= currentTileX && currentTileX < mapWidth) && (0<= currentTileY && currentTileY < mapHeight)) {
        
            if (!eatingPellets) { // collision with walls and door
			    if (('#' == i_map[currentTileY][0][currentTileX]) || ('J' == i_map[currentTileY][0][currentTileX]) || ('V' == i_map[currentTileY][0][currentTileX]) ||
                    ('E' == i_map[currentTileY][0][currentTileX]) || ('R' == i_map[currentTileY][0][currentTileX]) || ('W' == i_map[currentTileY][0][currentTileX]) ||
                    ('A' == i_map[currentTileY][0][currentTileX]) || ('T' == i_map[currentTileY][0][currentTileX]) || ('K' == i_map[currentTileY][0][currentTileX]) ||
                    ('L' == i_map[currentTileY][0][currentTileX]) || ('S' == i_map[currentTileY][0][currentTileX]) || ('D' == i_map[currentTileY][0][currentTileX]) ||
                    ('B' == i_map[currentTileY][0][currentTileX]) || ('M' == i_map[currentTileY][0][currentTileX]) || ('Q' == i_map[currentTileY][0][currentTileX]))   {

				    collision = true;
			    }
                if ('=' == i_map[currentTileY][0][currentTileX] && usingDoor == false) {
				    collision = true;
			    }
            }

            else { // collision with pellets, power up, etc
                if ('.' == i_map[currentTileY][0][currentTileX]) {
                    if (eatingPellets) {
                        //std::cout<<"pellet";
                        
					    m.modifyMap(currentTileX,currentTileY,' ');
                    }
                }
                else if ('o' == i_map[currentTileY][0][currentTileX]) {
                    if (eatingPellets) {
                        //std::cout<<"pellet";
                        collision = true;
					    m.modifyMap(currentTileX,currentTileY,' ');
                    }
                }
            }
        }
    }
    return collision;
}