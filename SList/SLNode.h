#pragma once

#include <string>
#include <cstdlib>

class SLNode{
    public:
        SLNode();
        SLNode(int newContents);
        ~SLNode();
        
        void setContents(int newContents);
        int getContents() const;
        
        void setNextNode(SLNode* newNextNode);
        
        SLNode* getNextNode() const;
        
    private:
        SLNode *nextNode;
        int contents;
};