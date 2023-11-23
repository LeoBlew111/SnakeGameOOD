#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //initalize vars
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
    aList = new objPos[sizeArray];      //initalize to heap
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;     //FIXME need deep delete?
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // check if full
    if(sizeList == sizeArray)
    {
        //cout << "array full.."<< endl;            FIXME need somthing to show full?
        return;
    }

    //pushing all elements back by one
    // overwrite the value in i+1 pos with that of value in i pos
    for (int i = sizeList; i > 0 ; i--)
    {
        aList[i].setObjPos(aList[i-1]);
        //aList[i] = aList[i-1];
    }

    //aList[0] is ready to be overwritten by imcoming value
    aList[0] = thisPos;

    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(sizeList == sizeArray)
    {
        //cout << "array full.."<< endl;            FIXME need somthing to show full?
        return;
    }
    

    aList[sizeArray++] = thisPos;
}

void objPosArrayList::removeHead()
{
    //list empty check
    if (sizeList <= 0)
    {
        //cout << "List empty... " << endl;            FIXME need somthing to show full?
        return;
    }

    //shuffling forward
    //grab the i+1 emelent and overwrite element i
    for (int i = 0; i < (sizeList - 1); i++)
    {
        aList[i] = aList[i+1];
        sizeList--;

        //lazy deletion
        //doesnt acutally delete last slot, just makes it effectivley unaccesible by adjusting sizeList size
    }
}

void objPosArrayList::removeTail()
{
     //list empty chekc
    if (sizeList <= 0)
    {
        //cout << "List empty... " << endl;            FIXME need somthing to show full?
        return;
    }
    
    //lazy deletion again
    sizeList--;
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