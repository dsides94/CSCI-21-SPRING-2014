#include "magicitem.h"

#include <sstream>

MagicItem::MagicItem(std::string newName, unsigned int newValue, std::string newDescription, unsigned int newManaRequired)
: Item(newName, newValue),
  description(newDescription),
  manaRequired(newManaRequired)
{}

MagicItem::~MagicItem(){
    
}

void MagicItem::setDescription(std::string newDescription){
    description = newDescription;
}

void MagicItem::setManaRequired(unsigned int newManaRequired){
    manaRequired = newManaRequired;
}

std::string MagicItem::getDescription() const{
    return description;
}

unsigned int MagicItem::getManaRequired() const{
    return manaRequired;
}

std::string MagicItem::toString(){
    std::stringstream ss;
    ss << getName() << ", $" << getValue() << ", " << description << ", requires " << manaRequired << " mana";
    return ss.str();
}