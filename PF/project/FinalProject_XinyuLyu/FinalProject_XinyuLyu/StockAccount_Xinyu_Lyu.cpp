#include"StockAccount_Xinyu_Lyu.h"
StockAccount::StockAccount(){}
StockAccount::~StockAccount(){}
void StockAccount::Display_Stock_Price(RealTime_Price&r)          
{
	string company;
	cout << "Please enter the stock symbol: ";
	cin >> company;
	double t = r.getStock_Price(company);
	if (t!=-1)                                                // if find the stock company 
	{
		cout << "Company Symbol Price per share " << company << " $" << t<<endl;
	}
	else
	{
		cout << "The company cannot be found" << endl;
	}
}
void StockAccount::Display_currentPortfolio(DoubleLinkList &list)                
{
	cout << "Cash Balance= $" << getCash_Balance() << endl;;
	if (list.isEmpty()) {                                                 // if empty
		cout << "Your Portfolio is empty." << endl;
	}
	else
	{
		list.changePrice();                                               // realtime price
		list.sortList();                                                   // sort before display
		cout << left << setw(20) << "CompanySymbol" << setw(20) << "Number" << setw(20) << "PricePerShare($)" << setw(20) << "TotalValue($)" << endl;
		list.print();                                                     
		cout << "Total portfolio value: $" << fixed << setprecision(2) << getCash_Balance() + list.getTolPortfolio() << endl << endl;
	}
}
void StockAccount::Buy( DoubleLinkList& list, RealTime_Price& r)
{
	string company;
	int number;
	double price;
	cout << "Please enter the stock symbol you wish to purchase: ";
	cin >> company;
	double t = r.getStock_Price(company);//realtime price
	if (t!=-1)//have this company
	{
		cout << "Please enter the number of shares: ";
		cin >> number;
		if (number*t > getCash_Balance())
		{
			cout << "You don't have enough money in your bank account." << endl;
		}
		else//enough money
		{
			cout << "Please enter the maximum amount you are willing to pay per share: $";
			cin >> price;
			if (price < t)
			{
				cout << "The cost per stock is higher than the amount you are willing to pay" << endl;
			}
			else//price>=t
			{
				if (list.isExist(company))//exist
				{
					int newnumber = list.changeNumber(company, number);
					list.deleteNode(company);
					Node *tempPtr = new Node(company, newnumber, t);
					tempPtr->setTolVal(t, newnumber);
					list.insertNode(tempPtr);
					setCash_Balance(getCash_Balance() - t*number);
					Write_History("Buy", company, number, t, number*t);
					cout << "You have purchased " << number << " shares of " << company << " at $" << t << " each for a total of $" << number*t<<endl;
					Write_Graph_Data(list);
					list.Write_currentPortfolio();
				}
				else
				{
					Node *tempPtr = new Node(company, number, t);
					tempPtr->setTolVal(t, number);
					list.insertNode(tempPtr);
					setCash_Balance(getCash_Balance() - t*number);
					Write_History("Buy", company, number, t, number*t);
					cout << "You have purchased " << number << " shares of " << company << " at $" << t << " each for a total of $" << number*t<<endl;
					Write_Graph_Data(list);
					list.Write_currentPortfolio();
				}
			}
		}
	}
	else//no this company
	{
		cout << "The company cannot be found" << endl;
	}
}
void StockAccount::Sell( DoubleLinkList& list, RealTime_Price&r)
{
	string company;
	int number;
	double price;
	cout << "PLease enter the stock company you want to sell: ";
	cin >>company ;
	if (list.isEmpty())
	{
		cout << "Your stock is empty." << endl;
	}
	else
	{
		if (list.isExist(company))
		{
			cout << "Please enter how many shares you want to sell: ";
			cin >> number;
			if (number > list.getNumber(company))
			{
				cout << "You don't have such amount of shares in your stock account" << endl;
			}
			else//have such amount
			{
				double t = r.getStock_Price(company);
				cout << "Please enter the minimal amout you are willing to sell per share: $";
				cin >> price;
				if (t<price)//too high
				{
					cout << "The cost per stock is lower than the amount you are willing to sell" << endl;
				}
				else
				{
					int n=list.getNumber(company);
					if (number == list.getNumber(company))//decrease to 0
					{
						list.deleteNode(company);
					    setCash_Balance(getCash_Balance()+price*number);
						Write_History("Sell", company, number,price,number*price);
						cout << "You have sell " << number << " shares of " << company << " at $" << price << " each for a total of $"<<number*price << endl;
						Write_Graph_Data(list);
						list.Write_currentPortfolio();
					}
					else
					{
						list.deleteNode(company);
						Node *tempPtr = new Node(company,n-number,price);
						tempPtr->setTolVal(price,n-number);
						list.insertNode(tempPtr);
						setCash_Balance(getCash_Balance() + price*number);
						Write_History("Sell", company, number, price, number*price);
						cout << "You have sell " << number << " shares of " << company << " at $" << price << " each for a total of $" << number*price << endl;
						Write_Graph_Data(list);
						list.Write_currentPortfolio();
					}
				}
			}
		}
		else
		{
			cout << "You don't have such stock in your stock account" << endl;
		}
	}
}
void StockAccount:: Write_History(string event, string company, int number, double price, double total)
{
	int hour, minute, second, day, month, year = 0;                                                       // write the information to the stock transaction history and the bank transcation history 
	GetTime(hour, minute, second, day, month, year);
	ofstream write_stock_history;
	write_stock_history.open("Stock_Transaction_History_Xinyu_Lyu.txt",ios::app);
	write_stock_history << event <<"\t"<<company<< "\t" << number << "\t" << price<<"\t" <<total<<"\t"<<hour<<":"<<minute<<":"<<second<< endl;
	write_stock_history.close();
	ofstream write_bank_history;
	write_bank_history.open("Bank_Transaction_History_Xinyu_Lyu.txt",ios::app);
	write_bank_history<<event << "\t" << total << "\t" << month << "/" << day << "/" << year << "\t" << getCash_Balance() << endl;
	write_bank_history.close();
}
void StockAccount::Print_Stock_History()
{
	cout << left << setw(15) << "Event" << setw(20) << "Company Symbol" << setw(20) << "Number" << setw(20) << "Price Per Share($)" << setw(20) << "Total Value($)" << setw(20) << "Time" << endl;
	fstream read_stock_history;
	read_stock_history.open("Stock_Transaction_History_Xinyu_Lyu.txt");
	string event, company, time;
	int number;
	double price, total;
	while (read_stock_history>>event>>company>>number>>price>>total>>time)
	{
		cout << left << setw(15) << event << setw(20) << company << setw(20) << number << setw(20)<<price << setw(20)<<total << setw(20) << time << endl;
	}
	read_stock_history.close();
}
void StockAccount::bridge()
{
	cout << "The bridge in stockaccount" << endl;
}