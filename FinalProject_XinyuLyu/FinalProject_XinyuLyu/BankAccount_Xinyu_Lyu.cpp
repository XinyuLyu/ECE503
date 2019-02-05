#include"BankAccount_Xinyu_Lyu.h"
#include<iomanip>
BankAccount::BankAccount(){}
BankAccount::~BankAccount(){}
void BankAccount::View_Account_Balance()
{
	cout << "You have $" << getCash_Balance() << " in your bank account" << endl;         //print the cash balance
}
void BankAccount::Deposit(DoubleLinkList & list)                          
{
	double money;
	cout << "Please select the amount you wish to deposit: $";                            
	cin >> money;                                                                  
	setCash_Balance(getCash_Balance()+money);                                        // deposit
	cout << "Deposit $" << money << " in your bank account" << endl;
	Write_Bank_History("Deposit", money, getCash_Balance());                              //write to the history
	Write_Graph_Data(list);                                                         // write to the matlab data
}
void BankAccount::Withdraw(DoubleLinkList & list)                            
{
	double money;
	cout << "You have $" << getCash_Balance()<<" in your bank account" << endl;
	cout << "Please select the amount you wish to withdraw: $";
	cin >> money;
	if (money > getCash_Balance())                                                    //not enough money
	{
		cout << "You don't have such amount of money in your bank account" << endl;
	}
	else
	{
		setCash_Balance(getCash_Balance()-money);                                        // withdraw
		cout << "Withdraw $" << money << " from your bank account" << endl;              
		Write_Bank_History("Withdraw", money, getCash_Balance());                         // wirte to the history
		Write_Graph_Data(list);                                                          // write to the matlab data
	}
}
void BankAccount::Print_Bank_History()
{
	cout << left << setw(15) << "Event" << setw(20) << "Amount($)" << setw(20) << "Date" << setw(20) << "Balance($)" << endl;
	fstream read;
	read.open("Bank_Transaction_History_Xinyu_Lyu.txt");                                   // open and read
	string event,date;
	double amount, balance;
	while (read >> event >> amount >> date >> balance)
	{
		cout << left << setw(15) << event << setw(20) << fixed << setprecision(2) << amount << setw(20) << date << setw(20) << fixed << setprecision(2) << balance << endl;
	}
	cout << endl;
	read.close();
}
void BankAccount::Write_Bank_History(string event, double amount,double balance) 
{
	int hour, minute, second, day, month, year=0;
	GetTime(hour, minute, second, day, month, year);
	ofstream write;               
	write.open("Bank_Transaction_History_Xinyu_Lyu.txt",ios::app);                          // open and write
	write << event << "\t" << amount << "\t" << month << "/" << day << "/" << year << "\t" << balance << endl;
	write.close();
}
void BankAccount::Read_CashBalance()
{
        string event,date;
		double amount = 0;
	    double balance = 10000.0;
		fstream read;
		read.open("Bank_Transaction_History_Xinyu_Lyu.txt");
		while (read >> event >> amount >> date >> balance) {}                        // read out the bank account information,
		setCash_Balance(balance);
}
void BankAccount::print_Title()                                
{
		 cout << "Bank Transation History" << endl << endl;
		 cout << left << setw(15) << "Event" << setw(20) << "Amount($)" << setw(20) << "Date" << setw(20) << "Balance($)" << endl;
		 fstream read;
		 read.open("Bank_Transaction_History_Xinyu_Lyu.txt");                                   // open and read
		 string event, date;
		 double amount, balance;
		 while (read >> event >> amount >> date >> balance)
		 {
			 cout << left << setw(15) << event << setw(20) << fixed << setprecision(2) << amount << setw(20) << date << setw(20) << fixed << setprecision(2) << balance << endl;
		 }
		 cout << endl;
		 read.close();
}
void BankAccount::bridge()
{
	cout << "The bridge in bankaccount" << endl;
	cout << endl;
}