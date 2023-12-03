#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"


class objPosArrayList
{
    private:
        // List components
        objPos* aList;      // The array of objects that stores the info of the list
        int sizeList;       // The size of the list and also acts as the numbr of items in list
        int sizeArray;      // The size of the array that is used to store the list elements

    public:
        // Default constructor and destructor
        objPosArrayList();
        ~objPosArrayList();

        // Methods to insert and remove items from head and tail of list
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        // Getter for size of list
        int getSize();

        // Getters for item at head, tail, and given index of list
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
};

#endif