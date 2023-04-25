#include "Vehicles.h"
Vehicles::Vehicles()
{
	this->Name = "";
	this->Id = "";
	this->Color = "";
	this->DateAdded = "";
	this->saleDate = "";
	this->price = 0;
}
Vehicles::Vehicles(string Id, string Name, string Color, string DateAdded, string saleDate, long price)
{
	this->Id = Id;
	this->Name = Name;
	this->Color = Color;
	this->DateAdded = DateAdded;
	this->saleDate = saleDate;
	this->price = price;
}
void Vehicles::display()
{
	cout << "|" << setw(10) << left << this->Id;
	cout << "\t|" << setw(10) << left << this->Name << "\t|";
	cout << setw(10) << left << this->Color << "\t|";
	cout << setw(10) << left << this->DateAdded << "\t|";
	cout << setw(10) << left << this->saleDate << "\t|";
}

void Vehicles::input()
{
	cout << "Name : "; getline(cin, Name);
	cout << "ID : "; getline(cin, Id);
	cout << "Color : "; getline(cin, Color);
	cout << "DateAdded : "; getline(cin, DateAdded);
	cout << "Price : ";  cin >> price;
	this->saleDate = "0";
}

string Vehicles::getName()
{
	return this->Name;
}

string Vehicles::getID()
{
	return this->Id;
}

string Vehicles::getColor()
{
	return Color;
}

string Vehicles::getDateAdded()
{
	return DateAdded;
}

string Vehicles::getSaledate()
{
	return saleDate;
}

long Vehicles::getprice()
{
	return price;
}

void Vehicles::setSaledate(string saleDate)
{
	this->saleDate = saleDate;
}