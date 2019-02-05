#include"Node_Xinyu_Lyu.h"
#include<string>
void Node::setCompany(string company)
{
	Stock_Company = company;
}
string Node::getCompany() const
{
	return Stock_Company;
}
void Node::setPrice(double price)
{
	Stock_Price = price;
}
double Node::getPrice() const
{
	return Stock_Price;
}
void Node::setNumber(int number)
{
	Stock_Number = number;
}
int Node::getNumber()const
{
	return Stock_Number;
}
void Node::setTolVal(double price,int number)
{
	Stock_TolVal = (price*number);
}
double Node::getTolVal()const
{
	return Stock_TolVal;
}
void Node::clear()
{
	Stock_Company = "";
	Stock_Price,Stock_TolVal = 0.0;
	Stock_Number = 0;
}
Node::Node(string &company, int number, double price)           //construction
	:Stock_Company(company), Stock_Number(number), Stock_Price(price)
{
	setTolVal(Stock_Price, Stock_Number);
	this->prev = NULL;
	this->next = NULL;
}