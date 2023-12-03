#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;       // Default dir is STOP

    // Inital head position of player
    objPos initalPos;
    initalPos.setObjPos
    (
        (mainGameMechsRef->getBoardSizeX() / 2),       // Set player to middle of board in x
        (mainGameMechsRef->getBoardSizeY() / 2),       // Set player to middle of board in y
        ('*')                                          // Char to represent player
    );

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(initalPos);
    
}
 // THIS DEAFULT CONSTRUCTOR SHOULD NEVER BE USED AS A GAMEMECHS REF IS NECESSARY FOR CORRECT OPERATION
Player::Player()
{
    mainGameMechsRef = nullptr;
    myDir = STOP;
    
    objPos tempPos;
    tempPos.setObjPos
    (
        (-99),       // Set player to middle of board in x
        (-99),       // Set player to middle of board in y
        ('9')        // Char to represent player
    );

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}
Player::~Player()
{
    delete playerPosList;       // Delete list on heap
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;       // Return the reference to the playerPosList
}
void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();      // Get keyboard input
    if(input != (char)0)  // If not null character
    {
        switch(input)
        {                      
            case (char)27:  // Escape key pressed
                mainGameMechsRef->setExitTrue();        // Exit game
                break;
            case 'w':     // w or W key
            case 'W':
                if ( (myDir == LEFT) || (myDir == RIGHT) || (myDir == STOP) )       // Only allow player to switch directions by 90 degrees at a time
                {
                    myDir = UP;
                }
                break;
            case 'a':
            case 'A':
                if ( (myDir == UP) || (myDir == DOWN) || (myDir == STOP))
                {
                    myDir = LEFT;  //a or A key
                }
                break;
            case 's':
            case 'S':
                if ( (myDir == LEFT) || (myDir == RIGHT) || (myDir == STOP) )
                {
                    myDir = DOWN;      //s or S key
                }
                break;
            case 'd':
            case 'D':    
                if ( (myDir == UP) || (myDir == DOWN) || (myDir == STOP) )
                {
                    myDir = RIGHT;     //d or D key
                }
                break;
            default:
                break;
        }

        mainGameMechsRef->clearInput();
    }
}
void Player::movePlayer()
{
    objPos currentHead;
    playerPosList->getHeadElement(currentHead);     // Holding the pos info of current head of player


    int borderXSize = mainGameMechsRef->getBoardSizeX();
    int borderYSize = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if (currentHead.y == (0) )      // If collide with border
            {
                currentHead.y += (borderYSize - 2);      // Wrap player around board from one side to thre other
            }
            break;
        case LEFT:
            currentHead.x--;
            if (currentHead.x == (0) )
            {
                currentHead.x += (borderXSize - 2);      //wrap player around board
            }
            break;
        case DOWN:
            currentHead.y++;
            if (currentHead.y == (borderYSize - 1) )
            {
                currentHead.y -= (borderYSize - 2);      //wrap player around board
            }
            break;
        case RIGHT:
            currentHead.x++;
            if (currentHead.x == (borderXSize - 1) )
            {
                currentHead.x -= (borderXSize - 2);      //wrap player around board
            }
            break;
        default:
            break;
    }

    // To move snake, add head then, and remove tail
    playerPosList->insertHead(currentHead);     // Add head

    // Check food and body collision
    objPos headPos;     // Head pos to see if collided with food
    headPos = objPos();
    playerPosList->getHeadElement(headPos);

    objPos bodySegmentPos;      // Current body segment pos to see if head collided with body (suicide check)
    bodySegmentPos = objPos();

    objPos foodPos;     // Food pos to see if collided with food
    foodPos = objPos();
    mainGameMechsRef->getFoodPosition(foodPos);

    
    if ( (headPos.x == foodPos.x) && (headPos.y == foodPos.y) )     // If collided with food
    {
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateRandomFood(playerPosList);        // Generate new food position
    }
    else        // Only execute this if no food collision
    {
        playerPosList->removeTail();        // Remove tail
    }
    // Suicide check
    for (int i = 1; i < playerPosList->getSize(); i++)      // Iterate through player body
                                                            // GetSize() return human redable index, subtract 1 for array indexing. 
                                                            // Start at index 1 so head is not check against itself 
    {
        playerPosList->getElement(bodySegmentPos, i);
        if ( (headPos.x == bodySegmentPos.x) && (headPos.y == bodySegmentPos.y) )       // If head collide with current body segment
        {
            mainGameMechsRef->setLoseFlag();        // Loose
            mainGameMechsRef->setExitTrue();
            return;
        }
    }
}

