#include <iterator>     //ostream_iterator and istream_iterator
#include <algorithm>    //foreach/replace_if/remove/sort/find/copy
#include <numeric>      //acummulate 
#include <iostream>     
#include<deque>         //pushback /erase/pushfront
#include<set>           //count_if
#include<vector>
using namespace std;
bool greater6(int x);
void outputHalf(int value);
int main()
{
	int sum = 0;
	std::deque<int>a;
	a.push_back(3);   //push back
	a.push_back(4);
	a.push_back(6);
	a.push_back(2);
	a.push_back(9);
	a.push_back(1);
	a.push_back(5);
	a.push_back(0);
	a.push_back(7);
	a.push_back(8);
	std::deque<int>::iterator remove_value;
	remove_value = remove(a.begin(), a.end(), 7);    //get the remove location --the first locatio after the removevalue
	a.erase(remove_value, a.end());                   //erase from remove location to the end
	replace_if(a.begin(), a.end(), greater6, 10);      //replace if bigger than 6
	sum = accumulate(a.begin(),a.end(),0);             //get sum
	cout << "The sum of the numbers 0 to 9 after removing 7 and replacig values greater than 6 with 10 is:" << sum << endl;
	a.push_front(sum);                                        //push front
	int number=count_if(a.begin(),a.end(),greater6);          //count if bigger than 6
	cout << "Now the number of elements greater than 6 is:" << number<<endl;
	cout << "The half of every element in the deque is: ";
    std::for_each(a.begin(), a.end(), outputHalf);           //get the half of each element without modifying them
	sort(a.begin(),a.end());                                   //sort
 	auto Index = find(a.begin(), a.end(), 6);               //find the 6 return its location
	cout << endl;
	cout << "After sorting, the location of 6 is at index:"<<Index - a.begin() << endl;  
	std::ostream_iterator<int>output(cout, ",");       //cout with , 
	cout << "The items in the deque are:";
	std::copy(a.begin(), a.end(), output);
	cout << endl;
	system("pause");
	return 0;
}
bool greater6(int x)
{
	return x > 6;
}
void outputHalf(int value)
{
	cout << value / 2 << ' ';
}