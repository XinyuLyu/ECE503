#include<iostream>
#include<iomanip>
#include<vector>
#include<new>
#include"XINYU_LYU_OvernightPackage.h"
#include"XINYU_LYU_Package.h"
#include"XINYU_LYU_TwoDayPackage.h"
using namespace std;
int main()
{
	Package *package1 = new Package("John Smith", "1 Davidson Road", "Piscataway", "NJ", 8854,                             //construction package
		"Tom Smith", "2 Davidson Road", "Piscataway", "NJ",8854,10,0.5);
	TwoDayPackage *package2 = new TwoDayPackage("Mary Smith", "3 Davidson Road",                                           //construction Twodaypackage
		"Piscataway", "NJ", 8854, "Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ",8854,5,0.5,2);
	OvernightPackage *package3 = new OvernightPackage("John Smith","1 Davidson Road", 
		"Piscataway", "NJ", 8854,"Mary Smith","3 Davidson Road","Piscataway", "NJ",8854,2,0.5,5);                           //consturction Overnight package
	Package *package4 = new Package("Xinyu Lyu", "UESTC", "Chengdu", "Sichuan", 1234,
		"Fengjia Yu", "Uestc", "Neijiang", "Sichuan",2345,10,0.5);
	TwoDayPackage *package5 = new TwoDayPackage("Xinyu Lyu", "UESTC", "Chengdu", "Sichuan", 1234,
		"Fengjia Yu", "Uestc", "Neijiang", "Sichuan",2345,5,0.5,2);
	OvernightPackage *package6 = new OvernightPackage("Xinyu Lyu", "UESTC", "Chengdu", "Sichuan", 1234,
		"Fengjia Yu", "Uestc", "Neijiang", "Sichuan",2345,2,0.5,5);

	vector<Package*>packageVector(6);            //creat pointer to each package                                                                            
	packageVector[0] = package1;
	packageVector[1] = package2;
	packageVector[2] = package3;
	packageVector[3] = package4;
	packageVector[4] = package5;
	packageVector[5] = package6;

	cout << "Package delivery services program"<<endl;
	cout << endl;

    cout << fixed << setprecision(2);

	for (int i = 0; i < 3; i++)                 // print price information for each unit
	{
		packageVector[i]->printPrice();
	}
	cout << endl;

	for (int i = 0; i < 6; i++)               //print information of address ,name, cost......  
	{
		cout << "Package" <<" "<<i+1<<":"<< endl;
		packageVector[i]->print();
	}

    double total=0;
	for (int i = 0; i < 6; i++)               // print total cost
	{	
		total += packageVector[i]->calculateCost();
		if (i == 5)
		{
		cout << "Total cost of all the packages: "<<"$"<<total << endl;
		}
	}

	system("pause");
	return 0;
}
