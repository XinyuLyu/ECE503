#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include<string>
using namespace std;
class  Shape
{
public:
	Shape();
	virtual double getArea() const=0; 
	virtual double getVolume() const;
	virtual string getName() const = 0;
	virtual void print() const = 0;
};
#endif 
