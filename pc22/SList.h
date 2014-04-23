#pragma once

#include <string>
#include <sstream>
#include "SLNode.h"

template <typename T>
class SList{
    public:
        /*
         * Default constructor.
         * Initializes head to NULL.
         */
        SList()
        : head(NULL),
          size(0)
        {}
        
        /*
         * Default deconstructor that deletes all nodes in this list, by
         * calling the clear function.
         */
        ~SList(){
            clear();
        }
        
        /*
         * Adds a node to the head of this list.
         * @param contents a type that is the contents of the new node.
         */
        void insertHead(T contents){
            size++;
            SLNode<T> *newHead = new SLNode<T>(contents);
            newHead->setNextNode(head);
            head = newHead;
        }
        
        /*
         * Adds a a node to the tail of this list.
         * @param contents a type that is the contents of the new node.
         */
        void insertTail(T contents){
            if(head != NULL){
                size++;
                SLNode<T> *lastNode = head;
                
                while(lastNode->getNextNode() != NULL){
                    lastNode = lastNode->getNextNode();
                }
                lastNode->setNextNode(new SLNode<T>(contents));
            }
            else{
                insertHead(contents);
            }
        }
        
        /*
         * Removes the head node for this list.
         */
        void removeHead(){
            if(head != NULL){
                size--;
                SLNode<T> *oldHead = head;
                head = head->getNextNode();
                delete oldHead;
            }
        }
        
        /*
         * Removes the tail node for this list.
         */
        void removeTail(){
            if(head != NULL){
                size--;
                SLNode<T> *lastNode = head;
                SLNode<T> *prevNode = NULL;
                
                while(lastNode->getNextNode() != NULL){
                    prevNode = lastNode;
                    lastNode = lastNode->getNextNode();
                }
                delete lastNode;
                if(prevNode != NULL){
                    prevNode->setNextNode(NULL);
                }
                else{
                    head = NULL;
                }
            }
        }
        
        /*
         * Inserts a node into the list, trying to keep the list in ascending order.
         * @param contents a type that is the contents of the new node.
         */
        void insert(T contents){
            if(head == NULL || head->getContents() >= contents){
                insertHead(contents);
            }
            else{
                SLNode<T> *node = head;
                SLNode<T> *prevNode = NULL;
                
                while(node != NULL){
                    prevNode = node;
                    node = node->getNextNode();
                    if(node == NULL || node->getContents() >= contents){
                        size++;
                        SLNode<T> *newNode = new SLNode<T>(contents);
                        prevNode->setNextNode(newNode);
                        newNode->setNextNode(node);
                        break;
                    }
                }
            }
        }
        
        /*
         * Removes the first node in the list that matches the specific contents.
         * @param target a type that is the contents of the node being removed.
         * @return a bool that is true if the contents was found, and false if not.
         */
        bool removeFirst(T contents){
            bool contentsRemoved = false;
    
            if(head != NULL){
                if(head->getContents() == contents){
                    removeHead();
                    contentsRemoved = true;
                }
                else{
                    SLNode<T> *node = head;
                    SLNode<T> *prevNode = NULL;
                    
                    while(node != NULL){
                        if(node->getContents() == contents){
                            size--;
                            if(prevNode != NULL){
                                prevNode->setNextNode(node->getNextNode());
                            }
                            delete node;
                            contentsRemoved = true;
                            break;
                        }
                        prevNode = node;
                        node = node->getNextNode();
                    }
                }
            }
            
            return contentsRemoved;
        }
        
        /*
         * Removes all nodes in the list that matches the specific contents.
         * @param target a type that is the contents of the node being removed.
         * @return a bool that is true if the contents was found, and false if not.
         */
        bool removeAll(T contents){
            bool contentsRemoved = false;
    
            if(head != NULL){
                if(head->getContents() == contents){
                    removeHead();
                    contentsRemoved = true;
                }
                else{
                    SLNode<T> *node = head;
                    SLNode<T> *prevNode = NULL;
                    SLNode<T> *nextNode = NULL;
                    
                    while(node != NULL){
                        if(node->getContents() == contents){
                            size--;
                            if(prevNode != NULL){
                                prevNode->setNextNode(node->getNextNode());
                            }
                            nextNode = node->getNextNode();
                            delete node;
                            node = nextNode;
                            contentsRemoved = true;
                        }
                        else{
                            prevNode = node;
                            node = node->getNextNode();
                        }
                        
                    }
                }
            }
            
            return contentsRemoved;
        }
        
        /*
         * Deletes every node in this list, clearing it.
         */
        void clear(){
            while(head != NULL){
                removeHead();
            }
        }
        
        /*
         * Get the size of this list, which is the number of nodes in it.
         * @return an unsigned int that is the size of this list.
         */
        unsigned int getSize() const{
            return size;
        }
        
        /*
         * Builds a string representation of the contents of every node in
         * this list.
         * @return a string that is the string representation of this list.
         */
        std::string toString() const
        {
            std::stringstream ss;
            SLNode<T> *node = head;
            
            while(node != NULL){
                ss << node->getContents();
                node = node->getNextNode();
                if(node != NULL){
                    ss << ',';
                }
            }
            std::string str = ss.str();
            
            return ss.str();
        }
        
    private:
        SLNode<T> *head;
        unsigned int size;
};