#define DEFAULT_BOARD_X_SIZE 30
#define DEFAULT_BOARD_Y_SIZE 15
#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

enum Direction { STOP, UP, DOWN, LEFT, RIGHT };
const char FOOD_CHAR = 'o';

class GameMechs {
public:
    //define the array of border objects using board x and y size
    objPos border[(2*DEFAULT_BOARD_X_SIZE) + (2*(DEFAULT_BOARD_Y_SIZE))];       //FIXME need to be able to change board size?


    //lose flag and debug       FIXME
    void DebugIncrementScore();
    void DebugSetLoseFlag(); 

    // Constructors and Destructor
    GameMechs();
    GameMechs(int boardX, int boardY);
    ~GameMechs();

    //random food generator and position getter
    void generateRandomFood(objPosArrayList* blockOf);
    void getFoodPosition(objPos &returnPos);  // Getter for food objPos

    // Getter and setter for exit flag
    bool getExitFlagStatus();
    void setExitTrue();

    // Getter and setter for lose flag
    bool getLoseFlagStatus();
    void setLoseFlag();

    // Getter and setter for input
    char getInput();
    void setInput(char thisInput);

    // Clear input method
    void clearInput();

    // Getter methods for board dimensions
    int getBoardSizeX();
    int getBoardSizeY();

    // Getter method for the game score
    int getScore();

    // Specialized setter to increment the score
    void incrementScore();

    // Main logic
    void runLogic();

    // Initalize border
    void initalizeBorder();


private:
    int speed;

    char input;
    bool exitFlag;
    bool loseFlag;
    int score;
    int boardSizeX;
    int boardSizeY;

    objPos foodPos;

};

#endif