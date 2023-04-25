#include "Bike.h"

Bike::Bike() :Vehicles()
{
	this->engineOutput = 0;
	this->vehicles = "Bike";
}

Bike::Bike(string Id, string Name, string Color, string DateAdded, string saleDate, long price, int engineOutput) :Vehicles(Id, Name, Color, DateAdded, saleDate, price)
{
	this->engineOutput = engineOutput;
	this->vehicles = "Bike";
}

void Bike::input()
{
	Vehicles::input();
	cout << "EngineOutput : "; cin >> engineOutput;
}

long Bike::money()
{
	long sum = (this->price * 5) / 100;

	return this->price + sum;
}

int Bike::getengineOutput()
{
	return engineOutput;
}

string Bike::getvehicles()
{
	return vehicles;
}

long Bike::getFurnitureMoney()
{
	return 0;
}

void Bike::display()
{
	cout << setw(6) << left << "Bike " << "\t";
	Vehicles::display();
	cout << setw(10) << left << this->engineOutput << "\t|";
	cout << setw(10) << left << money() << "\t|" << endl;

}