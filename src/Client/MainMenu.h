#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include "User.h"
#include "Connection.h"

using namespace std;

class MainMenu
{
public:

	void createMainMenu();

	MainMenu() {};
	~MainMenu() {};

	

private:
	

protected:
	//Main Menu
	void customerManagementMenu();
	void carManagementMenu();
	void showAllCarsMenu();
	void showAvailableCarMenu();
	void rentCatMenu();
	void returnCarMenu();

	//Customer Management Menu
	void addNewCustomerMenu();
	void getCustomerInfo();
};

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
void MainMenu::carManagementMenu() {
	cout << "==> Car Management <==" << endl;
	cout << "1. Show All cars" << endl;
	cout << "2. Show available cars" << endl;
	cout << "3. Rent Car" << endl;
	cout << "4. Return Car" << endl;
	cout << "5. Add new Car" << endl;
	cout << "6. Find a Car by id" << endl;
	cout << "7. Update a Car" << endl;
	cout << "9. Main Menu" << endl;
	cout << "0. Exit" << endl;

	char option = '0';
	cin >> option;

	switch (option) {
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '9':
		break;
	case '0':
		break;

	default:
		break;

	}
}

void MainMenu::showAllCarsMenu() {

}

void MainMenu::showAvailableCarMenu() {

}

void MainMenu::rentCatMenu() {

}

void MainMenu::returnCarMenu() {

}

//Customer Management Menu
void MainMenu::getCustomerInfo() {

}

void MainMenu::addNewCustomerMenu() {
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

	User user{ id,name,age, email,address, phone };

}

#endif