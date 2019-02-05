#include <iostream>
using namespace std;


#include "Booklist_lastName.h"
int main()
{
	Booklist booklist;
	booklist.Menu();
	cout << "Enter your Choice(1 or 2) to insert a element at position 1:" << endl;
	cin >> booklist.choice;
	while (booklist.choice != 10)
	{
		switch (booklist.choice)
		{
		case 1:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> booklist.ISBN;
			booklist.t = booklist.find_linear(booklist.a, booklist.ISBN);
			booklist.t ? booklist.insert_delete_item_position(booklist.a, booklist.ISBN, booklist.t)
				: booklist.insert(booklist.a, booklist.ISBN);
			break;
		case 2:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> booklist.ISBN;
			do {
				cout << "Input which position you want to insert:" << endl;
				cin >> booklist.position;
			} while (booklist.position < 1 || booklist.position>20);  //can't insert more than 20 elements
			booklist.t = booklist.find_linear(booklist.a,  booklist.ISBN);
			if (booklist.position >= 1 && booklist.position <= booklist.getnumber())
			{
				booklist.t ? booklist.delete_item_position_insert_at(booklist.a, booklist.t, booklist.position, booklist.ISBN)   //booklist.t delete, at_position add
					: booklist.insert_at(booklist.a, booklist.position, booklist.ISBN);
			}
			else if (booklist.position != 0)                                           //if position is bigger than the number of elements int the booklist insert at the end of the booklist
			{
				booklist.t ? booklist.delete_item_position_insert(booklist.a, booklist.t, booklist.ISBN)
					: booklist.insert(booklist.a, booklist.ISBN);
			}
			break;
		case 3:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> booklist.ISBN;
			booklist.t = booklist.find_linear(booklist.a,  booklist.ISBN);
			booklist.t ? cout << "The position is: " << booklist.t << endl : cout << "Not found." << endl;
			break;
		case 4:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> booklist.ISBN;
			cout << "Sorted:1 " << endl;
			cout << "Unsorted:0" << endl;
			cin >> booklist.order;
			booklist.t = booklist.find_binary(booklist.a,  booklist.ISBN, booklist.order);
			booklist.t ? cout << "The position is: " << booklist.t << endl : cout << "Not found." << endl;
			break;
		case 5:
			do
			{
				cout << "Input which position(1=<position<=" << booklist.getnumber()<< ") you want to Delete:" << endl;
				cin >> booklist.position;
			} while (booklist.position<1 || booklist.position>booklist.getnumber());
			booklist.delete_item_position(booklist.a, booklist.position);
			break;
		case 6:
			cout << "Input which ISBN(first digital can't be 0) you want to Delete:" << endl;
			cin >> booklist.ISBN;
			booklist.delete_item_isbn(booklist.a, booklist.ISBN);
			break;
		case 7:
			booklist.sort_list_selection(booklist.a, booklist.getnumber());
			break;
		case 8:
			booklist.sort_list_bubble(booklist.a, booklist.getnumber());
			break;
		case 9:
			booklist.print(booklist.a, booklist.getnumber());
			break;
		default:
			break;
		}
		do {
			booklist.Menu();
			cout << "Enter your Choice(1=<choice<=10):" << endl;
			cin >> booklist.choice;
		} while (booklist.choice > 10 || booklist.choice < 1);
	}
	return 0;
}

