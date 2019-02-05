#pragma once
class print                          // a design pattern: adapter class to fufill different requests for print from differet client
{
public:
	virtual void print_Title()=0;
};

