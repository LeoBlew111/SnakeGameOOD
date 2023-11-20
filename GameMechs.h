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

    void RunLogic();
    void ChangeDirection(char input);

    //lose flag and debug
    void DebugIncrementScore();
    void DebugSetLoseFlag(); 
    

    // Constructors and Destructor
    GameMechs();
    GameMechs(int boardX, int boardY);
    ~GameMechs();

    // Getter and setter for exit flag
    bool getExitFlagStatus() const;
    void setExitTrue();

    // Getter and setter for L flag
    bool getLoseFlagStatus() const;
    void setLoseFlag();

    // Getter and setter for input
    char getInput() const;
    void setInput(char thisInput);

    // Clear input method
    void clearInput();

    // Getter methods for board dimensions
    int getBoardSizeX() const;
    int getBoardSizeY() const;

    // Getter method for the game score
    int getScore() const;

    // Specialized setter to increment the score
    void incrementScore();

private:
    Direction MOV;
    int speed;

    char input;
    bool exitFlag;
    bool loseFlag;
    int score;
    int boardSizeX;
    int boardSizeY;

    Direction dir_tracker[2]; // temporary direction tracker for no oposite turn

};

#endif