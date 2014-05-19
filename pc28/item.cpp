#include "item.h"

#include <sstream>

Item::Item(std::string newName, unsigned int newValue)
: name(newName),
  value(newValue)
{}

Item::~Item(){
    
}

void Item::setName(std::string newName){
    name = newName;
}

std::string Item::getName() const{
    return name;
}

void Item::setValue(unsigned int newValue){
    value = newValue;
}

unsigned int Item::getValue() const{
    return value;
}

std::string Item::toString(){
    std::stringstream ss;
    ss << name << ", $" << value;
    return ss.str();
}