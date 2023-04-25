#pragma once
#include<iostream>
#include"Vehicles.h"
using namespace std;
class Bike :public Vehicles
{
private:
	int engineOutput;
	string vehicles;
public:
	Bike();
	Bike(string Id, string Name, string Color, string DateAdded, string saleDate, long price, int engineOutput);
	virtual void input();
	virtual void display();
	virtual long  money();
	int getengineOutput();
	string getvehicles();
	long getFurnitureMoney();
};

