#pragma once

#include <string>
#include <cstdlib>

template <typename T>
class DLNode{
    public:
        /*
         * Default constructor.
         * Initializes nextNode and prevNode to NULL.
         */
        DLNode()
        : nextNode(NULL),
          prevNode(NULL)
        {}
        
        /*
         * Initializes nextNode and prevNode to NULL and contents to the parameter.
         * @param newContents a type that contents is set to.
         */
        DLNode(T newContents)
        : nextNode(NULL),
          prevNode(NULL),
          contents(newContents)
        {}
        
        /*
         * Default deconstructor that sets nextNode and prevNode to NULL.
         */
        virtual ~DLNode(){
            nextNode = NULL;
            prevNode = NULL;
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
        void setNext(DLNode<T>* newNextNode){
            nextNode = newNextNode;
        }
        
        /*
         * Set the node that is before this node.
         * @param newNextNode is the new next node.
         */
        void setPrevious(DLNode<T>* newPrevNode){
            prevNode = newPrevNode;
        }
        
        /*
         * Get the node that is after this node.
         * @return a pointer to an SLNode that is after this node.
         */
        DLNode* getNext() const{
            return nextNode;
        }
        
        /*
         * Get the node that is before this node.
         * @return a pointer to an SLNode that is before this node.
         */
        DLNode* getPrevious() const{
            return prevNode;
        }
        
    private:
        DLNode<T> *nextNode;
        DLNode<T> *prevNode;
        T contents;
};