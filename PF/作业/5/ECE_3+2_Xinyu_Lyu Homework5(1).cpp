#include<iostream>
#include<vector>
using namespace std;
void recursion(int n);
int main()
{
	int n;
	cout << "Please input a positive interger:";
	cin >> n;
	recursion(n);
	system("pause");
	return 0;
}

void recursion(int n)
{
	if (n % 2 == 1)                                          //n is odd interger
	{
		if (n == 1)                
		{
			cout << "1,";
		}
		else  if (n == 0)                                    //n=0,do not print
		{
		}
		else
		{
			cout << n*n << ",";
			recursion(n - 2);
			cout << (n - 1)*(n - 1) << ",";
		}
	}
	else                                                     //n is even interger
	{
		if (n==1)
		{
			cout << "1,";
		}
		else  if (n == 0)
		{
		}
		else
		{
			cout << (n - 1)*(n - 1) << ",";
			recursion(n - 2);
			cout << n*n << ",";
		}
	}
}

