#pragma once

#include <string>
#include <cstdlib>

template <typename T>
class SLNode{
    public:
        /*
         * Default constructor.
         * Initializes nextNodeto NULL.
         */
        SLNode()
        : nextNode(NULL)
        {}
        
        /*
         * Initializes nextNode and prevNode to NULL and contents to the parameter.
         * @param newContents a type that contents is set to.
         */
        SLNode(T newContents)
        : nextNode(NULL),
          contents(newContents)
        {}
        
        /*
         * Default deconstructor that sets nextNode and prevNode to NULL.
         */
        virtual ~SLNode(){
            nextNode = NULL;
        }
        
        /*
         * Set the contents of this node.
         * @param newContents a type that contents is set to.
         */
        void setContents(T newContents){
            contents = newContents;
        }
        
        /*
         * Get the contents of this node.
         * @return a type that is the contents of this node.
         */
        T getContents() const{
            return contents;
        }
        
        /*
         * Set the node that is after this node.
         * @param newNextNode is the node that nextNode is set to.
         */
        void setNextNode(SLNode<T>* newNextNode){
            nextNode = newNextNode;
        }
        
        /*
         * Get the node that is after this node.
         * @return a pointer to an SLNode that is after this node.
         */
        SLNode* getNextNode() const{
            return nextNode;
        }
        
    private:
        SLNode<T> *nextNode;
        T contents;
};