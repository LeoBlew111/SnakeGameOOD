#include <iostream>  
#include "GameMechs.h"

// a bunch of emty getter and setter
// Constructors and Destructor
GameMechs::GameMechs() : exitFlag(false), loseFlag(false), score(0), boardSizeX(60), boardSizeY(30) {
    // Additional actions during default construction
}

GameMechs::GameMechs(int boardX, int boardY) : exitFlag(false), loseFlag(false), score(0), boardSizeX(boardX), boardSizeY(boardY) {
    // Additional actions during parameterized construction
}

GameMechs::~GameMechs() {
    // Deallocate any heap data members if needed nothing yet 
}

// Getter and setter for exit flag
bool GameMechs::getExitFlagStatus() const {
    return exitFlag;
}

void GameMechs::setExitTrue() {
    exitFlag = true;
}


bool GameMechs::getLoseFlagStatus() const {
    return loseFlag;
}

void GameMechs::setLoseFlag() {
    loseFlag = true;
}

char GameMechs::getInput() const {
    return input;
}

void GameMechs::setInput(char thisInput) {
    input = thisInput;
}

// Clear input 
void GameMechs::clearInput() {
    input = 0;
}

// Getter methods for board dimensions
int GameMechs::getBoardSizeX() const {
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const {
    return boardSizeY;
}

// Getter method for the game score
int GameMechs::getScore() const {
    return score;
}

//  setter to increment the score
void GameMechs::incrementScore() {
    score++;
    // Add additional logic if needed
}

//PPA import
void GameMechs::RunLogic() {
    if (input != 0) {
        // Debug: press i to increment score press l to set lost
        if (input == 'i') {
            DebugIncrementScore();
        } else if (input == 'l') {
            DebugSetLoseFlag();
        } else {
    
            ChangeDirection(input);
            
        }

        input = 0; 
    }

    dir_tracker[1] = dir_tracker[0];
    dir_tracker[0] = MOV;
}

//PPA import
void GameMechs::ChangeDirection(char input) {
    switch (input) {
        case '\x1B': // esc to exit 
            setExitTrue();
            break;
        case 'w':
            if (MOV != DOWN) {
                MOV = UP;
            }
            break;
        case 's':
            if (MOV != UP) {
                MOV = DOWN;
            }
            break;
        case 'a':
            if (MOV != RIGHT) {
                MOV = LEFT;
            }
            break;
        case 'd':
            if (MOV != LEFT) {
                MOV = RIGHT;
            }
            break;

        default:
            break;
    }

// not sure if need to add direction check for left dont go right etc or not
}

void GameMechs::DebugIncrementScore() {
    incrementScore();
    cout << "Debug: Score Incremented. New Score: " << getScore() << endl;
}

void GameMechs::DebugSetLoseFlag() {
    setLoseFlag();
    cout << "Debug: Lose Flag Set." << endl;
}

