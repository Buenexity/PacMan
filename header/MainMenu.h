#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

const int max_MM = 5;

class MainMenu {
    public: 
        MainMenu(float height, float width);
        void drawMM(sf::RenderWindow& window);
        void M_moveUp();
        void M_moveDown();
        int MMpressed() {
            return MMSelected;
        }
        ~MainMenu();
        
    private:
        int MMSelected;
        sf::Font font;
        sf::Text MMText[max_MM];
};