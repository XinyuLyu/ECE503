#include<iostream>
using namespace std;
#include"Sphere.h"
Sphere::Sphere(int xValue, int yValue,int zValue, double radiusValue)
	:ThreeDimensionalShape(xValue, yValue,zValue)
{
	setRadius(radiusValue);
}
void Sphere::setRadius(double radiusValue)
{
	radius = (radiusValue < 0.0 ? 0.0 : radiusValue);
}
double Sphere::getRadius()const
{
	return radius;
}
double Sphere::getArea()const
{
	return 4*3.141592654*getRadius()*getRadius();
}
double Sphere::getVolume()const
{
	return 4.188790205*getRadius()*getRadius()*getRadius();
}
string Sphere::getName()const
{
	return "Sphere";
}
void Sphere::print()const
{
	cout << "The sphere with length " << getRadius();
	cout << " at location";
	ThreeDimensionalShape::print();
	cout << "has:" << endl;
}