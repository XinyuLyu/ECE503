#include<iostream>
#include<iomanip>

using namespace std;


int main()

{
	const int VotersNumber = 20;                                                                //The number for voters
	int candidate[6] = { 0 };                                                                   //The array for each candidate's votes number
	int largest = 0;                                                                            //largest: the largest votes number of one candidate
	int winnerNum = 0;                                                                          //winnerNum:the winner's number

	for (int j = 1,i=0; j<= VotersNumber ; j++)                                                 //j:the number for voters i:the number for candidate
	{
		cout << "You voter number is: " << j << " . Please vote one candidate(1,2,3,4,5):" << endl;//Remind voters to enter the correct number 
		cin >> i;
		while (1 > i || i > 5)                                                                   //Detect the wrong number and remind voters to correct it
		{
			cout << "Wrong number! Please vote the number 1,2,3,4,5:" << endl;
			cout << "You voter number is: " << j << " . Please vote one candidate(1,2,3,4,5):" << endl;
			cin >> i;
		}
		++candidate[i];                                                                              // Tally up the votes number for each candidate
	}

	cout << '\n';
	cout << "*********************  The Result  **********************" << endl;                //Print the headline for results 
	cout << '\n';
	cout << "candidate" << setw(23) << "the number of votes" << endl;


	for (int i= 1; i <= 5; i++)                                                                 //Find the candidate number with the most votes and his number of votes
	{                                                                                           //i:the number for candidate
		cout << setw(9) << i << setw(22) << candidate[i] << endl;

		if (candidate[i] > largest)                                                              // If candidate[2]=candidate[3]=largest,winnerNum is 2,not 3.
		{
			largest = candidate[i];
			winnerNum =i;
		}
	}

	for (int i = 1; i <= (5 - winnerNum); i++)                                                  //Check if there are more than 1 people who have the same highest vote counts and print the corresponding results
	{                                                                                           //i:the number for candidate
		if (candidate[winnerNum] == candidate[winnerNum + i])                                   // For instance, if candidate[2]=candidate[3]=largest, we only need to judge whether there is someone equal to largest among  candidate[3] candidate[4] candidate[5]
		{                                                                                       // therefore the loop number is 5 - winnerNum.
			cout << "There is no winner." << endl; 
			break;
		}
		if (i == 5 - winnerNum)                                                                  //Without breaking from the loop, it means there is a winner. In order not to cout many times int the loop ,I use if to judge whether it is the proper time to print the results. 
		{
			cout << "The winner is candidate " << winnerNum << " who has " << largest << " votes." << endl;
		}
	}
	system("pause");
	return 0;
}

