#pragma once

#include <string>
#include <iostream>
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
        
        bool insert(T newContents){
            return insert(newContents, root);
        }
        
        void clear(){
            clear(root);
        }
        
        bool find(T targetData){
            return find(targetData, root);
        }
        
        bool remove(T targetData){
            return remove(targetData, root);
        }
        
        T* get(T targetData){
            return get(targetData, root);
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
        
        bool insert(T newContents, BSTNode<T> *&tempRoot){
            if(tempRoot == NULL){
                tempRoot = new BSTNode<T>(newContents);
                size++;
                return true;
            }
            else if(newContents < tempRoot->getData()){
                return insert(newContents, tempRoot->getLeftChild());
            }
            else if(newContents > tempRoot->getData()){
                return insert(newContents, tempRoot->getRightChild());
            }
            else{
                return false;
            }
        }
        
        bool find(T targetData, BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                if(targetData < tempRoot->getData()){
                    return find(targetData, tempRoot->getLeftChild());
                }
                else if(targetData > tempRoot->getData()){
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
        
        bool remove(T targetData, BSTNode<T> *&tempRoot){
            if(tempRoot == NULL){
                return false;
            }
            else if(targetData < tempRoot->getData()){
                return remove(targetData, tempRoot->getLeftChild());
            }
            else if(targetData > tempRoot->getData()){
                return remove(targetData, tempRoot->getRightChild());
            }
            else{
                if(tempRoot->getLeftChild() == NULL){
                    BSTNode<T> *oldRoot = tempRoot;
                    tempRoot = tempRoot->getRightChild();
                    delete oldRoot;
                }
                else{
                    removeMax(tempRoot->getData(), tempRoot->getLeftChild());
                }
                size--;
                return true;
            }
        }
        
        void removeMax(T &removed, BSTNode<T> *&tempRoot){
            if(tempRoot->getRightChild() == NULL){
                removed = tempRoot->getData();
                BSTNode<T> *oldRoot = tempRoot;
                tempRoot = tempRoot->getLeftChild();
                delete oldRoot;
            }
            else{
                removeMax(removed, tempRoot->getRightChild());
            }
        }
        
        T* get(T targetData, BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                if(targetData < tempRoot->getData()){
                    return get(targetData, tempRoot->getLeftChild());
                }
                else if(targetData > tempRoot->getData()){
                    return get(targetData, tempRoot->getRightChild());
                }
                else{
                    return &tempRoot->getData();
                }
            }
            else{
                return false;
            }
        }
        
        void clear(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                clear(tempRoot->getLeftChild());
                clear(tempRoot->getRightChild());
                delete tempRoot;
                tempRoot = NULL;
                size--;
            }
        }
        
        void inOrder(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                inOrder(tempRoot->getLeftChild());
                std::cout << tempRoot->getData() << ' ' << std::endl;
                inOrder(tempRoot->getRightChild());
            }
        }
        
        void reverseOrder(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                reverseOrder(tempRoot->getRightChild());
                std::cout << tempRoot->getData() << ' ' << std::endl;
                reverseOrder(tempRoot->getLeftChild());
            }
        }
};