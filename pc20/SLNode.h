#pragma once

#include <string>
#include <cstdlib>

class SLNode{
    public:
    
        /*
         * Default constructor.
         * Initializes nextNode to NULL and contents to 0.
         */
        SLNode();
        
        /*
         * Initializes contents to the parameter.
         * @param newContents a int that contents is set to.
         */
        SLNode(int newContents);
        
        /*
         * Default deconstructor that sets nextNode to NULL.
         */
        ~SLNode();
        
        /*
         * Set the contents of this node.
         * @param newContents an int that contents is set to.
         */
        void setContents(int newContents);
        
        /*
         * Get the contents of this node.
         * @return an int that is the contents of this node.
         */
        int getContents() const;
        
        /*
         * Set the node that this node points to.
         * @param newNextNode is the node that nextNode is set to.
         */
        void setNextNode(SLNode* newNextNode);
        
        /*
         * Get the node that is node points to.
         * @return a pointer to an SLNode that this node points to.
         */
        SLNode* getNextNode() const;
        
    private:
        SLNode *nextNode;
        int contents;
};