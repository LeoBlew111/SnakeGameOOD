#define DEFAULT_BOARD_X_SIZE 30
#define DEFAULT_BOARD_Y_SIZE 15
#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>
#include <iostream>

#include "objPos.h"
#include "MacUILib.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs {
    public:
        // Constructors and Destructor
        GameMechs();
        GameMechs(int boardX, int boardY);      //parameters: wanted board size
        ~GameMechs();

        // Random food generator and position getter
        void generateRandomFood(objPosArrayList* blockOf);      //Parameter: input player objPosArrayList
        void getFoodPosition(objPos &returnPos);

        // Getter and setter for exit flag
        bool getExitFlagStatus();
        void setExitTrue();

        // Getter and setter for lose flag
        bool getLoseFlagStatus();
        void setLoseFlag();

        // Getter and setter and clear for input
        char getInput();
        void setInput(char thisInput);
        void clearInput();

        // Getters for board dimensions
        int getBoardSizeX();
        int getBoardSizeY();

        // Getter and incrementor for the game score
        int getScore();
        void incrementScore();

        // Method for ending game
        void endGame();

    private:
        //consts
        const char FOOD_CHAR = 'o';     // Char used to represent food

        //vars
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        int boardSizeX;
        int boardSizeY;

        //objs
        objPos foodPos;
};

#endif