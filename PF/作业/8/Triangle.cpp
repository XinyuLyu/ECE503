#include<iostream>
using namespace std;
#include"Triangle.h"
Triangle::Triangle(int xValue, int yValue, double lengthValue)
	:TwoDimensionalShape(xValue, yValue)
{
	setLength(lengthValue);
}
void Triangle::setLength(double radiusValue)
{
	length = (radiusValue < 0.0 ? 0.0 : radiusValue);
}
double Triangle::getLength()const
{
	return length;
}
double Triangle::getArea()const
{
	return 0.4330127019*getLength()*getLength();
}
string Triangle::getName()const
{
	return "Triangle";
}
void Triangle::print()const
{
	cout << "The triangle with length " << getLength();
	cout << " at location";
	TwoDimensionalShape::print();
	cout << "has:" << endl;
}