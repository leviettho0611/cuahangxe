#pragma once
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
class Vehicles
{
protected:
	string Name;
	string Id;
	string Color;
	string DateAdded;
	string saleDate;
	long price;
public:
	Vehicles();
	Vehicles(string Id, string Name, string Color, string DateAdded, string saleDate, long price);
	virtual void display();
	virtual void input();
	virtual long  money() = 0;
	//----------------get-----------------------//
	string getName();
	string getID();
	string getColor();
	string getDateAdded();
	string getSaledate();
	long getprice();
	virtual long getFurnitureMoney() = 0;
	virtual int getengineOutput() = 0;
	virtual string getvehicles() = 0;
	//set
	void setSaledate(string saleDate);
};

