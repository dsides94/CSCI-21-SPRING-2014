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
    size = 0;
    while(head != NULL){
        SLNode *nextHead = head->getNextNode();
        delete head;
        head = nextHead;
    }
}

unsigned int SList::getSize() const
{
    return size;
}

std::string SList::toString() const
{
    if(size > 0){
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
    else{
        return "";
    }
}

/*
Declare and implement a class that provides the following interface EXACTLY.

class name: SList

private data members:

	head, SLNode* that points to the first node in a singly-linked list
	size, unsigned int the count of the number of nodes in the list

public function interface:

	default constructor, sets values head(NULL) and size(0)
	
	destructor, calls the clear function
	
	void insertHead (int), create a new SLNode and attach as head of list
	
	void removeHead (), remove the head node from the list
	
	void clear (), clear the entire contents of the list, freeing all memory
	               associated with all nodes
	
	unsigned int getSize () const
	
	string toString () const, return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1,NUM2,...,LASTNUM; return empty string on 
	                          empty list
*/