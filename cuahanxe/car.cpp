#include "car.h"
car::car() :Vehicles()
{
	this->engineOutput = 0;
	this->FurnitureMoney = 0;
	this->vehicles = "Car";
}

car::car(string Id, string Name, string Color, string DateAdded, string saleDate, long price, int engineOutput, long FurnitureMoney) :Vehicles(Id, Name, Color, DateAdded, saleDate, price)
{
	this->engineOutput = engineOutput;
	this->FurnitureMoney = FurnitureMoney;
	this->vehicles = "Car";
}

void car::input()
{
	Vehicles::input();
	cout << "EngineOutput : "; cin >> engineOutput;
	cout << "FurnitureMoney : "; cin >> FurnitureMoney;
}

void car::display()
{
	cout << setw(6) << left << "Car " << "\t";
	Vehicles::display();
	cout << setw(10) << left << this->engineOutput << "\t|";
	cout << setw(10) << left << money() << "\t|" << endl;
}

long car::money()
{
	return (this->price * 2) + FurnitureMoney;
}

int car::getengineOutput()
{
	return engineOutput;
}

long car::getFurnitureMoney()
{
	return FurnitureMoney;
}

string car::getvehicles()
{
	return vehicles;
}
