#pragma once

#include "item.h"

#include <cstdlib>
#include <string>

class MagicItem : public Item{
    public:
        MagicItem(std::string newName = "magicitem", unsigned int newValue = 0, std::string newDescription = "no description", unsigned int newManaRequired = 0);
        
        virtual ~MagicItem();
        
        void setDescription(std::string newDescription);
        void setManaRequired(unsigned int newManaRequired);
        
        std::string getDescription() const;
        unsigned int getManaRequired() const;
        
        std::string toString();
    
    private:
        std::string description;
        unsigned int manaRequired;
};