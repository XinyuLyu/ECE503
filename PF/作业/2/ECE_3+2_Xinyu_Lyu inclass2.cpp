#include "iostream"
#include<cmath>
using namespace std;
int main()
{
	
		int i;                                                                         //i:the number of lines 
		int j;                                                                         //j:the number of " "
		int k;                                                                         //k:the number of "*"
		int N;                                                                         //N;the maximum number of stars in each line                  
																						
		
		cout << "Input a maximum number(odd number) of stars in each line :" << endl;
		cin >> N;

		while (N % 2 == 0)                                                             //N must be a odd umber
		{
			cout << "Sorry,must be a odd number:" << endl;
			cin >> N;
		}

		for (i = 1; i <= N; i++)                                                       
		{
			for (j = 1; j <=abs((N+1)/2-i); j++)                                       
				cout<<" ";                                                             //insert" "
			for (k = 1; k <= N - 2 * abs((N + 1) / 2 - i); k++)                        
				cout<<"*";                                                             //insert"*"
			cout<<'\n';                                                                //start a new line
		}

		system("pause");                                                               //VS2015 needs the statement to print results
		return 0;
}