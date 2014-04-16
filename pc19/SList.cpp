#include "SList.h"
#include <sstream>

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
    
    return ss.str();
}