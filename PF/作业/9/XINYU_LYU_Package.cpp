#pragma warning(disable : 4996) 
#include<iostream>
#include"XINYU_LYU_Package.h"
#include<cstring>
#include<new>
#include<iomanip>
using namespace std; 
Package::Package(const char *Name, const char*Address,                                          //consturction
	const char*City, const char*State, int Zip,
	const char *name, const char*address, 
	const char*city, const char*state, int zip,double Weight,double P)
{
	Sender_Name= new char[strlen(Name) + 1];
	strcpy(Sender_Name, Name);
	Sender_Address = new char[strlen(Address) + 1];
	strcpy(Sender_Address, Address);
	Sender_City = new char[strlen(City) + 1];
	strcpy(Sender_City, City);
	Sender_State = new char[strlen(State) + 1];
	strcpy(Sender_State, State);
	setSender_Zip(Zip);

	Receipent_Name = new char[strlen(name) + 1];
	strcpy(Receipent_Name, name);
	Receipent_Address = new char[strlen(address) + 1];
	strcpy(Receipent_Address, address);
	Receipent_City = new char[strlen(City) + 1];
	strcpy(Receipent_City, city);
	Receipent_State = new char[strlen(State) + 1];
	strcpy(Receipent_State, state);
	setReceipent_Zip(zip);

	setWeight_Ounce(Weight);
	setPrice_Ounce(P);
}
Package::~Package()                                                                        //destruction
{
	delete[]Sender_Name;
	delete[]Sender_Address;
	delete[]Sender_City;
	delete[]Sender_State;
	delete[]Receipent_Name;
	delete[]Receipent_Address;
	delete[]Receipent_City;
	delete[]Receipent_State;
}
void Package::setWeight_Ounce(double w)           //set weight
{
	  Weight_Ounce=w;
}
void Package::setPrice_Ounce(double p)             //set unit price 
{
	Price_Ounce=p;
}
double Package::getPrice_Ounce()const              //get unit price 
{
	return Price_Ounce;
}
double Package::getWeight_Ounce()const              //get weight
{
	return Weight_Ounce;
}
double Package::calculateCost()const             //calculate price
{
	return getWeight_Ounce()*getPrice_Ounce();
}
void Package::setSender_Zip(int Zip)            //set cip code sender
{
	Sender_Zip = Zip;
}
int Package::getSender_Zip()const               //get cip code sender
{
	return Sender_Zip;
}
void Package::setReceipent_Zip(int Zip)          //set zip code receiver
{
	Receipent_Zip = Zip;
}
int Package::getReceipent_Zip()const               //get zip code receiver
{
	return Receipent_Zip;
}
const char *Package::getSender_Name()const           //get sender name
{
	return Sender_Name;
}
const char *Package::getReceipent_Name()const             //get receiver name
{
	return Receipent_Name;
}
const char *Package::getSender_Address()const               //get sende address
{
	return Sender_Address;
}
const char *Package::getReceipent_Address()const            //get receiver address
{
	return Receipent_Address;
}
const char *Package::getSender_City()const                     // get sender city
{
	return Sender_City;
}
const char *Package::getReceipent_City()const                 //get receiver coty
{
	return Receipent_City;
}  
const char *Package::getSender_State()const                        //get sender state
{ 
	return Sender_State;
}
const char *Package::getReceipent_State()const                   //get receiver state
{
	return Receipent_State;
}
void Package::print()const                                    //print the necessary information
{
	cout << endl;
	cout << "Sender: "<<endl;
	cout << this->getSender_Name() << endl;
	cout << this->getSender_Address() << endl;
	cout << this->getSender_City()<<", ";
	cout << this->getSender_State()<<" " ;
	cout <<setw(5)<<setfill('0')<<this->getSender_Zip() << endl;

	cout << endl;
	cout << "Receipent: " << endl;
	cout << this->getReceipent_Name() << endl;
	cout<<this->getReceipent_Address() << endl;
	cout << this->getReceipent_City() << ", ";
	cout << this->getReceipent_State()<<" ";
	cout <<setw(5)<<setfill('0')<<this->getReceipent_Zip() << endl;

	cout << endl;
	cout << "Weight of package: " << getWeight_Ounce() << " ounces" << endl;
	cout << "Type of delivery: Regular Delivery" << endl;
	cout << "Cost of Package: "<<"$"<<calculateCost() << endl;

	cout << endl;
}
void Package::setPrice(double p)                              //set unit price  
{
	setPrice_Ounce(p);
}
void Package::printPrice() const                                  //print unit price
{
	cout << "Cost per ounce for a package: " <<"$"<<this->getPrice_Ounce() << "/ounce"<<endl;
}