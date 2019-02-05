// IntegerSet.cpp
// Member-function definitions for class IntegerSet.

#include <iostream>
#include <iomanip>
using namespace std;
#include"IntegerSet.h"
// constructor
IntegerSet::IntegerSet()
{
	for (int i = 0; i < 101; i++) set[i] = 0;
} // end IntegerSet constructor

  // input a set from the user
void IntegerSet::inputSet()
{
	int number;
	do
	{
		cout << "Enter an element (-1 to end): ";
		cin >> number;
		if (validEntry(number))
			set[number] = 1;
		else if (number != -1)
			cout << "Invalid Element\n";
	} while (number != -1); // end do...while
	cout << "Entry complete\n";
} // end function inputSet

  // prints the set to the output stream
void IntegerSet::printSet() const
{
	cout << "{ ";
	for (int u = 0; u < 101; u++)
		if (set[u]) cout << u << " ";
	cout << "}" << endl;
	} // end function printSet

	  /* Write definition for unionOfSets */

IntegerSet operator +(IntegerSet a, IntegerSet b)
{
	IntegerSet c;
	for (int i = 0; i < 101; i++)
		c.set[i] = a.set[i] + b.set[i];	
	return c;
}
void IntegerSet::unionOfSets(IntegerSet a, IntegerSet b,IntegerSet &c)
{
	c = a + b;
}
  /* Write definition for intersectionOfSets */
IntegerSet operator *(IntegerSet a, IntegerSet b)
{
	IntegerSet c;
	for (int i = 0; i<101; i++)
			if (a.set[i] == b.set[i])
			{
				c.set[i] = a.set[i];
			}
	return c;
}
void IntegerSet::intersectionOfSets(IntegerSet a, IntegerSet b, IntegerSet &d)
{
	d = a*b;
}
	



