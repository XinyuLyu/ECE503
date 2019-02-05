#pragma once
#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include"ThreeDimensionalShape.h"
class Tetrahedron : public  ThreeDimensionalShape
{
public:
	Tetrahedron(int = 0, int = 0, int = 0, double = 0.0);
	void setLength(double);
	double getLength()const;
	virtual double getArea() const;
	virtual double getVolume()const;
	virtual string getName() const;
	virtual void print() const;
private:
	double Length;
};
#endif