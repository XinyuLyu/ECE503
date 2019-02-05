#include <iostream>
using namespace std;
#include"Polynomial_XinyuLyu.h"
int main()
{
	Polynomial Poly1;
	Polynomial Poly2;
	Polynomial Poly3;
	Polynomial Poly4;
	Polynomial Poly5;
	Polynomial Poly6;

	Poly1.Polynomial_term_set();
	Poly1.Coefficient_and_Exponent_set();

	Poly2.Polynomial_term_set();
	Poly2.Coefficient_and_Exponent_set();

	cout << "First Polynomial is : ";
	cout << Poly1;
	cout << endl;

	cout << "Second Polynomial is : ";
	cout << Poly2;
	cout << endl;

	Poly3 = Poly1 + Poly2;
	cout << "Adding polynomial yields : ";
	cout << Poly3;
	cout << endl;

	Poly4 = Poly1;
	Poly5 = Poly1;

    Poly1 += Poly2;
	cout << "+= the polynomial yields : ";
	cout << Poly1;
	cout << endl;

	Poly3 = Poly4 -Poly2;
	cout << "Substracting polynomial yields : ";
	cout << Poly3;
	cout << endl;

	Poly4 -= Poly2;
	cout << "-= the polynomial yields : ";
	cout << Poly4;
	cout << endl;

	Poly3 = Poly5 * Poly2;
	cout << "* the polynomial yields : ";
	cout << Poly3;
	cout << endl;

	Poly5 *= Poly2;
	cout << "*= the polynomial yields : ";
	cout << Poly5;
	cout << endl;

	system("pause");

	return 0;
}