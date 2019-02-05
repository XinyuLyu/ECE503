#pragma once                          
class Account; 	                           
class Bridge  {	             //abstract part in bridge design pattern    
public:
	virtual void Implement(Account *a) {};
};

