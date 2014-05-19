#pragma once

#include <cstdlib>
#include <string>

class Item{
    public:
        Item(std::string newName = "item", unsigned int newValue = 0);
        
        virtual ~Item();
        
        void setName(std::string newName);
        std::string getName() const;
        
        void setValue(unsigned int newValue);
        unsigned int getValue() const;
        
        std::string toString();
    
    private:
        std::string name;
        unsigned int value;
};