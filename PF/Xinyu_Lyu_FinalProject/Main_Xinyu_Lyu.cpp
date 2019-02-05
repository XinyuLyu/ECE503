#include"Account_Xinyu_Lyu.h"
#include"BankAccount_Xinyu_Lyu.h"
#include"DoubleLinkList_Xinyu_Lyu.h"
#include"Node_Xinyu_Lyu.h"
#include"RealTime_Price_Xinyu_Lyu.h"
#include"StockAccount_Xinyu_Lyu.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<time.h>
#include<fstream>
using namespace std;
    double Account::Cash_Balance = 10000.0;
	vector<string> Stock_company;                                   // the company symbol
	vector<double> Result_One_Price, Result_Two_Price;         // The price information for each company from Result one and Result two 
	void Welcome_Menu();                                     
	void Stock_Menu();
	void Bank_Menu();
    void load_Portfolio(DoubleLinkList & list);
	void load_Result(vector<string>& Stock_company, vector<double>& Result_One_Price, vector<double>& Result_Two_Price);
    Node *node;
	BankAccount Bank;
	RealTime_Price R;
	StockAccount Stock;	
	Bridge g;
int main()
{
	Bank.Read_CashBalance();
	load_Result(Stock_company, Result_One_Price, Result_Two_Price);
	R.set_Result_Vectors(Stock_company, Result_One_Price, Result_Two_Price);
	DoubleLinkList list(R);
	load_Portfolio(list);
	int welcome;
	int stock;
	int bank;
	do{
	Welcome_Menu();
	cin >> welcome;
	switch (welcome)
	{
	case 1:
		cout << "Stock Portfolio Account" << endl;                 //Stock Portfolio Account
		do {
			Stock_Menu();
			cin >> stock;
			switch (stock)
			{
			case 1:
				Stock.Display_Stock_Price(R);
				break;
			case 2:
				Stock.Display_currentPortfolio(list);
				break;
			case 3:
				Stock.Buy(list, R);
				break;
			case 4:
				Stock.Sell(list, R);
				break;
			case 5:
				Stock.View_Portfolio_Graph();
				break;
			case 6:
				Stock.Print_Stock_History();
				break;
			case 7:
				break;
			default:
				cout << "Invalid input." << endl;
				break;
			}
		} while (stock != 7);
		break;

	case 2:
		cout << "Bank Account" << endl;                          //Bank Account
		do {
			Bank_Menu();
			cin >> bank;
			switch (bank)
			{
			case 1:
				Bank.View_Account_Balance();
				break;
			case 2:
				Bank.Deposit(list);
				break;
			case 3:
				Bank.Withdraw(list);
				break;
			case 4:
				int choice;
				cout << "1. Print without title." << endl;
				cout << "2. Print with title." << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					Bank.Print_Bank_History();
					break;
				case 2:
					Bank.print_Title();
					break;
				default:
					break;
				}
				break;
			case 5:
				break;
			default:
				cout << "Invalid input" << endl;
				break;
			}
		} while (bank != 5);
		break;
	case 3:
		break;
	default:
		cout << "Invalid input" << endl;
		break;
	    }
	} while (welcome != 3);
	system("pause");
		return 0;
}
void Welcome_Menu()
{
	cout << "Please select an account to access:" << endl;
	cout << "1. Stock Portfolio Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit" << endl ;
	cout << endl;
	cout<< "Option: ";
}
void Stock_Menu()
{
	cout << "Please select an option:" << endl;
	cout << "1. Display the price for a stock symbol" << endl;
	cout << "2. Display the current portfolio" << endl;
	cout << "3. Buy Shares" << endl;
	cout << "4. Sell Shares" << endl;
	cout << "5. View a graph for the portfolio value" << endl;
	cout << "6. View transaction history" << endl;
	cout << "7. Return to previous menu" << endl;
	cout << endl;
	cout << "Option: ";
}
void Bank_Menu()
{
	cout << "1. View account balance" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print out history" << endl;
	cout << "5. Return to previous menu" << endl;
	cout << endl;
	cout << "Option: ";
}
void load_Result(vector<string>& Stock_company, vector<double>& Result_One_Price, vector<double>& Result_Two_Price) {
    string company,date;
	double price;
	ifstream Result_One;
	Result_One.open("Result_One.txt");                        
	ifstream Result_Two;
	Result_Two.open("Result_Two.txt");
	if (Result_One.fail()) {
		cout << "Error when Opening Result_One" << endl;//error
		exit(1);
	}
	if (Result_Two.fail()) {
		cout << "Error when Opening Result_Two" << endl;//error
		exit(1);
	}
	while (Result_One >> company >> price >> date) {                    //read the company price date information into the vector from result-one
		Stock_company.push_back(company);
		Result_One_Price.push_back(price);
	}
	Stock_company.clear();
	while (Result_Two >> company >> price >> date) {                     //read the company price date information into the vector from result-two
		Stock_company.push_back(company);
		Result_Two_Price.push_back(price);
	}
	Result_One.close();
	Result_Two.close();
}
void load_Portfolio(DoubleLinkList & list)
{
    string company = "";
	int number = 0;
	double price, total;
	ifstream Portfolio;
	Portfolio.open("Portfolio_Xinyu_Lyu.txt");
	while (Portfolio >> company >> number >> price >> total)           //read portfolio infromation to the linked list with node 
	{
		Node node(company, number, price);
		list.insertNode(&node);
	}
	Portfolio.close();
}

