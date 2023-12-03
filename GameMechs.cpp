#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs() {
    exitFlag = false; 
    loseFlag = false;
    score = 0;
    input = (char) 0;
    boardSizeX = DEFAULT_BOARD_X_SIZE;
    boardSizeY = DEFAULT_BOARD_Y_SIZE;
    srand(time(NULL));      // Seed rand with parameter: current time
    foodPos = objPos();     // Construct inital food position
}
GameMechs::GameMechs(int boardX, int boardY) {
    exitFlag = false; 
    loseFlag = false;
    score = 0;
    input = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    srand(time(NULL));      // Seed rand with parameter: current time
    foodPos = objPos();     // Construct inital food position
    
}
GameMechs::~GameMechs() {
    // Nothing to delete
}

void GameMechs::generateRandomFood(objPosArrayList* blockOf) {
    
    // Represents if new unique position for food has been found
    bool foundPos = false;

    // The coordinates for the new unique position for the food
    int xPosCandidate;
    int yPosCandidate;

    // The segment of the player body that is currently being compared
    objPos tempBodySegment;
    tempBodySegment = objPos();


    while(!foundPos)
    {
        xPosCandidate = ( (rand() %(boardSizeX - 3) ) + 1 );      // New random coords to try
        yPosCandidate = ( (rand() %(boardSizeY - 2) ) + 1 );      // Only finds coords within playing area of board
        for (int i = 0; i < blockOf->getSize(); i++)        // Iterate through entire passed in objPosArrayList
        {
            blockOf->getElement(tempBodySegment, i);        // Get body segment from passed in objPosArrayList
            
            if ( (xPosCandidate == tempBodySegment.x) && (yPosCandidate == tempBodySegment.y) )     // If candidate coords match body segment coords
            {
                break;      // Break out of for loop and find new candidate coords
            }
            
            // Only reached when candidate coords do not overlap the coords of any segment of the passed in objPosArrayList
            foodPos.setObjPos(xPosCandidate, yPosCandidate, FOOD_CHAR);     // Set the new coords of the food
            foundPos = true;
            break;
        }
    }

    return;
}
void GameMechs::getFoodPosition(objPos &returnPos) {
    returnPos.setObjPos(foodPos);
}

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
    if (MacUILib_hasChar())       // If a keyboard input is caught
    {
        setInput(MacUILib_getChar());     // Set input to caught inptut
    }
    else
    {
        clearInput();
    }

    return input;
}
void GameMechs::setInput(char thisInput) {
    input = thisInput;
}

void GameMechs::clearInput() {
    input = 0;
}

int GameMechs::getBoardSizeX() {
    return boardSizeX;
}
int GameMechs::getBoardSizeY() {
    return boardSizeY;
}

int GameMechs::getScore() {
    return score;
}
void GameMechs::incrementScore() {
    score++;
}

void GameMechs::endGame()
{
    MacUILib_clearScreen();
    

    if (getLoseFlagStatus() == true)
    {
        MacUILib_printf("Game Over! You lost!\n");
    }
    else
    {
        MacUILib_printf("Quitting...\n");
    }
    MacUILib_printf("Your final score: %d\n", getScore());
}