#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // Direction state

        // Construcors and destructor
        Player();       // THIS DEAFULT CONSTRUCTOR SHOULD NEVER BE USED AS A GAMEMECHS REF IS NECESSARY FOR CORRECT OPERATION
        Player(GameMechs* thisGMRef);       // Constructor with parameter: reference to the game mechanics obj
        ~Player();

        objPosArrayList* getPlayerPos();        // Get position of player
        void updatePlayerDir();
        void movePlayer();
    private:
        objPosArrayList* playerPosList;     // The list of player segments 
        enum Dir myDir;     // Direction of player

        GameMechs* mainGameMechsRef;
};

#endif