#pragma once

#include <string>
#include <cstdlib>
#include "BSTNode.h"

template <typename T>
class BSTree{
    public:
        BSTree()
        : root(NULL),
          size(0)
         {}
         
        ~BSTree(){
            clear();
        }
        
        bool insert(T newContents)){
            return insert(data, root);
        }
        
        void clear(){
            clear(root);
        }
        
        bool find(T targetData){
            find(targetData, root);
        }
        
        bool remove(T targetData){
            remove(targetData, root);
        }
        
        T* get(T targetData){
            get(targetData, root);
        }
        
        unsigned int getSize() const{
            return size;
        }
        
        void inOrder(){
            inOrder(root);
        }
        
        void reverseOrder(){
            reverseOrder(root);
        }
        
    private:
        BSTNode<T> *root;
        int size;
        
        bool insert(T newContents, BSTNode *&tempRoot){
            if(tempRoot == NULL){
                tempRoot = new BSTNode<T>(newContents);
                size++;
                return true;
            }
            else if(newContents < tempRoot->getContents()){
                return insert(newContents, tempRoot->getLeftChild());
            }
            else if(newContents > tempRoot->getContents()){
                return insert(newContents, tempRoot->getRightChild());
            }
            else{
                return false;
            }
        }
        
        bool find(T targetData, BSTNode *&tempRoot){
            if(tempRoot != NULL){
                if(targetData < tempRoot->getContents()){
                    return find(targetData, tempRoot->getLeftChild());
                }
                else if(newContents > tempRoot->getContents()){
                    return find(targetData, tempRoot->getRightChild());
                }
                else{
                    return true;
                }
            }
            else{
                return false;
            }
        }
        
        bool remove(T targetData, BSTNode *&tempRoot){
            
        }
        
        void removeMax(T &removed, BSTNode *&tempRoot){
            
        }
        
        T* get(T targetData, BSTNode *&tempRoot){
            if(tempRoot != NULL){
                if(targetData < tempRoot->getContents()){
                    return get(targetData, tempRoot->getLeftChild());
                }
                else if(newContents > tempRoot->getContents()){
                    return get(targetData, tempRoot->getRightChild());
                }
                else{
                    return &tempRoot->getContents();
                }
            }
            else{
                return false;
            }
        }
        
        void clear(BSTNode *&tempRoot){
            if(tempRoot != NULL){
                clear(tempRoot->getLeftChild());
                clear(tempRoot->getRightChild());
                delete tempRoot;
                tempRoot = NULL;
                size--;
            }
        }
        
        void inOrder(BSTNode *&tempRoot){
            if(tempRoot != NULL){
                inOrder(tempRoot->getLeftChild());
                std::cout << tempRoot->getContents() << ' ';
                inOrder(tempRoot->getRightChild());
            }
        }
        
        void reverseOrder(BSTNode *&tempRoot){
            if(tempRoot != NULL){
                inOrder(tempRoot->getRightChild());
                std::cout << tempRoot->getContents() << ' ';
                inOrder(tempRoot->getLeftChild());
            }
        }
};