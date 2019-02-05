#pragma once
#ifndef XINYU_LYU_LINKEDLIST_H
#define XINYU_LYU_LINKEDLIST_H
#include"XINYU_LYU_Node.h"
#include<new>
#include<iomanip>
#include<iostream>
using namespace std;
class LinkedList {                                 
public:
	LinkedList();
	~LinkedList();
	int size() const;
	void addToStart(string& name,int no);
	void addToEnd(string& name,int no);
	void printList()const;
	bool removeFromStart();
	bool removeFromEnd();
	bool removeNodeFromList(int no);
	bool removeNodeFromList_name(string& name);           //remove the node by input the name
	bool isEmpty()const;
private:
	Node *myHead;
	Node *myTail;
	int mySize;
	Node *getNewNode( string&name, int  no );     
};             
LinkedList::LinkedList()                                  //construction
	:myHead(0),myTail(0)
{

}    
LinkedList::~LinkedList()                                     //destruction
{
	if (!isEmpty())
	{
		Node *currentPtr = myHead;
		Node *tempPtr;

		while (currentPtr != 0)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
}
int LinkedList::size()const                                    //return size
{
	return 0;
}

bool LinkedList::isEmpty()const                             //judge whether the link is empty
{
	return myHead == 0;
}
Node *LinkedList::getNewNode(string&name, int no)                 //get new node
{
	return new Node(name, no);
}     
void LinkedList::printList()const                                //print the list
{
	if (isEmpty())
	{
		cout << "\n";
		cout << "The List is Empty" << endl;
		cout << "\n";
		return;
	}
	Node *currentPtr = myHead;
	cout << "\n";
	cout << "List" << endl;
	cout << "Item No"<<setw(10)<<"Item Name"<< endl;
	while (currentPtr != 0)
	{
		cout << currentPtr->itemNo << setw(15) << currentPtr->itemName << endl;
		currentPtr = currentPtr->next;
	}
	cout << "\n";
}

  void LinkedList::addToStart(string&name,int no)                          //add to start
{
	  Node *newPtr = getNewNode(name, no);
	  if (isEmpty())
	  {
		  myHead = myTail = newPtr;
	  }
	  else
	  {
		  newPtr->next = myHead;
		  myHead = newPtr;
	  }
} 
  void LinkedList::addToEnd(string&name, int no)                               //add to end
  {
	  Node *newPtr = getNewNode(name, no);
	  if (isEmpty())
	  {
		  myHead = myTail = newPtr;
	  }
	  else
	  {
		  myTail->next = newPtr;
		  myTail = newPtr;
	  }
  }
  bool LinkedList::removeFromStart()                                       //remove from start
  {
	  if (isEmpty())
	  {
		  return false;
	  }
	  else
	  {
		  Node *tempPtr = myHead;
		  if (myHead==myTail)
		  {
			  myHead = myTail = 0;
			  return true;
		  }
		  else
		  {
			  myHead = myHead->next;
			  delete tempPtr;
			  return true;
		  }
	  }
  }
  bool LinkedList::removeFromEnd()                           //remove from end
  {
	  if (isEmpty())
	  {
		  return false;
	  }
	  else
	  {
		  Node *tempPtr = myTail;
		  if (myHead == myTail)
		  {
			  myHead = myTail = 0;
			  return true;
		  }
		  else
		  {
			  Node *currentPtr = myHead;
			  while (currentPtr->next != myTail)
			  {
				  currentPtr = currentPtr->next;
			  }
			  myTail = currentPtr;
			  currentPtr->next = 0;
		  }
		  delete tempPtr;
		  return true;
	  }
  }
  bool LinkedList::removeNodeFromList(int no)                       //remove node from list by number
  {
  if(isEmpty())
	  {
	  cout << "Item Not Found" << endl;
	  return false;
      }
  else
  {
	  Node*tempPtr;
	  {
		  Node* currentPtr = myHead;
		  if (myHead == myTail)
		  {
			  if (currentPtr->itemNo == no)
			  {
				  LinkedList::removeFromStart();
				  return true;
			  }
			  else
			  {
				  cout << "\n";
				  cout << "Item Not Found" << endl;
				  return false;
			  }
		  }
		  else
		  {
			  if (currentPtr->itemNo == no)
			  {
				  LinkedList::removeFromStart();
				  return true;
			  }
			  else {
				  while (currentPtr->next->itemNo != no&&currentPtr->next != myTail)
				  {
					  currentPtr = currentPtr->next;
				  }
				  if (currentPtr->next->itemNo == no&&currentPtr->next != myTail)
				  {
					  tempPtr = currentPtr->next;
					  currentPtr->next = currentPtr->next->next;
					  delete tempPtr;
					  return true;
				  }
				  else
				  {
					  if (currentPtr->next->itemNo == no)
					  {
						  LinkedList::removeFromEnd();
						  return true;
					  }
					  else
					  {
						  cout << "\n";
						  cout << "Item No Found" << endl;
						  return false;
					  }
				  }
			  }
		  }
	  }
    }
  }
 bool LinkedList::removeNodeFromList_name(string& name)                   //remove node from list by name
 {
	 if (isEmpty())
	 {
		 cout << "Item Not Found" << endl;
		 return false;
	 }
	 else
	 {
		 Node*tempPtr;
		 {
			 Node* currentPtr = myHead;
			 if (myHead == myTail)
			 {
				 if (currentPtr->itemName == name)
				 {
					 LinkedList::removeFromStart();
					 return true;
				 }
				 else
				 {
					 cout << "\n";
					 cout << "Item Not Found" << endl;
					 return false;
				 }
			 }
			 else
			 {
				 if (currentPtr->itemName == name)
				 {
					 LinkedList::removeFromStart();
					 return true;
				 }
				 else {
					 while (currentPtr->next->itemName != name&&currentPtr->next != myTail)
					 {
						 currentPtr = currentPtr->next;
					 }
					 if (currentPtr->next->itemName == name&&currentPtr->next != myTail)
					 {
						 tempPtr = currentPtr->next;
						 currentPtr->next = currentPtr->next->next;
						 delete tempPtr;
						 return true;
					 }
					 else
					 {
						 if (currentPtr->next->itemName == name)
						 {
							 LinkedList::removeFromEnd();
							 return true;
						 }
						 else
						 {
							 cout << "\n";
							 cout << "Item No Found" << endl;
							 return false;
						 }
					 }
				 }
			 }
		 }
	 }
 }










#endif // !1