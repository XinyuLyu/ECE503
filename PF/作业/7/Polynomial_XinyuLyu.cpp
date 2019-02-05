#include <iostream>
#include <iomanip>
#include <iomanip>
using namespace std;
#include"Polynomial_XinyuLyu.h"

Polynomial::Polynomial()                             //initialization
{
	for (int i = 0; i < 7; i++) a[i] = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			b[i][j] = 0;
		}
	}
	for (int i = 0; i < 13; i++) c[i] = 0;
}                                   
Polynomial::~Polynomial()                             //deconstruction
{
}                
void Polynomial::Polynomial_term_set()                //set value for terms of every polynomial
{
	int t;
	cout << "Enter the number of polynomial terms : ";
	do {
		cin >> t;
		if (t <= 0)
		{
			cout << "The number of polynomial terms should be a positive number,enter again : ";
		}
	} while (t <= 0);
	this->Polynomial_term = (t >= 0 && t <= 7) ? t : 0;
}        
void Polynomial::Coefficient_set()                            //set value for coefficient 
{
	int t;
	cin >> t;
	this->Coefficient = t;
}
void Polynomial::Exponent_set()                               //set value for exponent
{
	int t;
	do
	{
		cin >> t;
		if (t < 0)
		{
			cout << "Valid, input the exponent again : ";
		}
	} while (t<0);
	this->Exponent = t;
}
void Polynomial::Coefficient_and_Exponent_set()                //set both coefficient and exponent 
{
	for (int i = 0; i < Polynomial_term; i++)
	{
		cout << "Enter coefficient and exponent : ";
			this->Coefficient_set();
			this->Exponent_set();
	
		this->a[Exponent] = this->Coefficient;
	}
	this->Polynomial_term = 7;
}
int Polynomial::Polynomial_term_get()                            //get term foe polynomial
{
	return Polynomial_term;
}
int Polynomial::Coefficient_get()                                 //get  coefficient for polynomial
{
	return Coefficient;
}
int Polynomial::Exponent_get()                                    //get exponent for polynomial
{
	return Exponent;
}
Polynomial Polynomial::operator+(const Polynomial&B)                 //overloaded operator+
{ 
	Polynomial C;
	C.Polynomial_term = 7;
	for (int i = 0; i < 7; i++)
	{
		C.a[i] = this->a[i] + B.a[i];
	}
	return C;
}
Polynomial Polynomial::operator-(const Polynomial&B)                    //overloaded operator-
{
	Polynomial C;
	C.Polynomial_term = 7;
	for (int i = 0; i < 7; i++)
	{
		C.a[i] = this->a[i] -B.a[i];
	}
	return C;
}
Polynomial Polynomial::operator=(const Polynomial&B)                         //overloaded operator assign
{
	this->Polynomial_term=B.Polynomial_term;
	this->Exponent=B.Exponent;
	this->Coefficient=B.Coefficient;
	for (int i = 0; i < 7; i++)
	{
		this->a[i] = B.a[i];
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			this->b[i][j] = B.b[i][j];
		}
	}
	for (int i = 0; i < 13; i++)
	{
		this->c[i] = B.c[i];
	}
	return *this;
}
Polynomial Polynomial::operator*(const Polynomial&B)                        //overloaded operator*
{
	Polynomial C;
	C.Polynomial_term = 13;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			C.b[i][j]= this->a[i] * B.a[j];
		}
	}
	for (int sum = 0; sum < 13; sum++)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if ((i + j) == sum)
				{
					C.c[sum] += C.b[i][j];
				}
			}
		}
	}
	return C;
}
Polynomial Polynomial::operator+=(const Polynomial&B)                           //overloaded operator+=
{
	this->Polynomial_term = (this->Polynomial_term > B.Polynomial_term) ? this->Polynomial_term : B.Polynomial_term;
	*this=*this + B;
	return *this;
}
 
Polynomial Polynomial::operator-=(const Polynomial&B)                                //overloaded operator-=
{
	this->Polynomial_term = (this->Polynomial_term > B.Polynomial_term) ? this->Polynomial_term : B.Polynomial_term;
	*this = *this - B;
	return *this;
}

Polynomial Polynomial::operator*=(const Polynomial&B)                                    //overloaded operator*=
{
	*this = *this * B;
	return *this;
} 
 ostream &operator<<(ostream&output, const Polynomial &Poly)                               //overloaded operator<<
{
	 int t=0; int counter = 0;
		 if (Poly.Polynomial_term == 13)
	 {
		 for (int i = 0; i < Poly.Polynomial_term; i++)
		 {
			 if (Poly.c[i] != 0)
			 {
				 if (i == 0)
				 {
					 output << Poly.c[i] ;
				 }
				 else
				 {
					 output << Poly.c[i] << "x^" << i;
				 }
				 t = i;
				 break;
			 }
			 else
			 {
				 counter++;
			 }
			 if (counter == 13)
			 {
				 cout << "0";
			}
		 }
		 for (int i = t + 1; i<Poly.Polynomial_term ; i++)
		 {
			 if (Poly.c[i] != 0)
			 {
				 (Poly.c[i] > 0) ? output << "+" << Poly.c[i] << "x^" << i : output << Poly.c[i] << "x^" << i;
			 }
		 }
	 }
	 else
	 {
    for (int i = 0; i < Poly.Polynomial_term; i++)
	 {
		 if (Poly.a[i] != 0)
		 {
			 if (i == 0)
			 {
				 output << Poly.a[i] ;
			 }
			 else
			 {
				 output << Poly.a[i] << "x^" << i;
			 }
			 t = i;
			 break;
		 }
		 else
		 {
			 counter++;
		 }
		 if (counter == 7)
		 {
			 cout << "0";
		 }
	 }
	for (int i = t + 1; i<Poly.Polynomial_term ; i++)
	 {
		 if (Poly.a[i] != 0)
		 { 
			 (Poly.a[i] > 0) ? output << "+" << Poly.a[i] << "x^" << i : output <<Poly.a[i] << "x^" << i;
		 }
	 }
	 }
	 return output;
}
