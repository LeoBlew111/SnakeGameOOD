#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Player.h"

using namespace std;

// Global consts
#define DELAY_CONST 100000      // Default delay time in between loop runs

GameMechs* gameMechanics;
Player* player;

void Initialize();
void RunGameLoop();
void CleanUp();
void drawScreen();


int main(void)
{
    // Program initalizes, runs main loop until an exit condition is met, cleans up, then ends.

    Initialize();

    RunGameLoop();

    CleanUp();

    return 0;
}

void Initialize()
{
    // Initalize MacUILib
    MacUILib_init();

    //  Clear screen of text
    MacUILib_clearScreen();

    // Initialize the game mechanics
    gameMechanics = new GameMechs();

    // Initalize the player
    player = new Player(gameMechanics);

    // Generate inital food
    gameMechanics->generateRandomFood(player->getPlayerPos());
}

void RunGameLoop()
{
    while (!gameMechanics->getExitFlagStatus())     // If exit condition is not met
    {
        // Draw screen
        drawScreen();

        // Update player move direction
        player->updatePlayerDir();

        // Update player position
        player->movePlayer();

        // Loop delay
        MacUILib_Delay(DELAY_CONST);
    }

    gameMechanics->endGame();       // End game if condition met
}

void drawScreen()       // Draw border, player, food, and score
{
    int boardSizeX = gameMechanics->getBoardSizeX();
    int boardSizeY = gameMechanics->getBoardSizeY();

    bool playerSegmentDrawn;        // Represents if current player segment has been drawn

    objPosArrayList* playerBody = player->getPlayerPos();       // Get position of player
    objPos tempBodySegment;

    objPos foodPos;
    foodPos = objPos();
    gameMechanics->getFoodPosition(foodPos);  // Retrieve food position
    

    MacUILib_clearScreen();  
    for (int i = 0; i < boardSizeY; i++)      // Rows or y values
    {
        for(int j = 0; j < boardSizeX; j++)       // Columns or x values
        {
            playerSegmentDrawn = false;

            // Iterate through player body list
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBodySegment, k);     // Set tempBodySegment to current player body segment
                if( (tempBodySegment.x == j) && (tempBodySegment.y == i) )
                {
                    MacUILib_printf("%c", tempBodySegment.symbol);      // Print segment
                    playerSegmentDrawn = true;
                    break;      // There can only be one player segment at any set of coords, so break out of for loop
                }
            }
            if(playerSegmentDrawn)
            {
                continue;       // If player segment drawn, dont draw anything else
            }
            
            if (i == foodPos.y && j == foodPos.x) {     // If pos of food     
                MacUILib_printf("%c", foodPos.symbol);      // Draw
                continue;       // Nothing else to print here, continue
            }
            else if ( ( (i == 0) || (i == (boardSizeY - 1) ) ) || ( (0 == j) || ( (boardSizeX - 1) == j) ) )        // If coords of any border component
            {
                MacUILib_printf("#");
            }
            else
            {
                MacUILib_printf(" ");       // Else print space
            }
        }
        MacUILib_printf("\n");      // Go down a line after each row drawn
    }

    MacUILib_printf("Score: %d", gameMechanics->getScore());        // After all rows drawn, drawn score
}

void CleanUp()
{
    MacUILib_uninit();      // Uninitalize MacUILib

    delete gameMechanics;
    delete player;
}