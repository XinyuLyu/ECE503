#pragma once
#ifndef XINYU_LYU_NODE_H
#define XINYU_LYU_NODE_H
#include<string>
using namespace std;
class Node {
	friend class LinkedList;
public:
	Node(string& name, int no)                                     //construction
		:itemName(name), itemNo(no)
	{
		this->next = NULL;
	}
	void Node::set_itemNo(int no);                                 //set number
	int Node::get_itemNo()const;                                     //get number
	void Node::set_itemName(string& name);                           //set name
	string Node::get_itemName()const;                                 //get name
private:
	string itemName;
	int itemNo;
	Node *next;

};
void Node::set_itemNo(int no)
{
	itemNo = no;
}
int Node::get_itemNo()const
{
	return itemNo;
}
void Node::set_itemName(string& name)
{
	itemName = name;
}
string Node::get_itemName()const
{
	return itemName;
}
#endif // 