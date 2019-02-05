#pragma once
#ifndef XINYU_LYU_OVERNIGHTPACKAGE_H
#define XINYU_LYU_OVERNIGHTPACKAGE_H
#include"XINYU_LYU_Package.h"
class OvernightPackage : public Package
{
public:
	OvernightPackage(const char *, const char*,                                   //consturction
		const char*, const char*, int ,
		const char *, const char*,
		const char*, const char*, int , double ,double,double);
	~OvernightPackage();                                                            //desturction
	virtual double calculateCost()const;                                                     //calculate cost
	virtual void print()const;                                                          //print necessayr infromation
	virtual void printPrice()const;                                                  //print unit price information
	virtual void setPrice(double);                                                    //set unit price
	virtual void setFlatFee_Ounce(double);                                                //set flatfee
	virtual double getFlatFee_Ounce()const;                                             //get flat fee
private:
	double FlatFee_Ounce;
};
#endif // 
