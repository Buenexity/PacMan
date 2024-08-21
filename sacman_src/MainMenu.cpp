#include "../header/MainMenu.h"

MainMenu::MainMenu(float height, float width) {
    if(!font.loadFromFile("extraFiles/control.ttf")) {
        cout << "No text file to be loaded" << endl;
    }

    //play button
    MMText[0].setFont(font);
    MMText[0].setFillColor(sf::Color::Blue);
    MMText[0].setString("Play Game");
    MMText[0].setCharacterSize(69);
    MMText[0].setPosition(175.0f, 220.0f);

    //Controls
    MMText[1].setFont(font);
    MMText[1].setFillColor(sf::Color::Blue);
    MMText[1].setString("Controls");
    MMText[1].setCharacterSize(69);
    MMText[1].setPosition(175.0f, 320.0f);

    //Credits
    MMText[2].setFont(font);
    MMText[2].setFillColor(sf::Color::Blue);
    MMText[2].setString("Credits");
    MMText[2].setCharacterSize(69);
    MMText[2].setPosition(175.0f, 420.0f);

    //Exit
    MMText[3].setFont(font);
    MMText[3].setFillColor(sf::Color::Blue);
    MMText[3].setString("Quit Game");
    MMText[3].setCharacterSize(69);
    MMText[3].setPosition(175.0f, 520.0f);

    MMText[4].setFont(font);
    MMText[4].setFillColor(sf::Color::Yellow);
    MMText[4].setString("PAC-MAN");
    MMText[4].setCharacterSize(75);
    MMText[4].setPosition(175.0f, 50.0f);

    MMSelected = -1;

}

MainMenu::~MainMenu() {

}

void MainMenu::drawMM(sf::RenderWindow& window) {
    for(int i = 0; i < max_MM; i++) {
        window.draw(MMText[i]);
    }
}

void MainMenu::M_moveUp() {
    MMText[MMSelected].setFillColor(sf::Color::Blue);

    if (MMSelected > 0) { // If not on the first option, move up
        MMSelected--;
    }
    else { // If on the first option, wrap around to the last option
        MMSelected = max_MM - 2;
    }

    MMText[MMSelected].setFillColor(sf::Color::Magenta);
}

void MainMenu::M_moveDown() {
    MMText[MMSelected].setFillColor(sf::Color::Blue);

    if (MMSelected < max_MM - 2) { // If not on the last option, move down
        MMSelected++;
    }
    else { // If on the last option, wrap around to the first option
        MMSelected = 0;
    }

    MMText[MMSelected].setFillColor(sf::Color::Magenta);
}
