#pragma once
#ifndef ACCOUNT_XINYU_LYU_H
#define ACCOUNT_XINYU_LYU_H
#include"global.h"
#include "Node_Xinyu_Lyu.h"
#include "DoubleLinkList_Xinyu_Lyu.h"
#include "RealTime_Price_Xinyu_Lyu.h"
#include"Bridge.h"
#include <yvals.h>
#if (_MSC_VER >= 1600)           //compile version
#define __STD_UTF_16__
#endif
#include "mex.h"
#include <engine.h>
#include<iostream>
#include <string>
#include <cmath>
#pragma comment (lib , "libmx.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")
using namespace std;
class Account:public global
{
	friend class RealTime_Price;           // a class get the realtime price 
public:
	Account();
	virtual ~Account();
	void GetTime(int &, int &, int &, int &, int &, int &);  //get time information for print
	double getCash_Balance();                                // get cash balance
	void setCash_Balance(double);                             // set cash balance
	vector<double>  Total_Portfolio, Index;              // vector for price and company name from the Result.txt 
    void View_Portfolio_Graph();                                // Matlab graph for portfolio 
	void Write_Graph_Data(DoubleLinkList & list);               // write portfolio data to Portfolio_Xinyu_Lyu.txt
	void virtual bridge() {};                              //implement part part in bridge design pattern  
};
#endif