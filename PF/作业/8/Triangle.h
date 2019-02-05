#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"TwoDimensionalShape.h"
class Triangle : public  TwoDimensionalShape
{
public:
	Triangle(int = 0, int = 0, double = 0.0);
	void setLength(double);
	double getLength()const;
	virtual double getArea() const;
	virtual string getName() const;
	virtual void print() const;
private:
	double length;
};
#endif