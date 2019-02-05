#pragma once
#ifndef BANKACCOUNT_XINYU_LYU_H
#define BANKACCOUNT_XINYU_LYU_H
#include"Account_Xinyu_Lyu.h"
#include"Node_Xinyu_Lyu.h"
#include"DoubleLinkList_Xinyu_Lyu.h"
#include"print_Title.h"
class BankAccount :public Account,public print
{
public:
	BankAccount();
	~BankAccount();
	void View_Account_Balance();   	// get cash balance
    void Withdraw(DoubleLinkList &);
	void Deposit(DoubleLinkList &);                      
	void Print_Bank_History();                         // print bank transcation history
    void Read_CashBalance();                            //read the event number date cash banlance information from Bank_Transaction_History_Xinyu_Lyu.txt 
	void Write_Bank_History(string,double,double);     // write bank transcation history to the Bank_Transaction_History_Xinyu_Lyu.txt
	virtual void  print_Title();                       // This is an adapter design pattern for different clients they have different requests for to print the history,
	                                                   // this function is used to adapt the different print requests. Very simple but necessary
	void virtual bridge();                            // implements of bridge 
};
#endif

















