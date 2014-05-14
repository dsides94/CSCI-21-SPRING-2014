#include <iostream>
#include "bstree.h"

BSTree::BSTree()
: root(NULL),
  size(0)
{}

BSTree::~BSTree(){
    clear();
}

bool BSTree::insert(int contents){
    return insert(contents, root);
}

bool BSTree::remove(int contents){
    return remove(contents, root);
}

void BSTree::clear(){
    clear(root);
}

unsigned int BSTree::getSize() const{
    return size;
}

void BSTree::inOrder(){
    inOrder(root);
}

bool BSTree::insert(int contents, BSTNode *&root){
    if(root == NULL){
        root = new BSTNode(contents);
        size++;
        return true;
    }
    else if(contents < root->getContents()){
        return insert(contents, root->getLeftChild());
    }
    else if(contents > root->getContents()){
        return insert(contents, root->getRightChild());
    }
    else{
        return false;
    }
}

bool BSTree::remove(int contents, BSTNode *&root){
    if(root != NULL){
        if(contents < root->getContents()){
            return remove(contents, root->getLeftChild());
        }
        else if(contents > root->getContents()){
            return remove(contents, root->getRightChild());
        }
        else{
            if(root->getLeftChild() == NULL){
                BSTNode *oldRoot = root;
                root = root->getRightChild();
                delete oldRoot;
            }
            else{
                removeMax(root->getContents(), root->getLeftChild());
            }
            size--;
            return true;
        }
    }
    else{
        return false;
    }
}

void BSTree::removeMax(int& removed, BSTNode *&root){
    if(root->getRightChild() == NULL){
        removed = root->getContents();
        BSTNode *oldRoot = root;
        root = root->getLeftChild();
        delete oldRoot;
    }
    else{
        removeMax(removed, root->getRightChild());
    }
}

void BSTree::clear(BSTNode *&root){
    if(root != NULL){
        clear(root->getLeftChild());
        clear(root->getRightChild());
        delete root;
        root = NULL;
        size--;
    }
}

void BSTree::inOrder(BSTNode *&root){
    if(root != NULL){
        inOrder(root->getLeftChild());
        std::cout << root->getContents() << ' ';
        inOrder(root->getRightChild());
    }
}