#include "SList.h"
#include <sstream>
#include <iostream>

SList::SList()
: head(NULL),
  size(0)
{
    
}

SList::~SList()
{
    clear();
}

void SList::insertHead(int contents)
{
    size++;
    SLNode *newHead = new SLNode(contents);
    newHead->setNextNode(head);
    head = newHead;
}

void SList::insertTail(int contents)
{
    if(head != NULL){
        size++;
        SLNode *lastNode = head;
        
        while(lastNode->getNextNode() != NULL){
            lastNode = lastNode->getNextNode();
        }
        lastNode->setNextNode(new SLNode(contents));
    }
    else{
        insertHead(contents);
    }
}

void SList::removeHead()
{
    if(head != NULL){
        size--;
        SLNode *oldHead = head;
        head = head->getNextNode();
        delete oldHead;
    }
}

void SList::removeTail()
{
    if(head != NULL){
        size--;
        SLNode *lastNode = head;
        SLNode *prevNode = NULL;
        
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

void SList::insert(int contents)
{
    if(head == NULL || head->getContents() >= contents){
        insertHead(contents);
    }
    else{
        SLNode *node = head;
        SLNode *prevNode = NULL;
        
        while(node != NULL){
            prevNode = node;
            node = node->getNextNode();
            if(node == NULL || node->getContents() >= contents){
                size++;
                SLNode *newNode = new SLNode(contents);
                prevNode->setNextNode(newNode);
                newNode->setNextNode(node);
                break;
            }
        }
    }
}

bool SList::removeFirst(int contents)
{
    bool contentsRemoved = false;
    
    if(head != NULL){
        if(head->getContents() == contents){
            removeHead();
            contentsRemoved = true;
        }
        else{
            SLNode *node = head;
            SLNode *prevNode = NULL;
            
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

void SList::clear()
{
    while(head != NULL){
        removeHead();
    }
}

unsigned int SList::getSize() const
{
    return size;
}

std::string SList::toString() const
{
    std::stringstream ss;
    SLNode *node = head;
    
    while(node != NULL){
        ss << node->getContents();
        node = node->getNextNode();
        if(node != NULL){
            ss << ',';
        }
    }
    std::string str = ss.str();
    //std::cout << ss.str()
    
    return ss.str();
}