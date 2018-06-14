#include "MainMenu.h"


using namespace std;
//Main Menu
void MainMenu::createMainMenu() {
	cout << "==> Welcome to Car sharing <==" << endl;
	cout << "1. Customer Management" << endl;
	cout << "2. Car Management" << endl;
	cout << "0. Exit" << endl;

	char option = '0';
	cin >> option;

	switch (option) {
	case '1':
		MainMenu::customerManagementMenu();
		break;
	case '2':
		MainMenu::carManagementMenu();
		break;
	case '0':
		return;
	default:
		break;
	}
}

void MainMenu::customerManagementMenu() {
	cout << "==> Customer Management <==" << endl;
	cout << "1. Add new Customer" << endl;
	cout << "2. Get Customer Info" << endl;
	cout << "9. Main Menu" << endl;
	cout << "0. Exit" << endl;

	char option = '0';
	cin >> option;

	switch (option) {
	case '1':
		MainMenu::addNewCustomerMenu();
		break;
	case '2':
		MainMenu::getCustomerInfo();
		break;
	case '9':
		MainMenu::createMainMenu();
		break;
	case '0':
		return;
	default:
		break;
	}
}

//Main Menu
FUNCTIONTYPE MainMenu::carManagementMenu() {
	cout << "==> Car Management <==" << endl;
	cout << "1. Show All cars" << endl;
	cout << "2. Show available cars" << endl;
	cout << "3. Rent Car" << endl;
	cout << "4. Return Car" << endl;
	cout << "5. Add new Car" << endl;
	cout << "6. Find a Car by id" << endl;
	cout << "7. User info" << endl;
	cout << "0. Exit" << endl;
//	cout << "8. Show reserved cars" << endl;

	int option = 0;
	cin >> option;

	switch (option) {
	case 1:
		return ShowAllCars();
		break;
	case 2:
		return ShowAvailableCars();
		break;
	case 3:
		return RentCar();
		break;
	case 4:
		return ReturnCar();
		break;
	case 5:
		return AddNewCar();
		break;
	case 6:
		return FindCarById();
		break;
	case 7:
		return getCustomerInfo();
		break;
	case 0:
		break;
/*	case 8:
		return ShowReservedCars();
		break;*/

	default:
		break;

	}
}



//Customer Management Menu
FUNCTIONTYPE MainMenu::getCustomerInfo() {
	cout << "==>User Info<==" << endl;
	return GETUSERINFO;
}
User MainMenu::addNewCustomerMenu() {
	string id = "";
	string name = "";
	int age = 0;
	string email = "";
	string address = "";
	string  phone = "";

	cout << "==> Add new Customer <==" << endl;
	cout << "Id: " << endl;
	cin >> id;
	cout << "Name: " << endl;
	cin >> name;
	cout << "Age: " << endl;
	cin >> (int)age;
	cout << "Email: " << endl;
	cin >> email;
	cout << "Address: " << endl;
	cin >> address;
	cout << "Phone: " << endl;
	cin >> phone;

	User user{ id,name,age, email,address , phone };
	//manageUser.insert(user
	return user;
}

FUNCTIONTYPE MainMenu::ShowAllCars() {
	cout << "==>Show All Cars<==" << endl;
	return SHOWALLCARS;
}

FUNCTIONTYPE MainMenu::ShowAvailableCars() {
	cout << "==>Show Available Cars<==" << endl;
	return SHOWAVAILABLECARS;
}
/*
FUNCTIONTYPE MainMenu::ShowReservedCars() {
	cout << "==>Show Reserved Cars<==" << endl;
	return SHOWRESERVEDCARS;
}*/



FUNCTIONTYPE MainMenu::RentCar() {
	cout << "==>Rent Car<==" << endl;
	return RENT;
}

FUNCTIONTYPE MainMenu::ReturnCar() {
	cout << "==>Return a car<==" << endl;
	return RETURN;
}

FUNCTIONTYPE MainMenu::AddNewCar() {
	cout << "==>Add new Car<==" << endl;
	return ADDNEWCAR;
}

FUNCTIONTYPE MainMenu::FindCarById(){
	cout << "==>Find car by Id<==" << endl;
	return FINDCARBYID;
}





