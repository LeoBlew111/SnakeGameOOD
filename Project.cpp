#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

//gloabl consts
#define DELAY_CONST 100000

//global vars
bool exitFlag;
objPos border[56];      //FIXME may want to be reference instead?

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;

    //initalize border
    int borderIndex = 0;
    for (int i = 0; i < 10/*FIXME change to fit border size from gameMechanics*/; i++)      //rows or y values
    {
        for(int j = 0; j < 20/*FIXME change to fit border size from gameMechanics*/; j++)       //columns or x values
        {
            if ( ( (i == 0) || (i == (10/*FIXME change to fit border size from gameMechanics*/ - 1) ) ) || ( (0 == j) || ( (20/*FIXME change to fit border size from gameMechanics*/ - 1) == j) ) )
            {
                border[borderIndex] = objPos(j, i, '#');
                borderIndex++;
            }
        }
    }
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    

    for (int i = 0; i < 10/*FIXME change to fit border size from gameMechanics*/; i++)      //rows or y values
    {
        for(int j = 0; j < 20/*FIXME change to fit border size from gameMechanics*/; j++)       //columns or x values
        {
            //FIXME implement print player
            //FIXME implement print collectables
            if ( ( (i == 0) || (i == (10/*FIXME change to fit border size from gameMechanics*/ - 1) ) ) || ( (0 == j) || ( (20/*FIXME change to fit border size from gameMechanics*/ - 1) == j) ) )
            {
                for (int k = 0; k < 56/*FIXME change to fit border size from gameMechanics*/; k++)
                {
                    if ( (border[k].x == j) && (border[k].y == i) )
                    {
                        MacUILib_printf("%c", border[k].symbol);
                    }
                }
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
