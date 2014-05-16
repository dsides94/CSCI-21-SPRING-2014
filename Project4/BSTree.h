#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "BSTNode.h"

template <typename T>
class BSTree{
    public:
        /*
         * Default Constructor.
         * Sets root to NULL and size to 0.
         */
        BSTree()
        : root(NULL),
          size(0)
        {}
        
        /*
         * Default Destructor
         */
        ~BSTree(){
            clear();
        }
        
        /*
         * Inserts new data into this tree.
         * @param newContents the data that is inserted into this tree.
         * @return a bool that is true if the data was not found, and then
         *         inserted, and false if the data was found.
         */
        bool insert(T newContents){
            return insert(newContents, root);
        }
        
        /* 
         * Deletes all the nodes from this tree.
         */
        void clear(){
            clear(root);
        }
        
        /*
         * Searches the tree for a node containing the specified data.
         * @param targetData the data being searched for.
         * @return a bool that is true if the data was found.
         */
        bool find(T targetData){
            return find(targetData, root);
        }
        
        /*
         * Removes the node from this tree containing the specified data.
         * @param targetData the data being removed.
         * @return a bool that is true if the data was found and removed.
         */
        bool remove(T targetData){
            return remove(targetData, root);
        }
        
        /*
         * Looks for a node in the tree containing the specified data,
         * and gets a pointer to its data.
         * @param targetData the data being searched for.
         * @return a pointer to the data if found, NULL if not.
         */
        T* get(T targetData){
            return get(targetData, root);
        }
        
        /*
         * Gets the number of nodes in this tree.
         * @return an unsigned int that is the size of this tree.
         */ 
        unsigned int getSize() const{
            return size;
        }
        
        /*
         * Prints the data of all the nodes in this tree in ascending order.
         */
        void inOrder(){
            inOrder(root);
        }
        
        /*
         * Prints the data of all the nodes in this tree in descending order.
         */
        void reverseOrder(){
            reverseOrder(root);
        }
        
    private:
        BSTNode<T> *root;
        int size;
        
        /*
         * Helper for the public insert function.
         * @param newContents the data that is inserted into this tree.
         * @param tempRoot the root for the current subtree.
         * @return a bool that is true if the data was not found, and then
         *         inserted, and false if the data was found.
         */
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
        
        /*
         * Helper for the public find function.
         * @param targetData the data being searched for.
         * @param tempRoot the root for the current subtree.
         * @return a bool that is true if the data was found.
         */
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
        
        /*
         * Helper for the public remove function.
         * @param targetData the data being removed.
         * @param tempRoot the root for the current subtree.
         * @return a bool that is true if the data was found and removed.
         */
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
        
        /*
         * Helper for the public remove function.
         * @param removed a reference to the data for a node.
         * @param tempRoot the root for the current subtree.
         */
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
        
        /*
         * Helper for the public get function.
         * @param targetData the data being searched for.
         * @param tempRoot the root for the current subtree.
         * @return a pointer to the data if found, NULL if not.
         */
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
        
        /* 
         * Helper for the public clear function.
         * @param tempRoot the root for the current subtree.
         */
        void clear(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                clear(tempRoot->getLeftChild());
                clear(tempRoot->getRightChild());
                delete tempRoot;
                tempRoot = NULL;
                size--;
            }
        }
        
        /* 
         * Helper for the public inOrder function.
         * @param tempRoot the root for the current subtree.
         */
        void inOrder(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                inOrder(tempRoot->getLeftChild());
                std::cout << tempRoot->getData() << ' ' << std::endl;
                inOrder(tempRoot->getRightChild());
            }
        }
        
        /* 
         * Helper for the public reverseOrder function.
         * @param tempRoot the root for the current subtree.
         */
        void reverseOrder(BSTNode<T> *&tempRoot){
            if(tempRoot != NULL){
                reverseOrder(tempRoot->getRightChild());
                std::cout << tempRoot->getData() << ' ' << std::endl;
                reverseOrder(tempRoot->getLeftChild());
            }
        }
};