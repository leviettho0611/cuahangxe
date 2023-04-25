#include"Bike.h"
#include"car.h"
#include"StoreVehicles.h"
int main() {
	StoreVehicles m;
	m.readFile();
	/*m.display();
	cout << "Nhap id muon Tiem kiem"; string id;
	getline(cin, id);
	m.find(id);*/
	m.menu();

	return 0;
}