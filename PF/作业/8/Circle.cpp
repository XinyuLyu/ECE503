#include<iostream>
using namespace std;
#include"Circle.h"
Circle::Circle(int xValue, int yValue,double radiusValue)
	:TwoDimensionalShape(xValue, yValue)
{
	setRadius(radiusValue);
}
void Circle::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
}
double Circle::getRadius()const
{
	return radius;
}
double Circle::getArea()const
{
	return 3.141592654*getRadius()*getRadius();
}
string Circle::getName()const
{
	return "Circle";
}
void Circle::print()const
{
	cout << "The circle with radius " << getRadius(); 
	cout << " at location";
    TwoDimensionalShape::print();
    cout<< "has:" << endl;
}