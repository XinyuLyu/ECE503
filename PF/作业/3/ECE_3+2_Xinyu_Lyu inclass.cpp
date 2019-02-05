#include<iostream>
#include<iomanip>

using namespace std;
void mode(int[], int[], int);

int main()

{
	const int VotersNumber = 20;                                                                //The number for woters
	int frequency[6] = { 0 };                                                                   //The array for each candidate's votes number
	int  response[VotersNumber] = {};                                                           //The array for each voter's choice

	for (int i = 0; i <= VotersNumber - 1; i++)                                                 //i:the number for voters
	{
		cout << "You voter number is: " << i + 1 << " . Please vote one candidate(1,2,3,4,5):" << endl;//Remind voters to enter the correct number 
		cin >> response[i];

		while (1 > response[i] || response[i] > 5)                                               //Detect the wrong number and remind voters to correct it
		{
			cout << "Wrong number! Please vote the number 1,2,3,4,5:" << endl;
			cout << "You are voter  " << i + 1 << "  Please vote one candidate(1,2,3,4,5):" << endl;
			cin >> response[i];
		}

	}

	mode(frequency, response, VotersNumber);
	system("pause");
	return 0;
}



void mode(int freq[], int resp[], int voternum)                                                 //The function to tally the votes and find the winner
{

	int largest = 0;                                                                            //largest: the largest votes number of one candidate
	int modeValue = 0;                                                                          //modeValue:the number for the winner

	for (int i = 1; i <= 5; i++)                                                                //Initialize the array
	{
		freq[i] = 0;
	}

	for (int j = 0; j <= (voternum - 1); j++)                                                   //Tally the votes for every candidate
	{
		++freq[resp[j]];
	}

	cout << '\n';
	cout << "*********************  The Result  **********************" << endl;                //Print the headline for results 
	cout << '\n';
	cout << "candidate" << setw(23) << "the number of votes" << endl;


	for (int CandidateNum = 1; CandidateNum <= 5; CandidateNum++)                               //Find the candidate number with the most votes and his number of votes
	{
		cout << setw(9) << CandidateNum << setw(22) << freq[CandidateNum] << endl;

		if (freq[CandidateNum] > largest)
		{
			largest = freq[CandidateNum];
			modeValue = CandidateNum;
		}
	}

	for (int k = 1; k <= (5 - modeValue); k++)                                                  //Check if there are more than 1 people who have the same highest vote counts and print the corresponding results
	{
		if (freq[modeValue] == freq[modeValue + k])
		{
			cout << "There is no winners." << endl;
			break;
		}
		if (k == 5 - modeValue)
		{
			cout << "The winner is candidate " << modeValue << " who has " << largest << " votes." << endl;
		}
	}

}

