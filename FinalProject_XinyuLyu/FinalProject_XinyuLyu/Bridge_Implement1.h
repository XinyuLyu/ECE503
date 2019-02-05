#pragma once
#include"Bridge.h"
#include"Account_Xinyu_Lyu.h"
class StockAccount_Bridge_Implement1 : public Bridge
{
public: 
	virtual void implement(Account *a)//implements of the abstract part of bridge
	{
		a->bridge();
	}
};