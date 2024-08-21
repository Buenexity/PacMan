#include "../header/ghost.h"

Ghost::Ghost(float initialX, float initialY, int initialDirection, bool hiding, bool dead, sf::Color color, GhostType ghostType)
    : Object(initialX, initialY), GhostMovable(), Drawable(), isHiding(hiding), isDead(dead), currentDirection(initialDirection)
{
    radius = 21.0f / 2;
    ghost.setRadius(radius);
    ghost.setFillColor(color);
    ghost.setPosition(initialX, initialY);
    ghost_speed = 1.0f;
    type = ghostType;
    UseDoor = true;
    initialPos.first = initialX;
    initialPos.second = initialY;
}

bool Ghost::getHidingState() const
{
    return isHiding;
}

void Ghost::setHidingState(bool hiding)
{
    isHiding = hiding;
}

bool Ghost::getDeathStatus() const
{
    return isDead;
}

void Ghost::setDeathStatus(bool dead)
{
    isDead = dead;
}

void Ghost::setDoor(bool usingDoor) {
    UseDoor = usingDoor;
}

bool Ghost::getDoor() {
    return UseDoor;
}

void Ghost::setCurrentDirection(int direction)
{
    currentDirection = direction;
}

int Ghost::getCurrentDirection() const
{
    return currentDirection;
}

float Ghost::getRadius() const {
    return radius;
}

bool Ghost::getFrightenedState() const {
    return isFrightened;
}

void Ghost::setFrightenedState(bool frightened, Map m) {
    isFrightened = frightened;
    sf::Time elapsed = boostClock.getElapsedTime();

    if (isFrightened) {
        boostClock.restart(); // start timer
        ghost.setFillColor(frightenedColor);
        scatter(m);
    }
    else if (elapsed >= boostDuration) {
        // Frightened state duration has elapsed, return to normal
        ghost_speed = 1.0f;   // original speed
        ghost.setFillColor(getOriginalColor());
    }
}

sf::Color Ghost::getOriginalColor() const {
    switch (type) {
        case RED_GHOST:
            return originalRed;
        case BLUE_GHOST:
            return originalCyan;
        case PINK_GHOST:
            return originalMagenta;
        case ORANGE_GHOST:
            return originalGreen;
        default:
            return sf::Color::White; // Default color if type is not recognized
    }
}


const sf::CircleShape& Ghost::getShape() const {
    return ghost;
}

//scatter to individual corners of the map depending on corner int input
//1 - top left
//2 - top right
//3 - bottom left
//4 - bottom right
void Ghost::guard(Map m,int corner,Pacman &p)
{   
    teleport();
    float square_size = 21.0f;
    //top left corner
    pair<float, float> top_left = std::make_pair(square_size, 0.0f);
    //top right corner
    pair<float, float> top_right = std::make_pair(static_cast<float>(square_size * (m.GetMap().size()-2)), 0.0f);
    //bottom left
    pair<float, float> bottom_left = std::make_pair(square_size,float(square_size * (m.GetMap().size()-1)));
    //bottom right
    pair<float, float> bottom_right = std::make_pair(float(square_size * (m.GetMap().size()-2)),float(square_size * (m.GetMap().size()-1)));

    switch (corner)
    {
    case 1:
        target_coords(top_left.first,top_left.second,m);
        break;
    case 2:
        target_coords(top_right.first,top_right.second,m);
        break;
    case 3:
        target_coords(bottom_left.first,bottom_left.second,m);
        break;
    case 4:
        target_coords(bottom_right.first,bottom_right.second,m);
        break;
    }
}

bool Ghost::teleport() 
{
    const float max_c = 21.0f * 21.0f;

    if(x_coordinate > (max_c)-.5f)
    {
        x_coordinate = 0;
        return true;
    }

    if (x_coordinate < 0.0f) 
    {
        x_coordinate = max_c;
        return true;
    }

    return false;
}

/*

    Scatter Function, make the ghost pick out random moves as long as they are no walls

*/

void Ghost::scatter(Map m) 
{
    
        std::vector<std::pair<float, float>> dir = {
        std::make_pair(x_coordinate + ghost_speed, y_coordinate),    // move right
        std::make_pair(x_coordinate, y_coordinate - ghost_speed),    // move down
        std::make_pair(x_coordinate, y_coordinate + ghost_speed),    // move up
        std::make_pair(x_coordinate - ghost_speed, y_coordinate)      // move left
    };

    int oppositeDirection = getOppositeDirection();
    if (oppositeDirection > 0 && oppositeDirection <= dir.size()) {
        dir.erase(dir.begin() + oppositeDirection - 1);
    }

    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, dir.size() - 1);
    int randomNumber = dist(gen);

    target_coords(dir[randomNumber].first, dir[randomNumber].second, m);
}



void Ghost::target_coords(float pacmanX, float pacmanY, Map m)
{
    bool doors = false;
    if(type != RED_GHOST)
    {
        doors = true;
    }
     teleport();

    std::vector<std::vector<std::string>> maze = m.GetMap();

    //possible move array
    vector<pair<float, float>> possibleMoves = 
    {
        std::make_pair(x_coordinate + ghost_speed, y_coordinate),
        std::make_pair(x_coordinate, y_coordinate - ghost_speed),
        std::make_pair(x_coordinate, y_coordinate + ghost_speed),
        std::make_pair(x_coordinate - ghost_speed, y_coordinate)
    };

    //collide function
    collisions collide;

    //array of walls
    std::array<bool, 4> walls 
    {
        collide.map_collision(0, doors, ghost_speed + x_coordinate, y_coordinate, maze,m),
        collide.map_collision(0, doors, x_coordinate, y_coordinate - ghost_speed, maze,m),
        collide.map_collision(0, doors, x_coordinate, y_coordinate + ghost_speed, maze,m),
        collide.map_collision(0, doors, x_coordinate - ghost_speed, y_coordinate, maze,m)
    };
    //opposite direction
    int behind = getOppositeDirection()-1;
    // Calculate distances to Pacman for each possible move
    std::array<float, 4> distances;
    float minDistance = std::numeric_limits<float>::max();
    int minIndex = 0;
    bool allMovesBlocked = true;
    for (int i = 0; i < possibleMoves.size(); i++) 
    {
        // Get x and y coordinates
        float vector_X = pacmanX - possibleMoves[i].first;
        float vector_Y = pacmanY - possibleMoves[i].second;

        // Pythagorean theorem to get the distance from each spot
        distances[i] = std::sqrt(vector_X * vector_X + vector_Y * vector_Y);

        //Ignore the direction behind of ghost
        //Ghost cant move backwards
         if (i == behind || walls[i]) 
        {
            distances[i] = std::numeric_limits<float>::max(); 
        } 
        else 
        {
            allMovesBlocked = false; 
        }

        // Check for the shortest distance to pacman
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
                 }
    }
     if(!allMovesBlocked)
    {
    currentDirection = minIndex + 1;
    x_coordinate = static_cast<float>(possibleMoves[minIndex].first);
    y_coordinate = static_cast<float>(possibleMoves[minIndex].second);
    }
    else 
    {
    //we flip the ghost around so he dosent get stuck
    currentDirection = getOppositeDirection()-1;
    }

}





    // int currentDirection;
    // 1 - right
    // 2 -down
    // 3- up
    // 4 - left

void Ghost::target(float pacmanX, float pacmanY, Map m, Pacman &p) 
{
    
    std::vector<std::vector<std::string>> maze = m.GetMap();

    //possible move array
    vector<pair<float, float>> possibleMoves = 
    {
        std::make_pair(x_coordinate + ghost_speed, y_coordinate),
        std::make_pair(x_coordinate, y_coordinate - ghost_speed),
        std::make_pair(x_coordinate, y_coordinate + ghost_speed),
        std::make_pair(x_coordinate - ghost_speed, y_coordinate)
    };

    //collide function
    collisions collide;
    std::array<bool, 4> walls 
    {
        collide.map_collision(0, 0, ghost_speed + x_coordinate, y_coordinate, maze,m),
        collide.map_collision(0, 0, x_coordinate, y_coordinate - ghost_speed, maze,m),
        collide.map_collision(0, 0, x_coordinate, y_coordinate + ghost_speed, maze,m),
        collide.map_collision(0, 0, x_coordinate - ghost_speed, y_coordinate, maze,m)
    };

if (UseDoor && type != RED_GHOST) {
    target_coords(m.door_position.x, m.door_position.y, m);
    if (x_coordinate == m.door_position.x && y_coordinate == m.door_position.y - 21.0f) 
    {
        UseDoor = false; // Corrected assignment operator
    }
    return;
}





    //opposite direction
    int behind = getOppositeDirection()-1;
    // Calculate distances to Pacman for each possible move
    std::array<float, 4> distances;
    float minDistance = std::numeric_limits<float>::max();
    int minIndex = 0;
    bool allMovesBlocked = true;

    /*
        RED GHOST - follows pacman directly 
    */
   if(type == RED_GHOST)
{
    target_coords(p.get_X(),p.get_Y(),m);
    return;
}

    /*
        Blue GHOST - moves randomally
    */
    if(type == BLUE_GHOST)
     {
         scatter(m);
         return;
     }

     
     /*
        Pink Ghost- target 2+ cells in sacman's direction
     */
if (type == PINK_GHOST)
{
    int pac_dir = p.getCurrentDirection();
    float targetX = pacmanX;
    float targetY = pacmanY;

    switch (pac_dir)
    {
        case 1: // Right
            targetX += 2 * 21.0f;
            break;
        case 2: // Up
            targetY -= 2 * 21.0f;
            break;
        case 3: // Down
            targetY += 2 * 21.0f;
            break;
        case 4: // Left
            targetX -= 2 * 21.0f;
            break;
    }

    for (int i = 0; i < possibleMoves.size(); i++)
    {
        float vector_X = targetX - possibleMoves[i].first;
        float vector_Y = targetY - possibleMoves[i].second;

        // Pythagorean theorem to get the distance from each spot
        distances[i] = std::sqrt(vector_X * vector_X + vector_Y * vector_Y);

        // Ignore the direction behind of ghost
        // Ghost can't move backwards
        if (i == behind || walls[i])
        {
            distances[i] = std::numeric_limits<float>::max();
        }
        else
        {
            allMovesBlocked = false;
        }

        // Check for the shortest distance to the target position
        if (distances[i] < minDistance)
        {
            minDistance = distances[i];
            minIndex = i;
        }
    }

}

    if(type == ORANGE_GHOST)
    {
        float distanceToPacman = 4.0f*21;
        float dist_x = x_coordinate - p.get_X();
        float dist_y = y_coordinate - p.get_Y();
        //if dist to pacman is < 4 go into guard mode
        float hypotenuse_dist = std::sqrt(dist_x * dist_x + dist_y * dist_y);
        if(hypotenuse_dist <= distanceToPacman)
        {
            int guard_corner = 1;
            guard(m,guard_corner,p);
            return;
        }
        //target pacman normally
        else
        {
              for (int i = 0; i < possibleMoves.size(); i++) 
        {   
        // Get x and y coordinates
        float vector_X = pacmanX - possibleMoves[i].first;
        float vector_Y = pacmanY - possibleMoves[i].second;

        // Pythagorean theorem to get the distance from each spot
        distances[i] = std::sqrt(vector_X * vector_X + vector_Y * vector_Y);

        //Ignore the direction behind of ghost
        //Ghost cant move backwards
         if (i == behind || walls[i]) 
        {
            distances[i] = std::numeric_limits<float>::max(); 
        } 
        else 
        {
            allMovesBlocked = false; 
        }

        // Check for the shortest distance to pacman
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    
    
     }

        }
    }
   
    // Move ghost based on the shortest distance to Pacman
    
    if(!allMovesBlocked)
    {
    currentDirection = minIndex + 1;
    x_coordinate = static_cast<float>(possibleMoves[minIndex].first);
    y_coordinate = static_cast<float>(possibleMoves[minIndex].second);
    }
    else
    {
    //we flip the ghost around so he dosent get stuck
    currentDirection = getOppositeDirection()-1;
    }
    teleport();
    
   
    
}



int Ghost::getOppositeDirection() 
{
    int oppositeDirection = 0;
    // Switch case statement for opposite direction
    switch (currentDirection) {
        case 0:
            oppositeDirection = 0;
            break;
        case 1: // right -> left
            oppositeDirection = 4;
            break;
        case 2: // down -> up
            oppositeDirection = 3;
            break;
        case 3: // up -> down
            oppositeDirection = 2;
            break;
        case 4: // left -> right
            oppositeDirection = 1;
            break;
        default:
            break;
    }
    return oppositeDirection;
}


void Ghost::draw(sf::RenderWindow& window) 
{
    sf::Sprite sprite;
    sf::Texture texture;

    int offset = 5;
    sprite.setPosition(x_coordinate - offset, y_coordinate - offset);

    // Choose the texture based on the ghost type
    std::string textureFile;
    switch (type) {
        case RED_GHOST:
            textureFile = "extraFiles/ghost_red_animation.png";
            break;
        case BLUE_GHOST:
            textureFile = "extraFiles/ghost_cyan_animation.png";
            break;
        case PINK_GHOST:
            textureFile = "extraFiles/ghost_pink_animation.png";
            break;
        case ORANGE_GHOST:
            textureFile = "extraFiles/ghost_orange_animation.png";
            break;
        default:
            textureFile = "extraFiles/ghost_red_animation.png"; // Use a default texture for unrecognized types
            break;
    }

    // afraid texture
    if (isFrightened) {
        textureFile = "extraFiles/ghost_afraid_animation.png";
    }

    texture.loadFromFile(textureFile);
    int tileLength = 32;

    sprite.setTexture(texture);

    sprite.setTextureRect(sf::IntRect(0, tileLength * currentDirection - tileLength, tileLength, tileLength));

    window.draw(sprite);
}