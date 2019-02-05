
#include <iostream>
using namespace std;
#include <iomanip>
#include "Booklist_lastName.h"

Booklist::Booklist()
{
	for (int i = 0; i < 20; i++)
	{
		a[i] = 0;
	}
}


void Booklist::insert(int mylist[], int new_element)
{
	int i = 0;
	if (number >= 20)
	{
		cout << "The BookList is full." << endl;
	}
	else
	{
		while (mylist[i] != '\0' && i < number)
		{
			i++;
		}
		mylist[i] = new_element;
		numberplus();
	}
	print(mylist, number);
}
void Booklist::insert_at(int mylist[], int at_position, int new_element)
{
	int i = 0;
	if (number >= 20)
	{
		cout << "The BookList is full." << endl;
	}
	else
	{

		for (i = number; i >= at_position; i--)
		{
			mylist[i] = mylist[i - 1];
		}
		mylist[at_position - 1] = new_element;
		numberplus();
	}
	print(mylist, number);
}

int Booklist::find_linear(int mylist[],  int element)

{
	for (int j = 0; j <number; j++)

		if (mylist[j] == element)  // if found,                   
			return j + 1;
	// return location of key      

	return 0;  // key not found  
}

int Booklist::find_binary(int mylist[],  int element, bool sorted)
{
	int middle;
	int low = 0;
	int high = number - 1;

	if (sorted == 1)
	{
		// loop until low subscript is greater than high subscript
		while (low <= high)
		{
			// determine middle element of subarray being searched
			middle = (low + high) / 2;
			// display subarray used in this loop iteration
			if (element == mylist[middle])  // match
				return middle + 1;
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
		return 0;  // searchKey not found
	}
	else if (sorted == 0)
	{
		cout << "The list needs to be sorted first before performing binary search." << endl;
		return 0;  // searchKey not found
	}

}
void Booklist::delete_item_position(int mylist[], int position)
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
		numberminus();
	}
	print(mylist, number);
}
void Booklist::delete_item_isbn(int mylist[], int element)
{
	int position = find_linear(mylist,element);
	if (position != 0)
	{
		delete_item_position(mylist, position);
		cout << "number: " << number << endl;
	}
	else                                                                                           //not found 
	{
		cout << "There is no book with the ISBN(" << element << ") to delete." << endl;
		print(mylist, number);
	}
}
void Booklist::sort_list_selection(int mylist[], int num_in_list)
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
	print(mylist, num_in_list);
}
void Booklist::sort_list_bubble(int mylist[], int num_in_list)
{
	int hold;
	for (int i = 0; i < num_in_list - 1; i++)
		// loop to control number of comparisons per pass
		for (int j = 0; j < num_in_list - 1 - i; j++)
			// compare side-by-side elements and swap them if
			// first element is greater than second element
			if (*(mylist + j) > *(mylist + j + 1))
			{
				hold = *(mylist + j);
				*(mylist + j) = *(mylist + j + 1);
				*(mylist + j + 1) = hold;
			} // end if
	print(mylist, num_in_list);
}

void Booklist::Menu()
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
void Booklist::swap(int *testArrayPtr, int smaller, int pass)
{
	int temp = *(testArrayPtr + pass);
	*(testArrayPtr + pass) = *(testArrayPtr + smaller);
	*(testArrayPtr + smaller) = temp;
}
void Booklist::print(int mylist[], int num_in_list)
{
	cout << "The BookList is:" << endl;
	for (int i = 0; i < num_in_list; i++)
	{
		cout << setw(7) << mylist[i];
	}
	cout << endl;
	cout << "The number is:" << num_in_list << endl;
}
void Booklist::insert_delete_item_position(int mylist[], int new_element, int position)        //if find the same one, delete the first then insert
{
	int i = 0;
	if (number >= 20)
	{
		cout << "The BookList is full." << endl;
	}
	else
	{
		while (mylist[i] != '\0' && i < number)
		{
			i++;
		}
		mylist[i] = new_element;
		numberplus();
	}
	for (int i = position; i < 20; i++)
	{
		mylist[i - 1] = mylist[i];
	}
	numberminus();
	print(mylist, number);
}

void Booklist::delete_item_position_insert_at(int mylist[], int position, int at_position, int new_element)         
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
		numberminus();
	}
	for (int i = number; i >= at_position; i--)
	{
		mylist[i] = mylist[i - 1];
	}
	mylist[at_position - 1] = new_element;
	numberplus();
	print(mylist, number);
}
void Booklist::delete_item_position_insert(int mylist[], int position, int new_element)
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
		numberminus();
	}
	int i = 0;
	while (mylist[i] != '\0' && i < number)
	{
		i++;
	}
	mylist[i] = new_element;
	numberplus();
	print(mylist, number);
}
void Booklist::numberplus()
{
	number++;
}
void Booklist::numberminus()
{
	number--;
}
int Booklist::getnumber()
{
	return number;
}
void Booklist::setposition(int p)
{
	position = p;
}
int Booklist::getposition()
{
	return position;
}