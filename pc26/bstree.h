#pragma once

#include <string>
#include <cstdlib>
#include "BSTNode.h"

class BSTree{
    public:
        BSTree();
        ~BSTree();
        
        bool insert(int contents);
        
        void clear();
        
        unsigned int getSize() const;
        
        void inOrder();
        
    private:
        BSTNode *root;
        int size;
        
        bool insert(int contents, BSTNode *&root);
        
        void clear(BSTNode *&root);
        
        void inOrder(BSTNode *&root);
};