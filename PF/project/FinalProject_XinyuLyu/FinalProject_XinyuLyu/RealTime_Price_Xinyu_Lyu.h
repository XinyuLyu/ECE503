#pragma once
#ifndef REALTIME_PRICE_XINYU_LYU_H
#define REALTIME_PRICE_XINYU_LYU_H
#include <iostream>
#include <string>
#include <time.h> 
#include <stdio.h>   
#include <vector>
 #include <fstream> 
#include <stdlib.h>       
using namespace std;
class RealTime_Price {
public:
	RealTime_Price();
	~RealTime_Price();
	vector<string> Stock_Company;               
	vector<double> Result_One_Price,Result_Two_Price;
	double getStock_Price(string company);                              // get random price with the help of the function of getRealTime_Price
	double getRealTime_Price(int index);
	void set_Result_Vectors(vector<string> company, vector<double> Price1, vector<double> Price2); //set the vector with the information of company, and price form the result one and the result two 
};
#endif