#include<iostream>
using namespace std;
#include"TwoDimensionalShape.h"

TwoDimensionalShape::TwoDimensionalShape(int xValue, int yValue)
	:x(xValue), y(yValue)
{
}

void TwoDimensionalShape::setX(int xValue)
{
	x = xValue;
}
int TwoDimensionalShape::getX() const
{
	return x;
}
void TwoDimensionalShape::setY(int yValue)
{
	y = yValue;
}
int TwoDimensionalShape::getY()const
{
	return y;
}
void  TwoDimensionalShape::print() const
{
	cout << " (" << getX() << "," << getY() << ") ";
}
