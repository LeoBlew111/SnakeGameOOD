#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player();
        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        //FIXME need more actions
        //after inserting head but before remove tail
        //check if player new head pos collides with food
        //if yes, increment score, do not remove tail, generate new tail
        //else remove tail (carry on as usual)
        void movePlayer();


        //FIXME add self collision check
        // if collide set loseflaf and exitflag both to true (through GM)
        //this will break program loop and end game
        //if ending, you need to differentiate if lost or won (with their messages)

    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif