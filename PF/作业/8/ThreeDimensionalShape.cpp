#include<iostream>
using namespace std;
#include"ThreeDimensionalShape.h"

ThreeDimensionalShape::ThreeDimensionalShape(int xValue, int yValue, int zValue)
	:x(xValue), y(yValue), z(zValue)
{
}

void ThreeDimensionalShape::setX(int xValue)
{
	x = xValue;
}
int ThreeDimensionalShape::getX() const
{
	return x;
}
void ThreeDimensionalShape::setY(int yValue)
{
	y = yValue;
}
int ThreeDimensionalShape::getY()const
{
	return y;
}
void ThreeDimensionalShape::setZ(int zValue)
{
	z = zValue;
}
int ThreeDimensionalShape::getZ()const
{
	return z;
}
 void ThreeDimensionalShape::print() const
{
	 cout << " (" << getX() << "," << getY() <<","<<getZ()<< ") ";
 }
