#define DEFAULT_BOARD_X_SIZE 20
#define DEFAULT_BOARD_Y_SIZE 10
#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

enum Direction { STOP, UP, DOWN, LEFT, RIGHT };

class GameMechs {
public:
    //define the array of border objects using board x and y size
    objPos border[(2*DEFAULT_BOARD_X_SIZE) + (2*(DEFAULT_BOARD_Y_SIZE))];       //FIXME need to be able to change board size?


    //lose flag and debug       FIXME
    void DebugIncrementScore();
    void DebugSetLoseFlag(); 
        
    void generateRandomFood();
    objPos getFoodPosition();  // Getter for food objPos
    



    // Constructors and Destructor
    GameMechs();
    GameMechs(int boardX, int boardY);
    ~GameMechs();

    // Getter and setter for exit flag
    bool getExitFlagStatus();
    void setExitTrue();

    // Getter and setter for L flag
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

    // Setter method for the debug key
    void setDebugKey(char key);

    // Declaration for the handleDebugKey method
    void handleDebugKey();



private:
    int speed;

    char input;
    bool exitFlag;
    bool loseFlag;
    int score;
    int boardSizeX;
    int boardSizeY;

    objPos foodPos;

    char debugKey;


};

#endif