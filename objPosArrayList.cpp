#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;      // Set max size of the list
    aList = new objPos[sizeArray];      // Initalize to heap
}
objPosArrayList::~objPosArrayList()
{
    delete[] aList;     // Delete aList and each of its indicies
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList == sizeArray)       // Check if list is full
    {
        return;     // Nothing happens if list is full
    }

    // Push all elements back by one
    // Overwrite the value in i+1 pos with that of value in i pos
    for (int i = sizeList; i > 0 ; i--)
    {
        aList[i].setObjPos(aList[i-1]);
    }

    // aList[0] is ready to be overwritten 
    aList[0] = thisPos;

    sizeList++;
}
void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)          // Check if list is full
    {
        return;     // Nothing happens if list is full
    }
    
    aList[sizeList] = thisPos;      // Simply add item to tail index which is also the list size
    sizeList++;
}
void objPosArrayList::removeHead()
{
    if (sizeList <= 0)      // Check if list has less than or 0 items
    {   
        return;     //Nothing happens if list has less than or 0 items
    }

    //shuffling forward
    //grab the i+1 emelent and overwrite element i
    for (int i = 0; i < (sizeList - 1); i++)
    {
        aList[i] = aList[i+1];
    }
    sizeList--;     // Lazy deletion, doesnt acutally delete last slot, just makes it effectivley unaccesible by negativley incrementing list size
}
void objPosArrayList::removeTail()
{
    if (sizeList <= 0)      // Check if list has less than or 0 items
    {   
        return;     //Nothing happens if list has less than or 0 items
    }
    
    sizeList--;     // Lazy deletion, doesnt acutally delete last slot, just makes it effectivley unaccesible by negativley incrementing list size
}

int objPosArrayList::getSize()
{
    return sizeList;
}
void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}
void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);
}
void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}