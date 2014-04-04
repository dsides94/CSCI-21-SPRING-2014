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
    prizes = NULL;
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