#pragma once
#ifndef DOUBLELINKLIST_XINYU_LYU
#define DOUBLELINKLIST_XINYU_LYU
#include<string>
#include<fstream>
#include"RealTime_Price_Xinyu_Lyu.h"
#include"Node_Xinyu_Lyu.h"
class DoubleLinkList : public RealTime_Price {
public:
	DoubleLinkList(RealTime_Price & price);
	~DoubleLinkList();
	bool isEmpty() const;                        // tell if the double linked list is empty 
	void insertNode(Node*);                      // insert node to the  double linked list
	void deleteNode(string);                       //delete node from  double linked list
	void sortList();                            // sort the list
	bool isExist(string);                        // tell if a company 
	void changePrice();                         // randomly choose the price from the result one or result two
	int changeNumber(string,int&);              // change the number for a node 
	int getNumber(string);                       // get the number information of the node
	double getTolPortfolio();                      // get total portfolio
	void print();                                 // print the list
	void Write_currentPortfolio();                  // write the portfolio information to the Portfolio_Xinyu_Lyu
private:
	Node *firstPtr;
	Node *lastPtr;
	RealTime_Price p;
}; 
#endif