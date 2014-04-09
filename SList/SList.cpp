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

void SList::removeHead()
{
    if(head != NULL){
        size--;
        SLNode *oldHead = head;
        head = head->getNextNode();
        delete oldHead;
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