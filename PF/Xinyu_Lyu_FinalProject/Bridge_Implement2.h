#pragma once
#pragma once
#include"Bridge.h"
#include"Account_Xinyu_Lyu.h"
class BankAccount_Bridge_Implement2: public Bridge
{
public:
	virtual void implement(Account *a)//implements of the abstract part of bridge
	{
		a->bridge();
	}
};