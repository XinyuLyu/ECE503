/*
#include <iostream>
#include <iomanip>
#include<string> 
using namespace std;
void insert(int mylist[], int& num_in_list, int new_element);
void insert_at(int mylist[], int &num_in_list, int at_position, int new_element);
int find_linear(int mylist[], int num_in_list, int element);
int find_binary(int mylist[], int num_in_list, int element, bool sorted);
void delete_item_position(int mylist[], int &num_in_list, int position);
void delete_item_isbn(int mylist[], int& num_in_list, int element);
void sort_list_selection(int mylist[], int num_in_list);
void sort_list_bubble(int a[], int arraySize);
void print(int mylist[], int num_in_list);                                                
void Menu();
void swap(int *testArrayPtr, int smaller, int pass);
int main()
{
	int ISBN;
	int position;
	int a[20] = { 0,0,0 };
	int choice;
	int number = 0;                                                                         //the number of elements in the booklist
	int t = 0;                                                                              //the symbol of found or not found
	int order;   //sorted or insorted in binary find

	Menu();
	cout << "Enter your Choice(1 or 2) to insert a element at position 1:" << endl;
	cin >> choice;

	while (choice != 10)
	{
		switch (choice)
		{
		case 1:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> ISBN;
			t = find_linear(a, number, ISBN);
			if (t == -1)                                                        
			{
				insert(a, number, ISBN);
				cout << "number: " << number << endl;
				print(a, number);
			}
			else
			{                                                                                //if find the same one, delete the first then insert 
				insert(a, number, ISBN);
				delete_item_position(a, number, t);
				cout << "number: " << number << endl;
				print(a, number);
			}
			break;
		case 2:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> ISBN;
			do {
				cout << "Input which position you want to insert:" << endl;             
				cin >> position;
			} while (position < 1 || position>20);                                            //can't insert more than 20 elements

			if (position >= 1 && position <= number)                                          
			{
				t = find_linear(a, number, ISBN);
				if (t == -1)
				{
					insert_at(a, number, position, ISBN);
					cout << "number: " << number << endl;
					print(a, number);
				}
				else
				{
					insert_at(a, number, position, ISBN);
					delete_item_position(a, number, t);
					cout << "number: " << number << endl;
					print(a, number);
				}
			}
			else 
			{
				if (t == -1)                                                                   //if position is bigger than the number of elements int the booklist insert at the end of the booklist
				{
					insert(a, number, ISBN);
					cout << "number: " << number << endl;
					print(a, number);
				}
				else
				{
					insert(a, number, ISBN);
					delete_item_position(a, number, t);
					cout << "number: " << number << endl;
					print(a, number);
				}
			}
			break;

		case 3:
			cout << "Input ISBN(first digital can't be 0):" << endl;
			cin >> ISBN;
			t = find_linear(a, number, ISBN);
			if (t == -1)
			{
				cout << "Not found." << endl;
			}
			else {
				cout << "The position is: " << t << endl;
			}
			break;

		case 4:
			cout << "Input ISBN(first digital can't be 0):" << endl;                        
			cin >> ISBN;
			cout << "Sorted:1 " << endl;
			cout << "Unsorted:0" << endl;
			cin >> order;
			t = find_binary(a, number, ISBN, order);
			if (t == -1)
			{
				cout << "Not found." << endl;
			}
			else {
				cout << "The position is: " << t << endl;
			}
			break;
		case 5:
			do
			{
			cout << "Input which position(1=<position<="<<number<<") you want to Delete:" << endl;
			cin >> position;
			} while (position<1 || position>number);
            delete_item_position(a, number, position);
			cout << "number: " << number << endl;
			print(a, number);
			break;
		case 6:
			cout << "Input which ISBN(first digital can't be 0) you want to Delete:" << endl;
			cin >> ISBN;
			delete_item_isbn(a, number, ISBN);
			break;
		case 7:
			sort_list_selection(a, number);
	        cout << "number: " << number << endl;
			print(a, number);
		
			break;
		case 8:
			sort_list_bubble(a, number);
			cout << "number: " << number << endl;
			print(a, number);
			break;
		case 9:
			print(a, number);
			cout << "number: " << number << endl;
			break;
		case 10:
			break;
		default:
			break;
		}
		do {
			Menu();
			cout << "Enter your Choice(1=<choice<=10):" << endl;
			cin >> choice;
		} while (choice > 10 || choice < 1);
	}
	system("pause");
	return 0;
}







void insert(int mylist[], int &num_in_list, int new_element)
{
	int i = 0;
	if (num_in_list >= 20)
	{
		cout << "The BookList is full." << endl;
	}
	else
	{
		while (mylist[i] != '\0' && i < num_in_list)
		{
			i++;
		}
		mylist[i] = new_element;
		num_in_list++;
	}

}
void insert_at(int mylist[], int &num_in_list, int at_position, int new_element)
{
	int i = 0;
	if (num_in_list >= 20)
	{
		cout << "The BookList is full." << endl;
	}
	else
	{
		for (i = num_in_list; i >= at_position; i--)
		{
			mylist[i] = mylist[i - 1];
		}
		mylist[at_position - 1] = new_element;
		num_in_list++;
	}
}
int find_linear(int mylist[], int num_in_list, int element)

{
	for (int j = 0; j <20; j++)

		if (mylist[j] == element)  // if found,                   
			return j + 1;              // return location of key      

	return -1;  // key not found                                

} // end function linearSearch    

int find_binary(int mylist[], int num_in_list, int element, bool sorted)
{
	int middle;
	int low = 0;
	int high = num_in_list-1;

	if (sorted == 1)
	{
		// loop until low subscript is greater than high subscript
		while (low <= high)
		{
			// determine middle element of subarray being searched
			middle = (low + high) / 2;
			// display subarray used in this loop iteration
			if (element == mylist[middle])  // match
				return middle+1;
			else
				// if searchKey less than middle element, 
				// set new high element
				if (element < mylist[middle])
					high = middle - 1;  // search low end of arr
										// if searchKey greater than middle element, 
										// set new low element
				else
					low = middle + 1;   // search high end of array
		}
		return -1;  // searchKey not found
	}
	else if(sorted==0)
	{
		cout << "The list needs to be sorted first before performing binary search." << endl;
		return -1;  // searchKey not found
	}

}

void delete_item_position(int mylist[], int &num_in_list, int position)
{
	if (mylist[position] == '0')                                                        //no element at this position
	{
		cout << "There is no element here." << endl;
		
	}
	else
	{
		for (int i = position; i < 20; i++)
		{
			mylist[i - 1] = mylist[i];

		}
		num_in_list--;
	}
}

void delete_item_isbn(int mylist[], int& num_in_list, int element)
{
	int position = find_linear(mylist, num_in_list, element);
	if (position != -1)                                                               
	{
		delete_item_position(mylist, num_in_list, position);
		cout << "number: " << num_in_list << endl;
		print(mylist,num_in_list);
	}
	else                                                                                           //not found 
	{
		cout << "There is no book with the ISBN(" << element << ") to delete." << endl;
		print(mylist, num_in_list);
	}
}

void sort_list_selection(int mylist[], int num_in_list)
{
	int j, k, sm_index;	int smallest;
   for (k = 0; k < num_in_list - 1; k++)	 // num_in_list-1 = number of passes
	{
		smallest = *(mylist + k);
		sm_index = k;
		for (j = k + 1; j <num_in_list; j++)
			if (mylist[j] < smallest)
			{
				smallest = *(mylist + j);
				sm_index = j;
			}
		swap(mylist, sm_index, k);	// call to swap()
	}
}

void swap(int *testArrayPtr, int smaller, int pass)
{					// pass = current position: k

	int temp = *(testArrayPtr + pass);
	*(testArrayPtr + pass) = *(testArrayPtr + smaller);
	*(testArrayPtr + smaller) = temp;
}

void sort_list_bubble(int a[], int arraySize)
{
	int hold;
	for (int pass = 0; pass < arraySize - 1; pass++)
		// loop to control number of comparisons per pass
		for (int j = 0; j < arraySize - 1 - pass; j++)
			// compare side-by-side elements and swap them if
			// first element is greater than second element
			if (*(a + j) > *(a + j + 1))
			{
				hold = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = hold;
			} // end if

}

void print(int mylist[], int num_in_list)                                                   //print the booklist
{
	cout << "The BookList is:" << endl;
	for (int i = 0; i < num_in_list; i++)
	{
		cout << setw(7) << mylist[i];
	}
	cout << endl;
}


void Menu()
{
	cout << "Menu" << endl;
	cout << "Choice 1: Insert new element at the end of the list." << endl;
	cout << "Choice 2: Insert new element at a certain position." << endl;
	cout << "Choice 3:Find an element.(using linear search)" << endl;
	cout << "Choice 4: Find an element of a sorted list.(using binary search)" << endl;
	cout << "Choice 5: Delete an element that is at a certain position." << endl;
	cout << "Choice 6: Delete an element by using its ISBN number." << endl;
	cout << "Choice 7: Sort the list by the ISBN numbers.(using selection sort)" << endl;
	cout << "Choice 8: Sort the list by the ISBN numbers.(using bubble sort)" << endl;
	cout << "Choice 9: Print the BookList." << endl;
	cout << "Choice 10: Quit." << endl;
}
*/



	














