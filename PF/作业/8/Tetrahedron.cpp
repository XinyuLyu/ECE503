#include<iostream>
using namespace std;
#include"Tetrahedron.h"
Tetrahedron::Tetrahedron(int xValue, int yValue, int zValue, double lengthValue)
	:ThreeDimensionalShape(xValue, yValue, zValue)
{
	setLength(lengthValue);
}
void Tetrahedron::setLength(double lengthValue)
{
	Length = (lengthValue < 0.0 ? 0.0 : lengthValue);
}
double Tetrahedron::getLength()const
{
	return Length;
}
double Tetrahedron::getArea()const
{
	return 1.732050808*getLength()*getLength();
}
double Tetrahedron::getVolume()const
{
	return 0.1178511302*getLength()*getLength()*getLength();
}
string Tetrahedron::getName()const
{
	return "Tetrahedron";
}
void Tetrahedron::print()const
{
	cout << "The tetrahedron with length " << getLength();
	cout << " at location";
	ThreeDimensionalShape::print();
	cout << "has:" << endl;
}