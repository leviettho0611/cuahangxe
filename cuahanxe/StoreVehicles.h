#pragma once
#include"Bike.h"
#include"car.h"
#include<vector>
#include<fstream>
class StoreVehicles
{
private:
	vector<Vehicles*> list;
	vector<int> bill;
public:
	StoreVehicles();
	void readFile();
	void updateFile();
	void display();
	void input();
	void find(string id);
	///----sua vs xoa---//
	int findById(string id);
	void eraseBylist(string id);
	void editBylist(string id);
	//--Bill--//
	void AddBill(string id);
	void displaybyBIll();
	void eraseBybill(string id);
	void menuBIll();
	//-----Menu------//
	void menu();
	~StoreVehicles();

};

