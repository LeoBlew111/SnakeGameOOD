#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"

using namespace std;

// Global consts
#define DELAY_CONST 100000

GameMechs* gameMechanics;
Player* player;

// set gameMechanics as instance of GameMechs
void Initialize();
void RunGameLoop();
void CleanUp();
void drawScreen();


int main(void)
{
    Initialize();

    RunGameLoop();

    CleanUp();

    return 0;
}

void Initialize()
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Initialize the game mechanics
    gameMechanics = new GameMechs();
    //gameMechanics.initalizeBorder();      FIXME

    player = new Player(gameMechanics);

    gameMechanics->generateRandomFood(player->getPlayerPos());
}

void RunGameLoop()
{
    while (!gameMechanics->getExitFlagStatus())
    {
        // Run game logic
        gameMechanics->runLogic();

        // Draw screen
        drawScreen();

        // Update player move direction
        player->updatePlayerDir();

        // Update player position
        player->movePlayer();

        // Loop delay
        MacUILib_Delay(DELAY_CONST);
    }

    // Display end-game messages using gameMechanics methods if needed
}

//main draw
void drawScreen()       //FIXME change gamMech to pass in by ref to reduce copying
{
    int boardSizeX = gameMechanics->getBoardSizeX();
    int boardSizeY = gameMechanics->getBoardSizeY();
    int borderArraySize = (2* boardSizeX) + ( 2* (boardSizeY - 2));

    bool drawn;

    objPosArrayList* playerBody = player->getPlayerPos();
    objPos tempBody;

    objPos foodPos;
    foodPos = objPos();
    gameMechanics->getFoodPosition(foodPos);  // Retrieve food position

    MacUILib_clearScreen();  
    for (int i = 0; i < boardSizeY; i++)      //rows or y values
    {
        for(int j = 0; j < boardSizeX; j++)       //columns or x values
        {
            drawn = false;

            //iterate through player body list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if( (tempBody.x == j) && (tempBody.y == i) )
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn)
            {
                continue;       //if player drawn, dont draw anything else
            }

            
            if (i == foodPos.y && j == foodPos.x) {
                MacUILib_printf("%c", foodPos.symbol);
            }
            
            //FIXME implement print collectables
            else if ( ( (i == 0) || (i == (boardSizeY - 1) ) ) || ( (0 == j) || ( (boardSizeX - 1) == j) ) )
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
}

void CleanUp()
{
    MacUILib_clearScreen();
    MacUILib_uninit();

    delete gameMechanics;
    delete player;

    // Perform any additional cleanup using the game mechanics object proly clear memory
}