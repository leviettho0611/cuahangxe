#pragma once
#include"Vehicles.h"
class car:public Vehicles
{
private:
	int engineOutput;
	long FurnitureMoney;
	string vehicles;
public:
	car();
	car(string Id, string Name, string Color, string DateAdded, string saleDate, long price, int engineOutput, long FurnitureMoney);
	virtual void input();
	virtual void display();
	virtual long  money();
	int getengineOutput();
	long getFurnitureMoney();
	string getvehicles();
};

