#include "SLNode.h"

SLNode::SLNode()
: nextNode(NULL),
  contents(0)
{
    
}

SLNode::SLNode(int newContents)
: nextNode(NULL),
  contents(newContents)
{
    
}

SLNode::~SLNode()
{
    nextNode = NULL;
}

void SLNode::setContents(int newContents)
{
    contents = newContents;
}

int SLNode::getContents() const
{
    return contents;
}

void SLNode::setNextNode(SLNode* newNextNode)
{
    nextNode = newNextNode;
}

SLNode* SLNode::getNextNode() const
{
    return nextNode;
}

/*Declare and implement a class that provides the following interface EXACTLY.

class name: SLNode

private data members:

	nextNode, SLNode* that points to the next node in a singly-linked list
	contents, int used to store the data contents of this SLNode

public function interface:

	default constructor, sets values nextNode(NULL) and contents(0)
	overloaded constructor, int parameter assigned to contents
	
	destructor, sets nextNode to NULL
	
	void setContents (int)
	int getContents () const
	
	void setNextNode (SLNode*)
	
	SLNode* getNextNode () const
*/