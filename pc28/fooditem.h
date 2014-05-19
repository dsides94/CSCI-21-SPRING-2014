#pragma once

#include "item.h"

#include <cstdlib>
#include <string>

class FoodItem : public Item{
    public:
        FoodItem(std::string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, std::string newUnitOfMeasure = "nounits", float newUnits = 0);
        
        virtual ~FoodItem();
        
        void setCalories(unsigned int newCalories);
        void setUnitOfMeasure(std::string newUnitOfMeasure);
        void setUnits(float newUnits);
        
        unsigned int getCalories() const;
        std::string getUnitOfMeasure() const;
        float getUnits() const;
        
        std::string toString();
    
    private:
        unsigned int calories;
        std::string unitOfMeasure;
        float units;
};