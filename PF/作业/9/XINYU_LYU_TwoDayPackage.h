#pragma once
#ifndef XINYU_LYU_TWODAYPACKAGE_H
#define XINYU_LYU_WODATPACKAGE_H
#include"XINYU_LYU_Package.h"
class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const char *, const char*,                              //construction
		const char*, const char*, int,
		const char *, const char*,
		const char*, const char*, int, double, double, double);
	~TwoDayPackage();                                                      //desturction
	virtual double calculateCost()const;                                 //calculate price
	virtual void print()const;                                             //print necessary information
	virtual void printPrice()const;                                        //print unit price
	virtual void setPrice(double);                                        //set price
 	virtual void setFlatFee_Ounce(double);                                //set flat fee
	virtual double getFlatFee_Ounce()const;                              // get flat fee
private:
	double FlatFee_Ounce;
};
#endif // 
