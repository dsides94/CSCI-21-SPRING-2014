#include "box.h"

Box::Box()
: boxNumber(0),
  boxColor("NO COLOR"),
  prizeCapacity(5),
  prizeCount(0),
  prizes(new Prize[prizeCapacity])
{
}

Box::Box(unsigned int newBoxNumber, std::string newBoxColor, unsigned int newPrizeCapacity)
: boxNumber(newBoxNumber),
  boxColor(newBoxColor),
  prizeCapacity(newPrizeCapacity),
  prizeCount(0),
  prizes(new Prize[prizeCapacity])
{
}

Box::~Box()
{
    delete[] prizes;
}

unsigned int Box::getBoxNumber() const
{
    return boxNumber;
}

void Box::setBoxNumber(unsigned int newBoxNumber)
{
    boxNumber = newBoxNumber;
}

std::string Box::getBoxColor() const
{
    return boxColor;
}

void Box::setBoxColor(std::string newBoxColor)
{
    boxColor = newBoxColor;
}

unsigned int Box::getPrizeCapacity() const
{
    return prizeCapacity;
}

unsigned int Box::getPrizeCount() const
{
    return prizeCount;
}

bool Box::addPrize(Prize prize)
{
    if(prizeCount < prizeCapacity){
        prizes[prizeCount] = prize;
        prizeCount++;
        return true;
    }
    else{
        return false;
    }
    
}

Prize Box::getPrize(unsigned int index)
{
    if(index < prizeCapacity){
        return prizes[index];
    }
    else{
        return scratch;
    }
    
}

Prize Box::removePrize(unsigned int index)
{
    if(index < prizeCount){
        prizeCount--;
        Prize removedPrize = prizes[index];
        for(unsigned int i = index; i < prizeCount; i++){
            prizes[i] = prizes[i+1];
        }
        for(unsigned int i = prizeCount; i < prizeCapacity; i++){
            prizes[i] = scratch;
        }
        return removedPrize;
    }
    else{
        return scratch;
    }
    
}

/*
Box (check UNIT TEST for required API)
private data members: boxNumber (unsigned int), boxColor (string), scratch (Prize), prizes (Prize*, for dynamic array), prizeCapacity (unsigned int), prizeCount (unsigned int)
public default constructor: initial values boxNumber (0), boxColor ("NO COLOR"), prizeCapacity (5), prizeCount(0), prizes (array initialized to match prizeCapacity)
public overloaded constructor: parameters for boxNumber, boxColor, prizeCapacity, prizes (array initialized to match prizeCapacity)
public destructor: free memory associated with prizes
public accessors/gets AND mutators/sets for boxNumber, boxColor
public accessor/get ONLY for data members prizeCapacity, prizeCount
public addPrize: parameters prize (Prize), return value (bool); place prize in prizes array if there is space and return true, else return false
public getPrize: parameters index (unsigned int), return value Prize&; return a Prize if index is valid, else return scratch (data member declared in class header)
public removePrize: parameters index (unsigned int), return value Prize; remove and return Prize if index is valid, else return scratch (data member declared in class header)
*/