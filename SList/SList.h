#pragma once

#include <string>
#include "SLNode.h"

class SList{
    public:
        /*
         * Default constructor.
         * Initializes head to NULL and size to 0.
         */
        SList();
        
        /*
         * Default deconstructor that deletes all nodes in this list, by
         * calling the clear function.
         */
        ~SList();
        
        /*
         * Adds a node to this list, and set it to the head of the list.
         * @param contents an int that is the contents of the new node.
         */
        void insertHead(int contents);
        
        /*
         * Removes the head node for this list.
         */
        void removeHead();
        
        /*
         * Deletes every node in this list, clearing it.
         */
        void clear();
        
        /*
         * Get the size of this list, which is the number of nodes in it.
         * @return an unsigned int that is the size of this list.
         */
        unsigned int getSize() const;
        
        /*
         * Builds a string representation of the contents of every node in
         * this list.
         * @return a string that is the string representation of this list.
         */
        std::string toString() const;
        
    private:
        SLNode *head;
        unsigned int size;
};