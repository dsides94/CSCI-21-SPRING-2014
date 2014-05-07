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
    bool added = false;
    
    if(root == NULL){
        root = new BSTNode(contents);
        size++;
        return true;
    }
    else if(contents < root->getContents()){
        added = insert(contents, root->getLeftChild());
    }
    else if(contents > root->getContents()){
        added = insert(contents, root->getRightChild());
    }
    else{
        return false;
    }
    return added;
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