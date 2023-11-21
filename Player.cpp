#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos( (mainGameMechsRef->getBoardSizeX() / 2), 
                         (mainGameMechsRef->getBoardSizeY() / 2),
                         ('*')      //FIXME     get symbol from somewhere else?
                        );
}


Player::~Player()
{
    // delete any heap members here     FIXME: need any deletion?
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos);
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
    // PPA3 Finite State Machine logic
    int borderXSize = mainGameMechsRef->getBoardSizeX();
    int borderYSize = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    {
        case UP:
            playerPos.y--;
            if (playerPos.y == (0) )
            {
                playerPos.y += (borderYSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case LEFT:
            playerPos.x--;
            if (playerPos.x == (0) )
            {
                playerPos.x += (borderXSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case DOWN:
            playerPos.y++;
            if (playerPos.y == (borderYSize - 1) )
            {
                playerPos.y -= (borderYSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        case RIGHT:
            playerPos.x++;
            if (playerPos.x == (borderXSize - 1) )
            {
                playerPos.x -= (borderXSize - 2);      //wrap player around board
            }
            //moveCount++;          FIXME need moveCount??
            break;
        default:
            break;
    }
}

