#pragma once

#include <string>
#include <cstdlib>

class BSTNode{
    public:
        BSTNode();
        BSTNode(int newContents);
        ~BSTNode();
        
        void setContents(int newContents);
        int getContents() const;
        int& getContents();
        
        void setLeftChild(BSTNode *newLeftChild);
        BSTNode* getLeftChild() const;
        BSTNode*& getLeftChild();
        
        void setRightChild(BSTNode *newRightChild);
        BSTNode* getRightChild() const;
        BSTNode*& getRightChild();
        
    private:
        BSTNode *leftChild;
        BSTNode *rightChild;
        int contents;
};