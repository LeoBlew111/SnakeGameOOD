#include <iostream>  
#include "GameMechs.h"
#include "MacUILib.h"
#include <cstdlib>  // Include this for rand()



// a bunch of emty getter and setter
// Constructors and Destructor
GameMechs::GameMechs() {
    // Additional actions during default construction
    exitFlag = false; 
    loseFlag = false;
    score = 0;
    input = 0;
    speed = 1;
    boardSizeX = DEFAULT_BOARD_X_SIZE;
    boardSizeY = DEFAULT_BOARD_Y_SIZE;

    /*int speed;

    char input;
    bool exitFlag;
    bool loseFlag;
    int score;
    int boardSizeX;
    int boardSizeY;*/
}

void GameMechs::generateRandomFood() {
    int randomX = rand() % (boardSizeX - 2) + 1;
    int randomY = rand() % (boardSizeY - 2) + 1;
    foodPos.setObjPos(randomX, randomY, 'O');  // Assuming 'F' is the symbol for food
}

objPos GameMechs::getFoodPosition() {
    return foodPos;
}




GameMechs::GameMechs(int boardX, int boardY) {
    // Additional actions during parameterized construction
    exitFlag = false; 
    loseFlag = false;
    score = 0;
    input = 0;
    speed = 1;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

GameMechs::~GameMechs() {
    // Deallocate any heap data members if needed nothing yet 
}

// Getter and setter for exit flag
bool GameMechs::getExitFlagStatus() {
    return exitFlag;
}

void GameMechs::setExitTrue() {
    exitFlag = true;
}


bool GameMechs::getLoseFlagStatus() {
    return loseFlag;
}

void GameMechs::setLoseFlag() {
    loseFlag = true;
}

char GameMechs::getInput() {
    if (MacUILib_hasChar())       //if have a char
    {
        setInput(MacUILib_getChar());     //set input to user input     
    }
    else        //redundant for readability
    {
        clearInput();
    }

    return input;
}

void GameMechs::setInput(char thisInput) {      //setter for given char
    input = thisInput;
}

// Clear input 
void GameMechs::clearInput() {
    input = 0;
}

// Getter methods for board dimensions
int GameMechs::getBoardSizeX() {
    return boardSizeX;
}

int GameMechs::getBoardSizeY() {
    return boardSizeY;
}

// Getter method for the game score
int GameMechs::getScore() {
    return score;
}

//  setter to increment the score
void GameMechs::incrementScore() {
    score++;
    // Add additional logic if needed
}

void GameMechs::runLogic() {        //FIXME need this?
       
}

void GameMechs::initalizeBorder()       //FIXME     dont need anymore
{
    //int borderArraySize = (2*boardSizeX) + ( 2* (boardSizeY - 2)) ;
    //border[borderArraySize];

    int borderIndex = 0;
    for (int i = 0; i < boardSizeY; i++)      //rows or y values
    {
        for(int j = 0; j < boardSizeX; j++)       //columns or x values
        {
            if ( ( (i == 0) || (i == (boardSizeY - 1) ) ) || ( (0 == j) || ( (boardSizeX - 1) == j) ) )
            {
                border[borderIndex] = objPos(j, i, '#');
                borderIndex++;
            }
        }
    }
}

void GameMechs::DebugIncrementScore() {
    incrementScore();
    cout << "Debug: Score Incremented. New Score: " << getScore() << endl;
}

void GameMechs::DebugSetLoseFlag() {
    setLoseFlag();
    cout << "Debug: Lose Flag Set." << endl;
}

void GameMechs::setDebugKey(char key) {
    debugKey = key;
}

void GameMechs::handleDebugKey() {
    if (getInput() == 'g') {  //g is debug
        generateRandomFood();
    }
}
