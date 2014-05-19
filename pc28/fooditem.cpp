#include "fooditem.h"

#include <sstream>

FoodItem::FoodItem(std::string newName, unsigned int newValue, unsigned int newCalories, std::string newUnitOfMeasure, float newUnits)
: Item(newName, newValue),
  calories(newCalories),
  unitOfMeasure(newUnitOfMeasure),
  units(newUnits)
{}

FoodItem::~FoodItem(){
    
}

void FoodItem::setCalories(unsigned int newCalories){
    calories = newCalories;
}

void FoodItem::setUnitOfMeasure(std::string newUnitOfMeasure){
    unitOfMeasure = newUnitOfMeasure;
}

void FoodItem::setUnits(float newUnits){
    units = newUnits;
}

std::string FoodItem::getUnitOfMeasure() const{
    return unitOfMeasure;
}

unsigned int FoodItem::getCalories() const{
    return calories;
}

float FoodItem::getUnits() const{
    return units;
}

std::string FoodItem::toString(){
    std::stringstream ss;
    ss.precision(2);
    ss << getName() << ", $" << getValue() << ", " << std::fixed << units << ' ' << unitOfMeasure << ", " << calories << " calories";
    return ss.str();
}