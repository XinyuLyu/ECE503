#include <iostream>
using namespace std;
bool Jump(int a, int b, int c[], int size);
int main()
{
	int c[10000] = {};
	int i = 0;

	cout << "Input:" << endl;
	cin >> c[i];

	while (c[i] != 0) {
		cout << "Input" << endl;
		i++;
		cin >> c[i];
	}
	cout << "size:"<<i + 1 << endl;
	int size = i + 1;
	Jump(0, c[0], c, size) ? cout << "True" << endl : cout << "False"<<endl;

	system("pause");
	return 0;
}


bool Jump(int a, int b, int c[], int size)                      //a:current position; b:current value
{
	int hold;
	int temp = 0;

	if (b == 0)
		return true;

	if (b < 0)
		return false;
	else                                                        //Set -1 for the elements visited
	{
		temp = c[a];
		c[a] = -1;
	}


	if (b <(size - a))                                          //If right move in boundary, move right
	{
		hold = temp;
		c[a] = -1;
		if (Jump(a + hold, c[a + hold], c, size))                //If the recursion is true,return ture
			return true;
	}

	if (b < (a + 1))                                             //If left move in boundary, move left
	{
		hold = temp;
		c[a] = -1;
		if (Jump(a - hold, c[a - hold], c, size))               
			return true;
		else 
			return false;                                          //If the recurison is false return false
	}
	return false;
}


