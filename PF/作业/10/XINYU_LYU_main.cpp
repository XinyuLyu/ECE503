#include<iostream>
using namespace std;
#include<iomanip>
#include<string>
#include"XINYU_LYU_LinkedList.h"
#include<vector>
void Menu();
int main()
{
	int choice;
	string name;
	int no;
	LinkedList list;
	do {
		Menu();
		do
		{
			cout << "Please choose an option: " << endl;
			cin >> choice;
			if (choice < 0 || choice>8)
			{
				cout << "Valid Choice, input again." << endl;
			}
		} while (choice < 0 || choice>8);
		switch (choice)
		{
		case 1:
			cout << "Please enter product number to insert at beginning: "<< endl;
			cin >> no;
			cout << "Please enter the name for the product: " << endl;
			cin >> name;
			list.addToStart(name, no);
			list.printList();
			break;
		case 2:
			cout << "Please enter product number to insert at end: " << endl;
			cin >> no;
			cout << "Please enter the name for the product: " << endl;
			cin >> name;
			list.addToEnd(name, no);
			list.printList();
			break;
		case 3:
			if (list.removeFromStart())                           //if list can be remove from start remove and print
			{
				list.printList();
			}
			else
			{
				cout << "\n";
				cout << "Empty, can't remove from the start." << endl;
				cout << "\n";
			}
				break;
		case 4:
			if (list.removeFromEnd())                            //if list can be remove from end remove and print
			{
				list.printList();
			}
			else
			{
				cout << "\n";
				cout << "Empty, can't remove from the end." << endl;
				cout << "\n";
			}
			break;
		case 5:
			cout << "Please input the number you want to remove: "<<endl;
			cin >> no;
			if (list.removeNodeFromList(no)){}                                      //after remove print 
			list.printList();
			break;
		case 6:
			cout << "Please input the name you want to remove: " << endl;;           //after remove print
			cin >> name;
			if (list.removeNodeFromList_name(name)){}    
            list.printList();
			break;
		case 7:
			list.printList();
			break;
		case 8:
			break;
		default:
			break;
			}
		} while (choice != 8);
	system("pause");
	return 0;
}
	void Menu()
	{
		cout << "1.  Add a new node at the beginning" << endl;
		cout << "2.  Add a new node at the end" << endl;
		cout << "3.  Remove the beginning node" << endl;
		cout << "4.  Remove the end node" << endl;
		cout << "5.  Remove a node from the list by entering an item number" << endl;
		cout << "6.  Remove a node from the list by entering an item name" << endl;
		cout << "7.  Print out the list" << endl;
		cout << "8.  Quit the program" << endl;
	}