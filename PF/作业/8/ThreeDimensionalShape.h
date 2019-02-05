#pragma once
#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H
#include"Shape.h"
class ThreeDimensionalShape : public Shape
{
public:
	ThreeDimensionalShape(int = 0, int = 0,int=0);
	void setX(int);
	int getX() const;
	void setY(int);
	int getY()const;
	void setZ(int);
	int getZ()const;
	virtual double getArea() const = 0;
	virtual double getVolume() const = 0;
	virtual string getName() const = 0;
	virtual void print() const;

private:
	int x;
	int y;
	int z;
};






#endif 
