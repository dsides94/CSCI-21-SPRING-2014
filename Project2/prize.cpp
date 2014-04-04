#include "prize.h"

Prize::Prize()
: prizeName("NO NAME"),
  prizeValue(0)
{
}

Prize::Prize(std::string newPrizeName, unsigned int newPrizeValue)
: prizeName(newPrizeName),
  prizeValue(newPrizeValue)
{
}

Prize::~Prize()
{
    
}

std::string Prize::getPrizeName() const
{
    return prizeName;
}

void Prize::setPrizeName(std::string newPrizeName)
{
    prizeName = newPrizeName;
}

unsigned int Prize::getPrizeValue() const
{
    return prizeValue;
}

void Prize::setPrizeValue(unsigned int newPrizeValue)
{
    prizeValue = newPrizeValue;
}

bool operator==(const Prize &p1, const Prize &p2)
{
    return (p1.prizeName == p2.prizeName && p1.prizeValue == p2.prizeValue);
}