#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../header/pacman.h"
#include "../header/backgroundSounds.h"
#include "../header/map.h"
#include "../header/ghost.h"
#include "../header/MainMenu.h"

using namespace std;

int main() {
    SoundBack backS;
    sf::Font font;
    if(!font.loadFromFile("extraFiles/control.ttf")) {
        cout << "No text file to be loaded" << endl;
    }
    sf::Text text[10];
    float square_size = 21.0f;
    
    sf::RenderWindow MM(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "Main Menu");
    MainMenu mainMenu(MM.getSize().x, MM.getSize().y);
    
    sf::Clock modeTimer;
    sf::Time scatterDuration = sf::seconds(7.0f);
    sf::Time chaseDuration = sf::seconds(20.0f);
    bool isScatterMode = false;

    while(MM.isOpen()){
        sf::Event event;
        while(MM.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                MM.close();
            }

            if(event.type == sf::Event::KeyReleased){
                if((event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::W)) {
                    mainMenu.M_moveUp();
                    break;
                }
                if((event.key.code == sf::Keyboard::Down) || (event.key.code == sf::Keyboard::S)) {
                    mainMenu.M_moveDown();
                    break;
                }
                
                if(event.key.code == sf::Keyboard::Return) 
                {
                    sf::RenderWindow playWindow(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "Pacman");
                    sf::RenderWindow controlWindow(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "Controls");
                    sf::RenderWindow creditWindow(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "Credits");
                    

                    playWindow.setFramerateLimit(60);
                    int initial = 0;
                    int s = 2;

                    // Create Pacman instance with an increased speed (e.g., 5.0f)
                    Pacman myPacman(0, false, false, 0.0f, 0.0f);

                    sf::Color originalRed = sf::Color::Red;
                    sf::Color originalGreen = sf::Color::Green;
                    sf::Color originalCyan = sf::Color::Cyan;
                    sf::Color originalMagenta = sf::Color::Magenta;

                    Map x;
                    Map winMap;
                    Map scoreMap;
                    x.set_Map(1);
                    winMap.set_Map(3);
                    scoreMap.set_Score_Map(x.GetMap());
                    x.draw_Map(playWindow);
                    Ghost ghost1(x.red_ghost_location.x,x.red_ghost_location.y, 4, false, false, originalRed, RED_GHOST); 
                    Ghost ghost2(x.orange_ghost_location.x,x.orange_ghost_location.y, 4, false, false, originalGreen, ORANGE_GHOST); 
                    Ghost ghost3(x.blue_ghost_location.x,x.blue_ghost_location.y, 4, false, false, originalCyan, BLUE_GHOST); 
                    Ghost ghost4(x.pink_ghost_location.x,x.pink_ghost_location.y, 4, false, false, originalMagenta, PINK_GHOST); 
                    myPacman.setPosition(x.pac_location.x, x.pac_location.y);

                    sf::View view(sf::FloatRect(0, -30, 21.0f * square_size, 21.0f * square_size + 59)); // Adjust the FloatRect as needed
                    playWindow.setView(view);
                    myPacman.setPosition(x.pac_location.x, x.pac_location.y);

                    int pressQ = mainMenu.MMpressed();
                    if(pressQ == 0){
                        while(playWindow.isOpen()){
                            sf::Event pEvent;
                            sf::Font livesFont;
                            if(!livesFont.loadFromFile("extraFiles/Score.otf")) {
                                cout << "No Score file" << endl;
                            }
                            sf::Text livesText;
                            sf::Text livesTitle;
                            sf::Text instructText;
                            sf::Text scoreText;
                            sf::Text scorePoints;
                            livesText.setFont(livesFont);
                            livesTitle.setFont(livesFont);
                            instructText.setFont(livesFont);
                            scoreText.setFont(livesFont);
                            scorePoints.setFont(livesFont);
                            livesText.setCharacterSize(14);
                            livesTitle.setCharacterSize(14);
                            instructText.setCharacterSize(12);
                            scoreText.setCharacterSize(14);
                            scorePoints.setCharacterSize(14);
                            livesText.setPosition(60.0f,445.0f);
                            livesTitle.setPosition(10.0f,445.0f);
                            instructText.setPosition(100.0f,-15.0f);
                            scoreText.setPosition(300.0f, 445.0f);
                            scorePoints.setPosition(355.0f, 445.0f);
                            livesTitle.setString("LIVES");
                            scoreText.setString("SCORE ");
                            livesText.setString(to_string(myPacman.getLives()));
                            scorePoints.setString(to_string(myPacman.score));
                            instructText.setString("Press 'ESC' to return to the main menu");
                            while(playWindow.pollEvent(pEvent)){
                                if(pEvent.type == sf::Event::Closed){
                                    playWindow.close();
                                }
                                if(pEvent.type == sf::Event::KeyPressed){
                                    if(pEvent.key.code ==sf::Keyboard::Escape){
                                        playWindow.close();
                                    }
                                }
                            }
                            controlWindow.close();

                            creditWindow.close();
                            playWindow.clear();
                            // winnerWindow.close();

                            vector<vector<string>> maze = x.GetMap();
                            
                            //ghost.target(myPacman.get_X(),myPacman.get_Y(),x);
                            sf::Time timepassed = modeTimer.getElapsedTime();
                            if (timepassed.asSeconds() <= 4.0f) {
                            //playWindow.clear();
                            ghost1.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost2.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost3.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost4.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            }

                            else
                            {
                                if (!isScatterMode && timepassed >= scatterDuration) {
                                 isScatterMode = true;
                                    modeTimer.restart();
                                } else if (isScatterMode && timepassed >= chaseDuration) {
                                    isScatterMode = false;
                                    modeTimer.restart();
                                }
                            

                            if (isScatterMode)
                            {
                            ghost1.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost2.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost3.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            ghost4.target(myPacman.get_X(),myPacman.get_Y(),x,myPacman);
                            }
                               
                            else
                            {
                                ghost1.guard(x, 1, myPacman);
                                ghost2.guard(x, 2, myPacman);
                                ghost3.guard(x, 3, myPacman);
                                ghost4.guard(x, 4, myPacman);

                            }
                            }

                            myPacman.move(maze,x);
                            x.draw_Map(playWindow);
                            ghost1.draw(playWindow);
                            ghost2.draw(playWindow);
                            ghost3.draw(playWindow);
                            ghost4.draw(playWindow);
                            myPacman.draw(playWindow);

                            /* check if pacman hits a ghost */
                            if (!myPacman.getInvincibility()) {
                                if (myPacman.ghost_collision(myPacman, ghost1) || myPacman.ghost_collision(myPacman, ghost2) ||
                                    myPacman.ghost_collision(myPacman, ghost3) || myPacman.ghost_collision(myPacman, ghost4)) {
                                
                                    backS.sackDead();
                                    myPacman.decrementLives();
                                    livesText.setString(to_string(myPacman.getLives()));
                                    sf::sleep(sf::seconds(2.0f));

                                    if (myPacman.getLives() > 0) {
                                        myPacman.setPosition(x.pac_location.x, x.pac_location.y);
                                        myPacman.setCurrentDirection(0);
                                        ghost1.setPosition(x.red_ghost_location.x,x.red_ghost_location.y);
                                        ghost1.setDoor(true);
                                        ghost2.setPosition(x.orange_ghost_location.x,x.orange_ghost_location.y);
                                        ghost2.setDoor(true);
                                        ghost3.setPosition(x.blue_ghost_location.x,x.blue_ghost_location.y);
                                        ghost3.setDoor(true);
                                        ghost4.setPosition(x.pink_ghost_location.x,x.pink_ghost_location.y);
                                        ghost4.setDoor(true);
                                    } else {
                                        playWindow.close();

                                        sf::RenderWindow loserWindow(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "You Win!");

                                        while(loserWindow.isOpen()){
                                            sf::Event loserEvent;
                                            while(loserWindow.pollEvent(loserEvent)){
                                                if(loserEvent.type == sf::Event::Closed){
                                                    loserWindow.close();
                                                }
                                                if(loserEvent.type == sf::Event::KeyPressed){
                                                    if(loserEvent.key.code ==sf::Keyboard::Escape){
                                                        loserWindow.close();
                                                    }
                                                }
                                            }

                                            loserWindow.clear();

                                            text[0].setFont(font);
                                            text[0].setFillColor(sf::Color::Red);
                                            text[0].setString("\n \n                         You Lose! \n \n \n Please hit ESC to return\n to the main menu.");
                                            text[0].setCharacterSize(50);
                                            text[0].setPosition(30.0f, 100.0f);

                                            loserWindow.draw(text[0]);

                                            loserWindow.display();
                                        }
                                    }
                                }
                            }

                            /* check if pacman is powered up*/
                            if (myPacman.getBoosted()) { // if he's powered up, ghosts are scared
                                ghost1.setFrightenedState(true, x);
                                ghost2.setFrightenedState(true, x);
                                ghost3.setFrightenedState(true, x);
                                ghost4.setFrightenedState(true, x);
                                backS.powerUp();
                                myPacman.setBoosted(false); // change him back to normal
                                
                            }
                            if (ghost1.getFrightenedState() && ghost1.boostClock.getElapsedTime() >= ghost1.boostDuration) {
                                ghost1.setFrightenedState(false, x);
                            }
                            if (ghost2.getFrightenedState() && ghost2.boostClock.getElapsedTime() >= ghost2.boostDuration) {
                                ghost2.setFrightenedState(false, x);
                            }
                            if (ghost3.getFrightenedState() && ghost3.boostClock.getElapsedTime() >= ghost3.boostDuration) {
                                ghost3.setFrightenedState(false, x);
                            }
                            if (ghost4.getFrightenedState() && ghost4.boostClock.getElapsedTime() >= ghost4.boostDuration) {
                                ghost4.setFrightenedState(false, x);
                            }

                            //Updating score every time a pellet is eaten
                            if (x.GetMap() != scoreMap.GetMap()) {
                                if (ghost1.getFrightenedState()) {
                                    myPacman.score += 50;
                                }
                                else {
                                myPacman.score += 10;
                                backS.wakawaka();
                                }
                                scorePoints.setString(to_string(myPacman.score));
                                scoreMap.set_Score_Map(x.GetMap());
                            }



                            //When all pellets are eaten, close window and open "You Win!" window
                            if (x.GetMap() == winMap.GetMap()){
                                playWindow.close();
                                // winnerWindow.setView(view);
                                sf::RenderWindow winnerWindow(sf::VideoMode(21.f * square_size * 2, (16.0f + 21.f * square_size) * 2), "You Win!");
                                backS.loadScreen();
                                while(winnerWindow.isOpen()){
                                    sf::Event wEvent;
                                    while(winnerWindow.pollEvent(wEvent)){
                                        if(wEvent.type == sf::Event::Closed){
                                            winnerWindow.close();
                                        }
                                        if(wEvent.type == sf::Event::KeyPressed){
                                            if(wEvent.key.code ==sf::Keyboard::Escape){
                                                winnerWindow.close();
                                            }
                                        }
                                    }
                                    winnerWindow.clear();

                                    text[0].setFont(font);
                                    text[0].setFillColor(sf::Color::Yellow);
                                    text[0].setString("\n \n                         You Win! \n \n \n Please hit ESC to return\n to the main menu.");
                                    text[0].setCharacterSize(50);
                                    text[0].setPosition(30.0f, 100.0f);

                                    winnerWindow.draw(text[0]);

                                    winnerWindow.display();
                                }

                                
                            }

                            playWindow.draw(livesTitle);
                            playWindow.draw(livesText);
                            playWindow.draw(instructText);
                            playWindow.draw(scoreText);
                            playWindow.draw(scorePoints);
                            playWindow.display();

                        }
                    }
                
                    if(pressQ == 1){
                        while(controlWindow.isOpen()){
                            sf::Event cEvent;
                            while(controlWindow.pollEvent(cEvent)){
                                if(cEvent.type == sf::Event::Closed){
                                    controlWindow.close();
                                }
                                if(cEvent.type == sf::Event::KeyPressed){
                                    if(cEvent.key.code ==sf::Keyboard::Escape){
                                        controlWindow.close();
                                    }
                                }
                            }
                            controlWindow.clear();

                            creditWindow.close();
                            playWindow.close();
                            // winnerWindow.close();

                            text[0].setFont(font);
                            text[0].setFillColor(sf::Color::Yellow);
                            text[0].setString("Use your arrow keys to \n move pac-man around \n \n Avoid the ghosts! \n \n Collect all the pellets \n \n Use power pellets to defeat \n the ghosts for a small \n amount of time");
                            text[0].setCharacterSize(50);
                            text[0].setPosition(30.0f, 100.0f);

                            controlWindow.draw(text[0]);

                            controlWindow.display();
                        }
                    }


                    if(pressQ == 2){
                        while(creditWindow.isOpen()){
                            sf::Event cEvent;
                            while(creditWindow.pollEvent(cEvent)){
                                if(cEvent.type == sf::Event::Closed){
                                    creditWindow.close();
                                }
                                if(cEvent.type == sf::Event::KeyPressed){
                                    if(cEvent.key.code ==sf::Keyboard::Escape){
                                        creditWindow.close();
                                    }
                                }
                            }
                            controlWindow.close();
                            creditWindow.clear();
                            playWindow.close();
                            // winnerWindow.close();

                            text[2].setFont(font);
                            text[2].setFillColor(sf::Color::Magenta);
                            text[2].setString("Game made by: \n \tAshton Clark \n \tDylan Tang \n \tKaran Dhawan \n \tKavan Dam \n \tRosendo Marquez \n \n Game Idea credit to: \n \tAtari and Namco Bandai \n \n Thank you for playing!!");
                            text[2].setCharacterSize(50);
                            text[2].setPosition(30.0f, 100.0f);

                            creditWindow.draw(text[2]);

                            creditWindow.display();
                        }
                    }

                    if(pressQ == 3){
                       MM.close();
                       break;
                    }
                }
            }
        }
        MM.clear();
        mainMenu.drawMM(MM);
        MM.display();
    }

    return 0;
}