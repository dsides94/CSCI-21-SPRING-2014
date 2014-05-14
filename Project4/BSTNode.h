#pragma once

#include <string>
#include <cstdlib>

template <typename T>
class BSTNode{
    public:
    
        /*
         * Overloaded Constructor.
         * Sets the left and right child nodes to NULL, and data to newData
         * @param newData the data for this node.
         */
        BSTNode(T newData)
        : leftChild(NULL),
          rightChild(NULL),
          data(newData)
        {}
        
        /*
         * Default Destructor
         */
        virtual ~BSTNode(){
            
        }
        
        /*
         * Sets the data for this node.
         * @param newData the new data for this node.
         */
        void setData(T newData){
            data = newData;
        }
        
        /* 
         * Gets the data for this node.
         * @return the data for this node.
         */
        T getData() const{
            return data;
        }
        
        /* 
         * Gets the data for this node as a reference.
         * @return the reference to the data for this node.
         */
        T& getData(){
            return data;
        }
        
        /*
         * Sets the left child for this node.
         * @param *newLeftChild a pointer to the new left child node.
         */
        void setLeftChild(BSTNode *newLeftChild){
            leftChild = newLeftChild;    
        }
        
        /* 
         * Gets a pointer to this node's left child node.
         * @return a BSTNode* that is a pointer to this node's left child node.
         */
        BSTNode* getLeftChild() const{
            return leftChild;
        }
        
        /* 
         * Gets a reference to a pointer to this node's left child node.
         * @return a BSTNode*& that is a reference to a pointer to this node's left child node.
         */
        BSTNode*& getLeftChild(){
            return leftChild;
        }
        
        /*
         * Sets the right child for this node.
         * @param *newRightChild a pointer to the new right child node.
         */
        void setRightChild(BSTNode *newRightChild){
            rightChild = newRightChild;
        }
        
        /* 
         * Gets a pointer to this node's right child node.
         * @return a BSTNode* that is a pointer to this node's right child node.
         */
        BSTNode* getRightChild() const{
            return rightChild;
        }
        
        /* 
         * Gets a reference to a pointer to this node's right child node.
         * @return a BSTNode*& that is a reference to a pointer to this node's right child node.
         */
        BSTNode*& getRightChild(){
            return rightChild;
        }
        
    private:
        BSTNode *leftChild;
        BSTNode *rightChild;
        T data;
};