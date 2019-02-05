#pragma once
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H
#include"Shape.h"
class TwoDimensionalShape : public Shape
{
public:
	TwoDimensionalShape(int = 0, int = 0);
	void setX(int);
	int getX() const;
	void setY(int);
	int getY()const;
	virtual double getArea() const = 0;
	virtual string getName() const=0;
	virtual void print() const;

private:
	int x;
	int y;
};






#endif 
