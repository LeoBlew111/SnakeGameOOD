#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

// Global consts
#define DELAY_CONST 100000

// set gameMechanics as instance of GameMechs
void Initialize(GameMechs &gameMechanics);
void RunGameLoop(GameMechs &gameMechanics);
void CleanUp(GameMechs &gameMechanics);


int main(void)
{
    GameMechs gameMechanics;

    Initialize(gameMechanics);

    RunGameLoop(gameMechanics);

    CleanUp(gameMechanics);

    return 0;
}

void Initialize(GameMechs &gameMechanics)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Initialize the game mechanics
    gameMechanics = GameMechs();  
    // more init ?
}

void RunGameLoop(GameMechs &gameMechanics)
{
    while (!gameMechanics.getExitFlagStatus())
    {
        // Input collection
        char userInput = MacUILib_getChar();
        gameMechanics.setInput(userInput);

        // Run game logic
        gameMechanics.RunLogic();

        // Draw screen
        // ... (use gameMechanics methods for drawing dunno if need to add or not ??)

        // Loop delay
        MacUILib_Delay(DELAY_CONST);
    }

    // Display end-game messages using gameMechanics methods if needed
}

void CleanUp(GameMechs &gameMechanics)
{
    MacUILib_clearScreen();
    MacUILib_uninit();

    // Perform any additional cleanup using the game mechanics object proly clear memory
    
}