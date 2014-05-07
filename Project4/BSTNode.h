#pragma once

#include <string>
#include <cstdlib>

template <typename T>
class BSTNode{
    public:
        BSTNode(){
        : leftChild(NULL),
          rightChild(NULL),
          data(0)
        {}
        
        BSTNode(int newData)
        : leftChild(NULL),
          rightChild(NULL),
          data(newData)
        {}
        
        virtual ~BSTNode(){}
        
        void setData(T newData){
            data = newData;
        }
        
        T getData() const{
            return data;
        }
        T& getData(){
            return data;
        }
        
        void setLeftChild(BSTNode *newLeftChild){
            leftChild = newLeftChild;    
        }
        
        BSTNode* getLeftChild() const{
            return leftChild;
        }
        
        BSTNode*& getLeftChild(){
            return leftChild;
        }
        
        void setRightChild(BSTNode *newRightChild){
            rightChild = newRightChild;
        }
        
        BSTNode* getRightChild() const{
            return rightChild;
        }
        
        BSTNode*& getRightChild(){
            return rightChild;
        }
        
    private:
        BSTNode *leftChild;
        BSTNode *rightChild;
        T data;
};