#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

// Global consts
#define DELAY_CONST 100000

// set gameMechanics as instance of GameMechs
void Initialize(GameMechs &gameMechanics, Player &player);
void RunGameLoop(GameMechs &gameMechanics, Player &player);
void CleanUp(GameMechs &gameMechanics);
void drawScreen(GameMechs &gameMechanics, Player &player);


int main(void)
{
    GameMechs gameMechanics;
    Player player;

    Initialize(gameMechanics, player);

    RunGameLoop(gameMechanics, player);

    CleanUp(gameMechanics);

    return 0;
}

void Initialize(GameMechs &gameMechanics, Player &player)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Initialize the game mechanics
    gameMechanics = GameMechs();
    //gameMechanics.initalizeBorder();      FIXME

    player = Player(&gameMechanics);
}

void RunGameLoop(GameMechs &gameMechanics, Player &player)
{
    while (!gameMechanics.getExitFlagStatus())
    {
        // Run game logic
        gameMechanics.runLogic();

        // Draw screen
        drawScreen(gameMechanics, player);

        // Update player move direction
        player.updatePlayerDir();

        // Update player position
        player.movePlayer();

        // Loop delay
        MacUILib_Delay(DELAY_CONST);
    }

    // Display end-game messages using gameMechanics methods if needed
}

//main draw
void drawScreen(GameMechs &gameMechanics, Player &player)
{
    int boardSizeX = gameMechanics.getBoardSizeX();
    int boardSizeY = gameMechanics.getBoardSizeY();
    int borderArraySize = (2* boardSizeX) + ( 2* (boardSizeY - 2));

    objPos playerPos;

    MacUILib_clearScreen();  

    for (int i = 0; i < boardSizeY; i++)      //rows or y values
    {
        for(int j = 0; j < boardSizeX; j++)       //columns or x values
        {
            player.getPlayerPos(playerPos);
            //FIXME implement print player
            if ( (i == playerPos.y) && (j == playerPos.x) )
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            //FIXME implement print collectables
            else if ( ( (i == 0) || (i == (boardSizeY - 1) ) ) || ( (0 == j) || ( (boardSizeX - 1) == j) ) )
            {
                MacUILib_printf("#");
                
                
                /*  FIXME
                for (int k = 0; k < borderArraySize; k++)
                {
                    if ( (gameMechanics.border[k].x == j) && (gameMechanics.border[k].y == i) )
                    {
                        MacUILib_printf("%c", gameMechanics.border[k].symbol);
                    }
                }
                */
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
}

void CleanUp(GameMechs &gameMechanics)
{
    MacUILib_clearScreen();
    MacUILib_uninit();

    // Perform any additional cleanup using the game mechanics object proly clear memory
}