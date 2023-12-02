#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos
    (
        (mainGameMechsRef->getBoardSizeX() / 2),       //set player to middle of board in x
        (mainGameMechsRef->getBoardSizeY() / 2),       //set player to middle of board in y
        ('*')                                          //FIXME     get symbol from somewhere else?
    );

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    
}

Player::Player()        //this constructor should never be used, it exists just for object defenition purposes in main
{
    mainGameMechsRef = nullptr;
    myDir = STOP;
    
    objPos tempPos;
    tempPos.setObjPos
    (
        (-99),       //set player to middle of board in x
        (-99),       //set player to middle of board in y
        ('9')      //FIXME     get symbol from somewhere else?                                       //FIXME     get symbol from somewhere else?
    );

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
}

Player::~Player()
{
    // delete any heap members here     FIXME: need any deletion?
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case (char)27:  //escape key pressed
                mainGameMechsRef->setExitTrue();
                break;
            /*                                          FIXME: speed change?
            case (char)9:       //TAB key pressed
                gameSpeedMultiplier++;
                if (gameSpeedMultiplier > 5)
                {
                    gameSpeedMultiplier = 1;
                }
                break;
            */
            case 'w':     //w or W key
            case 'W':
                if ( (myDir == LEFT) || (myDir == RIGHT) || (myDir == STOP) )
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
        input = 0;
        mainGameMechsRef->clearInput();
    }
}

void Player::movePlayer()
{
    objPos currentHead;     //holding the current pos info of current head
    playerPosList->getHeadElement(currentHead);


    // PPA3 Finite State Machine logic
    int borderXSize = mainGameMechsRef->getBoardSizeX();
    int borderYSize = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    {
        case UP:
            currentHead.y--;
            if (currentHead.y == (0) )
            {
                currentHead.y += (borderYSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case LEFT:
            currentHead.x--;
            if (currentHead.x == (0) )
            {
                currentHead.x += (borderXSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case DOWN:
            currentHead.y++;
            if (currentHead.y == (borderYSize - 1) )
            {
                currentHead.y -= (borderYSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case RIGHT:
            currentHead.x++;
            if (currentHead.x == (borderXSize - 1) )
            {
                currentHead.x -= (borderXSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        default:
            break;
    }

    //new current head should be inserted to head of posList, then remove tail
    playerPosList->insertHead(currentHead);

    //check if food collision
    objPos headPos;
    headPos = objPos();
    playerPosList->getHeadElement(headPos);

    objPos bodySegmentPos;
    bodySegmentPos = objPos();

    objPos foodPos;
    foodPos = objPos();
    mainGameMechsRef->getFoodPosition(foodPos);

    
    if ( (headPos.x == foodPos.x) && (headPos.y == foodPos.y) )
    {
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateRandomFood(playerPosList);
    }
    else
    {
        playerPosList->removeTail();
    }
    for (int i = 1; i < playerPosList->getSize(); i++)      //getSize() return human redable index, subtract 1 for array indexing. 
                                                            //start at index 1 so head is not check against itself 
    {
        playerPosList->getElement(bodySegmentPos, i);
        if ( (headPos.x == bodySegmentPos.x) && (headPos.y == bodySegmentPos.y) && (myDir != STOP) )
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return;
        }
    }
}

