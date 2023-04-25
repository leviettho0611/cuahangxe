#include "StoreVehicles.h"

StoreVehicles::StoreVehicles()
{
}

void StoreVehicles::readFile()
{
	ifstream fi("listVehicles.txt");
	Vehicles* tmp;
	string vehicel, id, name, color, dayall, daysale, price, cc;
	while (fi.good()) {

		getline(fi, vehicel, ',');
		getline(fi, id, ',');
		getline(fi, name, ',');
		getline(fi, color, ',');
		getline(fi, dayall, ',');
		getline(fi, daysale, ',');
		getline(fi, price, ',');
		if (vehicel == "" || name == "" || color == "" || daysale == "" || price == "") { break; }
		long tmpPrice = stol(price);
		if (vehicel.compare("Bike") == 0) {
			getline(fi, cc, '\n');
			int tmpcc = stoi(cc);
			tmp = new Bike(id, name, color, dayall, daysale, tmpPrice, tmpcc);
			list.push_back(tmp);
		}
		else {
			string ImportTax;
			getline(fi, cc, ',');
			int tmpcc = stoi(cc);
			getline(fi, ImportTax, '\n');
			long tmpImportTax = stol(ImportTax);
			tmp = new car(id, name, color, dayall, daysale, tmpPrice, tmpcc, tmpImportTax);
			list.push_back(tmp);
		}
	}
	fi.close();
}

void StoreVehicles::updateFile()
{
	ofstream fo("listVehicles.txt");
	for (int i = 0; i < list.size(); i++) {
		fo << list[i]->getvehicles() << "," << list[i]->getID() << "," << list[i]->getName() << "," << list[i]->getColor() << "," << list[i]->getDateAdded() << "," << list[i]->getSaledate() << "," << list[i]->getprice() << "," << list[i]->getengineOutput();
		if (list[i]->getvehicles().compare("Bike") == 0) {
			fo << endl;
		}
		else {
			fo << "," << list[i]->getFurnitureMoney() << endl;
		}
	}
	fo.close();
}

void StoreVehicles::display()
{
	cout << "------------------------------------------------------Bang Kho hang----------------------------------------------------" << endl;
	cout << setw(6) << left << "Vehicles";
	cout << "|" << setw(10) << left << "ID";
	cout << "\t|" << setw(10) << left << "Name" << "\t|";
	cout << setw(10) << left << "color" << "\t|";
	cout << setw(10) << left << "DateAdded" << "\t|";
	cout << setw(10) << left << "saleDate" << "\t|";
	cout << setw(10) << left << "engineOutput" << "\t|";
	cout << setw(11) << left << "Price+Tax" << "\t|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < list.size(); i++) {
		list.at(i)->display();
	}
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void StoreVehicles::input()
{
	Vehicles* tmp;
	int index;
	while (true) {
		cout << "----------- nhap 1 hoac 2 de them vao kho hang ----------------" << endl;
		cout << "1 : Them xe may : " << endl;
		cout << "2 : Them oto : " << endl;
		cout << "0 : thoat : " << endl;
		cout << "xin moi nhap lua chon : ";
		cin >> index;
		cin.ignore();
		if (index == 1) {
			tmp = new Bike();
			tmp->input();
			list.push_back(tmp);
		}
		else if (index == 2) {
			tmp = new car();
			tmp->input();
			list.push_back(tmp);
		}
		else if (index == 0) {
			return;
		}
		else {
			cout << "Ban chua nhap lua chon dung moi nhap lai" << endl;
			system("pause");
		}
		system("cls");
	}
}

void StoreVehicles::find(string id)
{
	cout << "------------------------------------------------------Bang Kho hang----------------------------------------------------" << endl;
	cout << setw(6) << left << "Vehicles";
	cout << "|" << setw(10) << left << "ID";
	cout << "\t|" << setw(10) << left << "Name" << "\t|";
	cout << setw(10) << left << "color" << "\t|";
	cout << setw(10) << left << "DateAdded" << "\t|";
	cout << setw(10) << left << "saleDate" << "\t|";
	cout << setw(10) << left << "engineOutput" << "\t|";
	cout << setw(11) << left << "Price+Tax" << "\t|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < list.size(); i++) {
		if (list.at(i)->getName().find(id)!= string::npos) {
			list.at(i)->display();
		}
	}
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

int StoreVehicles::findById(string id)
{

	int pos = -1;
	for (int i = 0; i < list.size(); i++) {
		if (id.compare(list[i]->getID()) == 0) {
			pos = i;
			return pos;
		}
	}
	return pos;
}

void StoreVehicles::eraseBylist(string id)
{ 
	int pos = findById(id);
	if (pos == -1) { return; }
	list.erase(list.begin()+pos);
}

void StoreVehicles::editBylist(string id)
{
	int pos = findById(id);
	if (pos == -1) { return; }
	list.erase(list.begin() + pos);
	Vehicles* tmp;
	int index;
	cout << "1 : Them xe may : " << endl;
	cout << "2 : Them oto : " << endl;
	cout << "xin moi nhap lua chon : ";
	cin >> index;
	cin.ignore();
	if (index == 1) {
		tmp = new Bike();
		tmp->input();
		list.insert(list.begin() + pos, tmp);
	}
	else if (index == 2) {
		tmp = new car();
		tmp->input();
		list.insert(list.begin() + pos, tmp);
	}
}

void StoreVehicles::AddBill(string id)
{

	int pos = findById(id);
	if (pos == -1) {
		return;
	}
	bill.push_back(pos);
}

void StoreVehicles::displaybyBIll()
{
	long sum = 0;
	cout << "------------------------------------------------------Bang Kho hang----------------------------------------------------" << endl;
	cout << setw(6) << left << "Vehicles";
	cout << "|" << setw(10) << left << "ID";
	cout << "\t|" << setw(10) << left << "Name" << "\t|";
	cout << setw(10) << left << "color" << "\t|";
	cout << setw(10) << left << "DateAdded" << "\t|";
	cout << setw(10) << left << "saleDate" << "\t|";
	cout << setw(10) << left << "engineOutput" << "\t|";
	cout << setw(11) << left << "Price+Tax" << "\t|" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < bill.size(); i++) {
		list.at(bill.at(i))->display();
		sum += list.at(bill.at(i))->money();
	}
	cout << "Tong tien la : " << sum<<endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

void StoreVehicles::eraseBybill(string id)
{
	int pos = stoi(id);
	int vt = -1;
	for (int i = 0; i < bill.size(); i++) {
		int tmp = stoi(list.at(bill.at(i))->getID());
		if (pos == bill.at(i)) {
			vt = i;
		}
	}
	system("pause");
	if (vt == -1) {
		return;
	}
	bill.erase(bill.begin() + vt);
}

void StoreVehicles::menuBIll()
{
	int index;
	while (true) {
		system("cls");
		cout << "----------- nhap lua chon de them vao Bill ----------------" << endl;
		cout << "1 : Nhap Bill  " << endl;
		cout << "2 : xem Bill  " << endl;
		cout << "3 : xoa Bill   " << endl;
		cout << "4 : Thoat  : " << endl;
		cout << "xin moi nhap lua chon  "<<endl;
		cin >> index;
		//cin.ignore();
		if (index == 1) {
			cin.ignore();
			string id;
			cout << "Moi Nhap id : "; getline(cin, id);
			AddBill(id);
		}
		else if (index == 2) {
			system("cls");
			displaybyBIll();
			system("pause");
		}
		else if (index == 3) {
			string id;
			cin.ignore();
			cout << "Moi Nhap vi tri muon xoa ";
			getline(cin, id);
			eraseBybill(id);
		}
		else {
			return;
		}
	}
}

void StoreVehicles::menu()
{
	int index;
	while (true) {
		system("cls");
		cout << "----------- nhap lua chon de them vao Bill ----------------" << endl;
		cout << "1 : Nhap Kho : " << endl;
		cout << "2 : xem Kho : " << endl;
		cout << "3 : xoa kho  : " << endl;
		cout << "4 : chinh sua thong Tin : " << endl;
		cout << "5 : Tiem kiem items trong kho : " << endl;
		cout << "6 : Tinh BIll : " << endl;
		cout << "7 : cap nhap : " << endl;
		cout << "8 : Thoat : " << endl;
		cout << "xin moi nhap lua chon : ";
		cin >> index;
		system("cls");
		cin.ignore();
		if (index == 1) {
			input();
		}
		else if (index == 2) {
			display();
			system("pause");
		}
		else if (index == 3) {
			string id;
			cout << "Moi Nhap ID muon xoa ";
			getline(cin, id);
			eraseBylist(id);
		}
		else if (index == 4) {
			string id;
			cout << "Moi Nhap ID muon sua ";
			getline(cin, id);
			editBylist(id);
		}
		else if (index == 5) {
			string name;
			cin.ignore();
			cout << "Moi Nhap ID muon xoa ";
			getline(cin, name);
			find(name);
			system("pause");
		}
		else if (index == 6) {
			menuBIll();
		}

		else if (index == 7) {
			system("cls");
			updateFile();
		}
		else {
			return;
		}
	}
}

StoreVehicles::~StoreVehicles()
{
	list.clear();
	bill.clear();
}
