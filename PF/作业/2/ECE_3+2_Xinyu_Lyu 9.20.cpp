#include "iostream"
#include <time.h>
#include <stdlib.h>  
#include <fstream>
using namespace std;

int main()
{
                                              
	int N;                                                    //how many random numbers you want to estimate ¦Ð              
	double counter = 0;                                       //calcultate the number of dots inside the qudarny circle
	double t, pi;                                             //t:pi = 4 * t
	double m, n, x, y;                                        //m,n£ºrandom number for x,y between 0-9999
	                                                          //x,y: random number between 0-0.9999
	srand((unsigned)time(0));                                         //set the seeds
	cout << "Please input how many random number you want:" << endl;       
	cin >> N;

	ofstream file;
	file.open("myfile.txt");
	file << "x "<< "," << "y" << "\n";                        //write "x,y" in txt file

	for (int i = 0; i < N; i++)
	{

		m = (int)(10000.0*rand()/(RAND_MAX));                                   //random number for x between 0-9999
		n = (int)(10000.0*rand()/(RAND_MAX));                                   //random number for y between 0-9999
		       
		x = m / 10000;                                        //random number between 0-0.9999
		y = n / 10000;                                        //random number between 0-0.9999
		 
		if ((x*x + y*y) <= 1)                                 //judge whether the dots in the qudarny circle or not
		{
			counter++;
		}
		
		file << x << "," << y << "\n";                        //write x y in txt file    
		cout << x << " " << y << endl;                        //display x y on the screen to make sure 
	}

	t = counter / N;                                          
	pi = 4 * t;                                                 
	 
	cout << pi << endl;                                       //display the estimated value of ¦Ð on the screen
	system("pause"); 
	return 0;
}