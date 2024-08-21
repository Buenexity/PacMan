# Sack-Man
 
 > Authors: [Ashton Clark](https://github.com/MinionTorturer3), [Kavan Dam](https://github.com/KavanDam), [Dylan Tang](https://github.com/TangDylan1), [Karan Dhawan](https://github.com/kdhaw001), [Rosendo Marquez](https://github.com/Buenexity)
## Project Description
 > * Interest: We decided to make a Pac-Man parody game because all of us growing up played the game at arcades and at home.
 > * Languages and tools: We plan to use C++ and VSCode for the project.
 > * Input/Output: Inputs that are expected for the project are input to play and quit the game, and arrow keys or W, A, S, and D to move the character around. Outputs that are expected are character movements, game text (i.e. WINNER, Click to play), display of the actual game (such as character and map), a GUI for the main menu, and a guide on the controls.
 > * Features: Unique AI for the ghosts, edge teleporting when the furthest point is reached, and a way to avoid the ghosts through collectable power-ups

## User Interface Specification

### Navigation Diagram
![Sac-Man Navigation Drawing](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/410d1b88-072a-41b6-bcb6-36802272dafe)

> The User Navigation Diagram outlines all the screens the user can encounter when moving across the game program. From the start menu, the user can access the credits screen, controls screen, and exit the game.
> Furthermore, the user can start the game from the menu to play "Sacman". At any point, the user can stop the game and go back to the menu with the press of a button. Once the user runs out of lives, they will be
> prompted with a Game Over screen and can press ESC to return to the menu. If the user eats all the pellets, they will be prompted with a You Win screen and can press ESC to return to the menu.

### Screen Layouts
![Copy of Sack-Man UML Drawing](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/0cb523d9-1049-4412-9b7d-86d414359867)



## Class Diagram
![Sack-Man UML Drawing](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/146399114/2d0b7747-61d2-4862-93ae-2cc23603be63)


> Class Descriptions:

> * Main: Includes the main menu of the game, as well as buttons to navigate throughout the game, such as a play, leaderboard, or quit button. This is where most of the other classes will branch from.
> * Leaderboard: Holds the player's name, rank, and score on a leaderboard that can be viewed at the main menu of the game.
> * Credits: Includes the names of the developers that worked on this project.
> * Game Engine: Will generate the maps and characters of the game for the player to move around and complete their objectives.
> * Character: Encompasses the character the player will get to control, and the ghosts that will try to collide with the player to make them lose lives.
> * Ghost: Non playable characters whose goal is to collide with the player to make them lose lives.
> * Sack Man: the playable character of this game that the player will get to control. Their goal is to collect all the orbs across the map and progress to the next level
> * Sounds: Includes any sound that will be included in the game. Some sounds include an eating sound when sack man eats an orb, or a sound when sack man dies.
> * Collisions: Handles the collisions that may occur when the player or ghost reaches a wall, or when the player and ghost collide, or when sack man collides with an orb (sack man eats the orb)
> * Maps: This includes the different maps that a player will be able to play on, and this class should set up the map to be playable.
> * Object: Includes some other various objects that are included in the game, such as fruit or the walls of the map.


OLD UML DIAGRAM
![Sack-Man UML Drawing (1)](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/120551095/e7397129-2433-4f95-bef2-b818b2b7341d)


Single Responsibility Principle:
>With the addition of the the EasyMap, MediumMap, and HardMap, being inherited from the Map class this falls under the Single Responsibility Principle. This is because instead of the map class having to do every little thing for each of the options, by separating them it allows for each class to specialize in the different maps. While each of the map classes have the same public functions, this in turn decluttered the code, which before was extremely cluttered with all three different maps being in the same class. This helped our code because it allowed for easier access to change small details for each of the maps, so if there is an issue with one map size, it would not affect the other maps and it allows selecting the map choice for the user easier.

Interface Segregation Principle
>The Pacman and Ghost class implementing the "Move" and "Draw" interfaces aligns with the Interface Segregation Principle. It does this by providing the classes with an interface to only implement the methods that correspond to the classes. Pacman only uses the move function to move across the map while the target method is used by ghosts to move to Pacman. This makes our code better as it reduces unnecessary dependencies within our classes and improves clarity.

 
 ## Screenshots
![pacman_1](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/540d330f-9751-478c-94dd-cc1b0437e2de)
![pacman_2](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/99eff8fc-9d2a-48f7-a84e-2413b10a7782)
![pacman_3](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/c28979af-d548-4737-ab59-2463534f36ec)
![pacman_4](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/19af33ca-07f2-4366-8c3a-cde8be5f78c3)
![pacman_5](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/58598b77-0d0d-4e7f-8646-bfa64b316401)
![pacman_6](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/9f565f35-6c89-470e-bf7f-27f35e395af5)
![pacman_7](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/117532440/def6e174-fa2b-48d0-af1d-dad4515ebc4e)



 ## Installation/Usage
 1) Only runs for window computers <br>
  Install Cmake: https://cmake.org/download <br>
  Install Mingw32: https://sourceforge.net/projects/mingw-w64/
 4) Set up Cmake and Mingw32 as Enviromental Variables <br>
 ![image](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/120551095/140477f0-36cd-4aee-b24c-7dbe8131d07b)
 5) Clone this repository in Vscode or IDE
 6) In the terminal run <mingw32-make.exe> to build the executables in the "build" folder
 7) To run game executable enter: <.\build\main.exe> in terminal
 8) To run testing executable enter: <.\build\test.exe> in terminal


 ## Testing
 How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 We tested our project with Catch2, a C++ testing framework similar to Google Test (gtest). We were given permission by Lawrence Wang to use Catch2 instead of Google test due to our unique 
 circumstances. 
 There are unit tests for every testable function, including but not limited to: Map initialization, Pacman/Ghost movement and targeting, collisions, etc...
 For example, there are unit tests to check whether a collision occurs when Pacman intersects with a pellet, a wall, a ghost, and an energizer. If Pacman intersects with a ghost, there should be a 
 collision and one of Pacman's lives should be lost. There are over 30 total unit tests that validate 78 different values and conditions throughout the program.
 SCREENSHOT: ![image](https://github.com/cs100/final-project-kdam004-dtang041-aclar064-kdhaw001/assets/146399114/c49d5e63-bb80-4bfd-985b-dd2d185179ab)

 
