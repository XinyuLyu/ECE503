#include"DoubleLinkList_Xinyu_Lyu.h"
#include<string>
#include<iomanip>
using namespace std;
DoubleLinkList::DoubleLinkList(RealTime_Price &price)                      //construction
{
	p = price;
	firstPtr =lastPtr= 0;
}
DoubleLinkList::~DoubleLinkList()                                    //destruction delete the node of the  whole linklist
{
	Node *tempPtr;
	if (!isEmpty())
	{
		Node *currentPtr =firstPtr ;
		Node *tempPtr;
		while (currentPtr != 0)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
}
void DoubleLinkList::insertNode(Node *element)                              
{
	Node *tempPtr = new Node
	(element->Stock_Company,element->Stock_Number,element->Stock_Price);
	tempPtr->Stock_TolVal = element->Stock_TolVal;
	if (isEmpty())                                                            // if no node   
	{
		firstPtr = tempPtr;
		lastPtr = tempPtr;
		
	}
	else if (firstPtr == lastPtr)                                             // if one node
	{
		if (tempPtr->Stock_TolVal < firstPtr->Stock_TolVal)                   //sort when insert
		{
			firstPtr->next = tempPtr;
			tempPtr->prev = firstPtr;
			lastPtr=tempPtr;
			
		}
		else
		{
			tempPtr->next = firstPtr;
			firstPtr->prev = tempPtr;
			firstPtr = tempPtr;
			
		}
	}
	else                                                                         // more then one node
	{
		Node*currentPtr = firstPtr;
		while ((currentPtr != lastPtr) && (currentPtr->Stock_TolVal >= tempPtr->Stock_TolVal))        // sort when insert  
		{
			currentPtr = currentPtr->next;
		}
		if (currentPtr==firstPtr)
		{
			firstPtr->prev = tempPtr;
			tempPtr->next = firstPtr;
			firstPtr = tempPtr;
			
		}
		else if (currentPtr == lastPtr)
		{
			if(tempPtr->Stock_TolVal<lastPtr->Stock_TolVal)
			{
				firstPtr->next = tempPtr;
				tempPtr->prev = firstPtr;
				lastPtr = tempPtr;
				
			}
			else
			{
				currentPtr->prev->next = tempPtr;
				tempPtr->prev = lastPtr->prev;
				tempPtr->next = lastPtr;
				lastPtr->prev = tempPtr;
				
			}
		}
		else
		{
			currentPtr->prev->next = tempPtr;
			tempPtr->prev = currentPtr->prev;
			tempPtr->next = currentPtr;
			currentPtr->prev = tempPtr;
			
		}

	}
	
}
void DoubleLinkList::deleteNode(string company)
{
	if (!isEmpty())                                                            // not empty
	{
		Node*tempPtr = firstPtr;
		if ((firstPtr == lastPtr) && (company == firstPtr->Stock_Company))   //only one node
		{
			firstPtr =lastPtr = 0;
			delete tempPtr;
		}
		else
		{
			if (company == firstPtr->Stock_Company)                           //if at first
			{
				firstPtr->next->prev = NULL;
				firstPtr = firstPtr->next;
				delete tempPtr;
			}
			else
			{
				while ((company !=tempPtr->Stock_Company ) && (tempPtr != lastPtr))    // not the last loop to find
				{
					tempPtr = tempPtr->next;
				}
				if (tempPtr == lastPtr)                                             // last one
				{
					if (company ==tempPtr->Stock_Company )                       //it find 
					{
						tempPtr->prev->next = NULL;
						lastPtr = tempPtr->prev;
						delete tempPtr;
					}
					else
					{
						cout << "Item Not Found." << endl;
					}
				}
				else                                       // not the last one or the first one delete
				{
					tempPtr->prev->next = tempPtr->next;
					tempPtr->next->prev = tempPtr->prev;
					delete tempPtr;
				}
			}

		}
	}
}
bool DoubleLinkList::isEmpty()const                                          
{
	return firstPtr==0;
}
bool DoubleLinkList::isExist(string company)
{
	Node*tempPtr = firstPtr;
	if (isEmpty())
	{
		return false;
	}
	else
	{
		if (firstPtr == lastPtr)                               // if only one node in the list
		{
			if (tempPtr->Stock_Company == company)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			while ((tempPtr->Stock_Company!=company)&&(tempPtr!=lastPtr))            // loop to find not the last
			{
				tempPtr = tempPtr->next;
			}
			if (tempPtr == lastPtr)                                                  // if the last
			{
				if (lastPtr->Stock_Company == company)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}
		}
	}
}
void DoubleLinkList::changePrice()                                               //load new price to all the node of price and totalvalue
{
	Node* tempPtr = firstPtr;
	if (tempPtr==NULL)
	{
		return;
	}
	while (tempPtr->next!=NULL)
	{

		tempPtr->Stock_Price = p.getStock_Price(tempPtr->Stock_Company);
		tempPtr->Stock_TolVal = tempPtr->Stock_Number*tempPtr->Stock_Price;
		tempPtr = tempPtr->next;
	}
	if (tempPtr->next == NULL)
	{
		tempPtr->Stock_Price = p.getStock_Price(tempPtr->Stock_Company);
		tempPtr->Stock_TolVal = tempPtr->Stock_Number*tempPtr->Stock_Price;
	}
}
void DoubleLinkList::sortList()                                      
{
		/*if (firstPtr == lastPtr){}
		else
		{
			Node* tempPtr = firstPtr;
				while ((tempPtr->next!=NULL))
				{
					if ((tempPtr->Stock_TolVal >= tempPtr->next->Stock_TolVal))
					{
						tempPtr= tempPtr->next;
					}
					else
					{
						string company=tempPtr->Stock_Company;
						int number = tempPtr->Stock_Number;
						double price = tempPtr->Stock_Price;
						double total = tempPtr->Stock_TolVal;
						deleteNode(company);
						Node *element = new Node
						(tempPtr->Stock_Company, tempPtr->Stock_Number, tempPtr->Stock_Price);
						element->Stock_TolVal = tempPtr->Stock_TolVal;
						insertNode(element);
						tempPtr = firstPtr;
					}
				}*/Node* tempPtr = firstPtr;
			while (tempPtr != NULL && tempPtr->next != NULL)
			{
				if (tempPtr->Stock_TolVal < tempPtr->next->Stock_TolVal)
				{
					string company = tempPtr->Stock_Company;
					int quant = tempPtr->Stock_Number;
					double price = tempPtr->Stock_Price;
					double total = tempPtr->Stock_TolVal;
					deleteNode(company);
					Node element (company, quant, price);
					element.Stock_TolVal = total;
					insertNode(&element);
					tempPtr = firstPtr;
				}
				else
					tempPtr = tempPtr->next;
			}
		
}
int DoubleLinkList::changeNumber(string company, int& number)
{                                                                                // buy or sell the stock already in the list
		Node*tempPtr = firstPtr;
		while (tempPtr!=NULL)
		{
			if(tempPtr->Stock_Company==company)//if find
			{
				tempPtr->Stock_Number += number;
				return tempPtr->Stock_Number;
				break;
			}
			tempPtr = tempPtr->next;
		}
		return 0;
}
double DoubleLinkList::getTolPortfolio()                                  // add together total portfolio and return
{
	Node *tempPtr = firstPtr;
	double totalportfolio = 0.0;
	while (tempPtr!=NULL)
	{
		totalportfolio += tempPtr->Stock_TolVal;
		if (tempPtr == lastPtr)
		{
			break;
		}
		tempPtr = tempPtr->next;
	}
	return totalportfolio;
}
int DoubleLinkList::getNumber(string company)                                 // return the number of stock with the stock company
{
	Node *tempPtr = firstPtr;
	while (tempPtr!=NULL)
	{
		if (tempPtr->Stock_Company == company)
		{
			return tempPtr->Stock_Number;
		}
		else
		{
			if (tempPtr==lastPtr)
			{
				return false;
			}
			tempPtr = tempPtr->next;
		}
	}
}
void DoubleLinkList::print()
{
	Node *currentPtr = firstPtr;
	sortList();
	while (currentPtr != NULL) {
		cout<<left <<setw(20) << currentPtr->Stock_Company << setw(20) << currentPtr->Stock_Number << setw(20)<< currentPtr->Stock_Price << setw(20)<< currentPtr->Stock_TolVal << endl;
		currentPtr = currentPtr->next;
	}
	
}
void DoubleLinkList::Write_currentPortfolio()                            // write the company number totalvalue to the Portfolio_Xinyu_Lyu.txt
{
	ofstream file;
	file.open("Portfolio_Xinyu_Lyu.txt", ofstream::out|ofstream::trunc);
	Node*tempPtr = firstPtr;
	while (tempPtr!=NULL)
	{
		file << (tempPtr->Stock_Company) << "\t" << (tempPtr->Stock_Number) << "\t" << (tempPtr->Stock_Price) << "\t" << tempPtr->Stock_TolVal << endl;
		tempPtr = tempPtr->next;
	}
	file.close();
}