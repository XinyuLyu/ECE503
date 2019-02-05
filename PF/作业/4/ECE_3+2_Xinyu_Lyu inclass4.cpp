#include <iostream>

using namespace std;
const int SIZE = 100;
int rCount(char *L, char c, int  &number);
int main()
{
	char c;
	char s[SIZE];
	int number=0;                                                                                 //Number for counter
	 
	cout << "Please input your string(at most 100 characters):" << endl;                         //Input string s
	cin.getline(s, 20);                                                
	cout << "The string is:" << endl;
	cout << s << endl;
	 
	cout << "Please input the character you want to find:" << endl;                              //Input character c
	cin >> c;
	cout << "The character is:" << c<<endl;

	rCount(s,c,number);                                                                          //Recursive Functions:count the occurance number of character c in string s 

	cout << "The string has " << number << " numbers of the character you input" << endl;        //Output the result

	system("pause");
	return 0;
}
int rCount(char *L,char c,int &number)
{
	
	if (*L == '\0') return 0;                                                                     //Terminal condition to end recursion:searcing into the end of the string
	rCount(L+1,c,number);                                                                         //Recursive function
	if (*L == c)                                                                                  
	{
		number++;
	}
	return 0;
}

