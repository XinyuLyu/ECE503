#include"XINYU_LYU_OvernightPackage.h"
#include<iostream>
#include<iomanip>
using namespace std;
OvernightPackage::OvernightPackage(const char *Name, const char*Address,                           //construction
	const char*City, const char*State, int Zip,
	const char *name, const char*address,
	const char*city, const char*state, int zip, double Weight,double P,double Fee)
	:Package(  Name,  Address,
		City,  State, Zip,
		name, address,
		city, state,  zip,  Weight,P)
{
	setFlatFee_Ounce(Fee);
}
OvernightPackage::~OvernightPackage()                    //destruction
{
	Package::~Package();
}
void OvernightPackage::setFlatFee_Ounce(double f)          //set flat fee
{
	FlatFee_Ounce = f;
}
double OvernightPackage::getFlatFee_Ounce()const            //get flat fee
{
	return FlatFee_Ounce;
}
double OvernightPackage::calculateCost()const                // calculate cost
{
	return getWeight_Ounce()*getPrice_Ounce() + getFlatFee_Ounce()*getWeight_Ounce();
}
void OvernightPackage::print()const                            //print the necessary information
{
	cout << endl;
	cout << "Sender: " << endl;
	cout << this->getSender_Name() << endl;
	cout << this->getSender_Address() << endl;
	cout << this->getSender_City() << ", ";
	cout << this->getSender_State() << " ";
	cout << setw(5) << setfill('0') << this->getSender_Zip() << endl;

	cout << endl;
	cout << "Receipent: " << endl;
	cout << this->getReceipent_Name() << endl;
	cout << this->getReceipent_Address() << endl;
	cout << this->getReceipent_City() << ", ";
	cout << this->getReceipent_State() << " ";
	cout << setw(5) << setfill('0') << this->getReceipent_Zip() << endl;

	cout << endl;
	cout << "Weight of package: " << getWeight_Ounce() << " ounces" << endl;
	cout << "Type of delivery: Overnight Delivery" << endl;
	cout << "Cost of Package: " << "$" << calculateCost() << endl;
	cout << endl;
}
void OvernightPackage::setPrice(double f)                          //set unit price 
{
	setFlatFee_Ounce(f);
}
void OvernightPackage::printPrice() const                        //print unit price
{
	cout << "Additional cost for overnight delivery: " <<"$"<<this->getFlatFee_Ounce()<<"/ounce"<< endl;
}