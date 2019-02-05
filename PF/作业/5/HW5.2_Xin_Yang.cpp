/*/ Name: Xin Yang
// Course: 16:332:503, Programming Finance
// Example: Homework 5.2
// Submitting date: Oct/12/2017
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool recursion(vector<int> array, int index)
{
	if (array[index]<0)//if visited return false
		return false;
	else
		array[index] = -abs(array[index]);//if not visited, set as negative

	if (array[index] == 0)//if reaches zero, return true
		return true;

	if (index + abs(array[index]) < array.size())//if left move within boundary
	{
		if (recursion(array, index + abs(array[index])))//if recursion is true, return true, else move ahead
			return true;
	}

	if (index - abs(array[index]) >= 0)//if right move within boundary
	{
		if (recursion(array, index - abs(array[index])))//if
			return true;
		else
			return false;
	}
	return false;
}

int main()
{
	int in = -1;
	vector <int> array;
	cout << "please input array, end by 0" << endl;
	cin >> in;
	int count = 0;
	if (in <= 0)
	{
		cout << "invalid array!" << endl;
	}
	else
	{
		while (in >= 0)
		{
			array.push_back(in);
			if (in == 0)
				break;
			count++;
			cin >> in;
		}
	}
	int index = 0;//set index
	recursion(array, index) ? cout << "true" << endl : cout << "false" << endl;//print result
	system("pause");
}*/