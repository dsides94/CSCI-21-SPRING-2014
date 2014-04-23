#pragma once

#include <string>
#include <sstream>
#include "DLNode.h"

struct DLListException{
    DLListException (std::string newMessage = "Error")
    : message(newMessage)
    {}

    std::string message;
};

template <typename T>
class DLList{
    public:
        /*
         * Default constructor.
         * Initializes head and tail to NULL.
         */
        DLList()
        : head(NULL),
          tail(NULL),
          size(0)
        {}
        
        /*
         * Default deconstructor that deletes all nodes in this list, by
         * calling the clear function.
         */
        ~DLList(){
            clear();
        }
        
        /*
         * Adds a node to the head of this list.
         * @param contents a type that is the contents of the new node.
         */
        void pushFront(T contents){
            size++;
            DLNode<T> *newHead = new DLNode<T>(contents);
            if(head != NULL){
                head->setPrevious(newHead);
            }
            newHead->setNext(head);
            head = newHead;
            if(tail == NULL){
                tail = head;
            }
        }
        
        /*
         * Adds a a node to the tail of this list.
         * @param contents a type that is the contents of the new node.
         */
        void pushBack(T contents){
            size++;
            DLNode<T> *newTail = new DLNode<T>(contents);
            if(tail != NULL){
                tail->setNext(newTail);
            }
            newTail->setPrevious(tail);
            tail = newTail;
            if(head == NULL){
                head = tail;
            }
        }
        
        /*
         * Removes the head node for this list.
         */
        void popFront(){
            if(head != NULL){
                if(head == tail){
                    delete head;
                    head = NULL;
                    tail = NULL;
                }
                else{
                    size--;
                    DLNode<T> *oldHead = head;
                    head = head->getNext();
                    head->setPrevious(NULL);
                    delete oldHead;
                }
            }
        }
        
        /*
         * Removes the tail node for this list.
         */
        void popBack(){
            if(tail != NULL){
                if(head == tail){
                    delete head;
                    head = NULL;
                    tail = NULL;
                }
                else{
                   size--;
                    DLNode<T> *oldTail = tail;
                    tail = tail->getPrevious();
                    tail->setNext(NULL);
                    delete oldTail; 
                }
            }
        }
        
        /*
         * Gets the contents of the head of this list.
         * @return a type which is the contents.
         */
        T getFront() const{
            if(head != NULL){
                return head->getContents();
            }
            else{
                throw DLListException("LIST EMPTY");
            }
        }
        
        /*
         * Gets the contents of the tail of this list.
         * @return a type which is the contents.
         */
        T getBack() const{
            if(tail != NULL){
                return tail->getContents();
            }
            else{
                throw DLListException("LIST EMPTY");
            }
        }
        
        /*
         * Checks if there is a node in the list with the target contents.
         * @param target a type that is the contents being searched for.
         * @return a bool that is true if the target was found, false if not.
         */
        bool get(T target) const{
            bool targetExists = false;
            
            if(head != NULL){
                DLNode<T> *node = head;
                
                while(node != NULL){
                    if(node->getContents() == target){
                        targetExists = true;
                    }
                    node = node->getNext();
                }
            }
            
            return targetExists;
        }
        
        /*
         * Inserts a node into the list, trying to keep the list in ascending order.
         * @param contents a type that is the contents of the new node.
         */
        void insert(T contents){
            if(head == NULL || head->getContents() >= contents){
                pushFront(contents);
            }
            else{
                DLNode<T> *node = head;
                DLNode<T> *prevNode = NULL;
                
                while(node != NULL){
                    prevNode = node;
                    node = node->getNext();
                    if(node == NULL || node->getContents() >= contents){
                        size++;
                        DLNode<T> *newNode = new DLNode<T>(contents);
                        prevNode->setNext(newNode);
                        newNode->setPrevious(prevNode);
                        newNode->setNext(node);
                        if(node != NULL){
                            node->setPrevious(newNode);
                        } else {
                            tail = newNode;
                        }
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
        bool removeFirst(T target){
            bool targetFound = false;
            
            if(head != NULL){
                if(head->getContents() == target){
                    popFront();
                    targetFound = true;
                }
                else{
                    DLNode<T> *node = head;
                    DLNode<T> *prevNode = NULL;
                    
                    while(node != NULL){
                        if(node->getContents() == target){
                            size--;
                            if(prevNode != NULL){
                                prevNode->setNext(node->getNext());
                            }
                            if(node->getNext() != NULL){
                                node->getNext()->setPrevious(prevNode);
                            }
                            delete node;
                            targetFound = true;
                            break;
                        }
                        prevNode = node;
                        node = node->getNext();
                    }
                }
            }
            
            return targetFound;
        }
        
        /*
         * Removes all nodes in the list that matches the specific contents.
         * @param target a type that is the contents of the node being removed.
         * @return a bool that is true if the contents was found, and false if not.
         */
        bool removeAll(T target){
            bool targetFound = false;
            
            if(head != NULL){
                if(head->getContents() == target){
                    popFront();
                    targetFound = true;
                }
                else{
                    DLNode<T> *node = head;
                    DLNode<T> *prevNode = NULL;
                    DLNode<T> *nextNode = NULL;
                    
                    while(node != NULL){
                        if(node->getContents() == target){
                            size--;
                            if(prevNode != NULL){
                                prevNode->setNext(node->getNext());
                            }
                            if(node->getNext() != NULL){
                                node->getNext()->setPrevious(prevNode);
                            }
                            nextNode = node->getNext();
                            delete node;
                            node = nextNode;
                            targetFound = true;
                        } else{
                            prevNode = node;
                            node = node->getNext();
                        }
                    }
                }
            }
            
            return targetFound;
        }
        
        /*
         * Deletes every node in this list, clearing it.
         */
        void clear(){
            while(head != NULL){
                popFront();
            }
            size = 0;
        }
        
        /*
         * Get the size of this list, which is the number of nodes in it.
         * @return an unsigned int that is the size of this list.
         */
        unsigned int getSize() const{
            return size;
        }
        
        /*
         * Overloads the insertion operator so you can insert a string containing
         * a comma seperated list of the contents of all the nodes in this list
         * into an output stream.
         * @param out an ostream& that is the output stream that the string is
         *        inserted into.
         * @param src a DLList& containing the data used.
         */
        friend std::ostream& operator<<(std::ostream& out, const DLList<T>& src){
            std::stringstream ss;
            DLNode<T> *node = src.head;
            
            while(node != NULL){
                ss << node->getContents();
                node = node->getNext();
                if(node != NULL){
                    ss << ',';
                }
            }
            out << ss.str();
            return out;
        }
        
    private:
        DLNode<T> *head;
        DLNode<T> *tail;
        unsigned int size;
};