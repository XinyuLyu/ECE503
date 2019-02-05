#include "RealTime_Price_Xinyu_Lyu.h"
RealTime_Price::RealTime_Price()
{
	vector<string> Stock_company = {};                     // the vector to save company name
	vector<double> Result_One_Price , Result_Two_Price = {};// the vetor to save the price from result one and result two
}
RealTime_Price::~RealTime_Price(){}
void RealTime_Price::set_Result_Vectors(vector<string> company, vector<double> Price1, vector<double> Price2)
{
	Stock_Company.swap(company);                                //load the comapny name
	Result_One_Price.swap(Price1);                             // load theprice from result one
	Result_Two_Price.swap(Price2);                           //load the price from the result two
}
double RealTime_Price::getStock_Price(string company)
{
	int i=0;
	while (i < Stock_Company.size()) {                              
		if (Stock_Company[i] == company)                              
		{
			return getRealTime_Price(i);                              //if found
		}
		i++;
	}
	return -1;                                                   //not found
}
double RealTime_Price::getRealTime_Price(int index)            
{
	int x = 0;
	srand(time(NULL));
	x = rand() % 2;                                         // rand 1 or 0
	if (x == 0) {                                                           
		return Result_Two_Price[index];                        
	}
	else
	{
		return Result_One_Price[index];
	}
}
