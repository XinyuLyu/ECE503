#pragma once
#ifndef STOCKACCOUNT_XINYU_LYU_H
#define STOCKACCOUNT_XINYU_LYU_H
#include"Node_Xinyu_Lyu.h"
#include"DoubleLinkList_Xinyu_Lyu.h"
#include"Account_Xinyu_Lyu.h"
#include<iomanip>
#include<ctime>
class StockAccount:public Account
{
	friend class RealTime_Price;
public:
	StockAccount();
	~StockAccount();
	void Display_Stock_Price(RealTime_Price&);                       // display the price for a specific stock
	void Display_currentPortfolio(DoubleLinkList &);                    // display the portfolio
	void Buy(DoubleLinkList&,RealTime_Price& );                        
	void Sell(DoubleLinkList&,RealTime_Price&);
	void Print_Stock_History();                                      // print stock transcation history
	void Write_History(string,string,int,double,double);             // wirte the stock transcation history to Stock_Transaction_History_Xinyu_Lyu.txt
	void virtual bridge();                                           // implements of bridge 
};
#endif // !STOCKACCOUNT_XINYU_LYU
