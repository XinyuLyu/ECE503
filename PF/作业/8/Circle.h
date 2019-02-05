#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include"TwoDimensionalShape.h"
class Circle : public  TwoDimensionalShape 
{
public:
	Circle(int = 0, int = 0, double = 0.0);
	void setRadius(double);
	double getRadius()const;
	virtual double getArea() const;
	virtual string getName() const;
	virtual void print() const;
private:
	double radius;
};
#endif