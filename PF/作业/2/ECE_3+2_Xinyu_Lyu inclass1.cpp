#include "iostream"
using namespace std;
int main()
{
	int N;
	cout << "How many lines of * you want:" << endl; 
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";                             //insert "*"
		}
	    cout << '\n';                                //start a new line
	}
	system("pause");                                 //VS2015 needs the statement to print results
	return 0;
}
