#pragma once

#include <string>
#include "SLNode.h"

class SList{
    public:
        SList();
        ~SList();
        
        void insertHead(int contents);
        void removeHead();
        
        void clear();
        
        unsigned int getSize() const;
        
        std::string toString() const;
        
    private:
        SLNode *head;
        unsigned int size;
};