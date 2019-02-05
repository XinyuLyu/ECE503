#pragma once
#ifndef NODE_XINYU_LYU
#define NODE_XINYU_LYU
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Node {
	friend class DoubleLinkList;
public:
/*	Node::Node(string &company, int number, double price)           //construction
		:Stock_Company(company), Stock_Number(number), Stock_Price(price)
	{
		setTolVal(Stock_Price, Stock_Number);
		this->prev = NULL;
		this->next = NULL;
	}	
	*/
	Node(string& symbol, int quant, double price);
	Node()
	{
		Stock_Company = "";
		Stock_Number = 0.0;
		Stock_Price = 0;
		Stock_TolVal = 0;

		this->next = NULL;
		this->prev = NULL;
	}

	void clear();                                                                //clear all the information of a node
	void setTolVal(double,int);                                                 // set the total value   of a node
	double getTolVal()const;                                                  // get the total value  of a node 
	void setNumber(int);                                                  //set the number  of a node
	int getNumber()const;                                                   // get the number of a node 
	void setCompany(string);                                           //set company of a node
	string getCompany()const;                                            // get company symbol of a node
	void setPrice(double);                                                  // set the price of a node
	double getPrice()const;                                                       // get the price of a node
private:
	string Stock_Company;
	int Stock_Number;
	double Stock_Price,Stock_TolVal;
	Node*prev;
	Node*next;
};
#endif // !NODE_XINYU_LYU
