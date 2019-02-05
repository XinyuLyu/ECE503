
#include <iostream>
#define N 5                                           // input how much number you want to compare
using namespace std;   
int MAX(int a[N]);                                    //function declaration: get the max number
int MIN(int a[N]);                                    //function declaration: get the min number

int main()
{
	int i;
	int a[N];
	int max;
	int min;

	cout <<"Please insert   "<< N <<"   numbers"<< endl; //insert numbers
	for (i = 0; i < N; i++)
	{
		cin >> a[i];                                  
	}

	max = MAX(a);                                      //call functions   
	min = MIN(a);

	cout<< "The max number is:" << max << endl;        //print 
	cout << "The min number is:" << min << endl;
	system("pause");                                   //VS 2015 need this for demonstration
	return 0;
}


int MAX(int a[N])                                      //get the max number  
{
	int i;
	int temp=a[0];
	for (i = 0; i < N; i++)                           
	{
		if (a[i] >= temp)
		{
			temp = a[i];
		}
	}
	return temp;
}



int MIN(int a[N])                                      //get the min number  
{
	int i;
	int temp = a[0];
	for (i = 0; i < N; i++)
	{
		if (a[i]< temp)
		{
			temp = a[i];
		}
	}
	return temp;
}





