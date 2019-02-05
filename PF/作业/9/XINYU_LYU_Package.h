#pragma once
#ifndef XINYU_LYU_PACKAGE_H
#define XINYU_LYU_PACKAGE_H
class Package
{
public:
	Package(const char *,const char *,const char*,const char *,int,                             //consturction
		const char *, const char*, const char*, const char*,int,double,double);
	~Package();                                                                                   //destruction
    virtual double calculateCost()const;                                    // calculate price
	virtual void print()const;                                                //print the necessary information
	virtual void printPrice()const;                              //print unit price
	virtual void setPrice(double);                         //set unit price  
	void setWeight_Ounce(double);                                                                       //set weight
	double getWeight_Ounce()const;                                  //get weight
	void setPrice_Ounce(double);                                //set unit price 
	double getPrice_Ounce()const;                                     //get unit price 
	void setSender_Zip(int);                                        //set cip code sender
	int getSender_Zip()const;                                      //get cip code sender
	void setReceipent_Zip(int);                                   //set zip code receiver
	int getReceipent_Zip()const;                                              //get zip code receiver
    const char *getSender_Name()const;                        //get sender name
	const char *getReceipent_Name()const;                            //get receiver name
	const char *getSender_Address()const;                        //get sende address
	const char *getReceipent_Address()const;                             //get receiver address
	const char *getSender_City()const;                                  // get sender city
	const char *getReceipent_City()const;                                   //get receiver coty
	const char *getSender_State()const;                                   //get sender state
	const char *getReceipent_State()const;                                 //get receiver state
private:
	char *Sender_Name;
	char *Receipent_Name;
	char *Sender_Address;
	char *Receipent_Address;
	char *Sender_City;
	char *Receipent_City;
	char *Sender_State;
	char *Receipent_State;
	int Sender_Zip;
	int Receipent_Zip;
	double Weight_Ounce;
	double Price_Ounce;
};
#endif // 
