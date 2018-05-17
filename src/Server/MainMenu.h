#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include "User.h"
#include "Connection.h"
#include "ManageUser.h"
#include <vector>

using namespace std;

class MainMenu
{
public:

	vector<string> createMainMenu();
	vector<string> Responce(char option);

	MainMenu() {};
	~MainMenu() {};

private:
	ManageUser manageUser;


protected:
	//Main Menu
	vector<string> customerManagementMenu();
	//vector<string> carManagementMenu();
	//vector<string> showAllCarsMenu();
	//vector<string> showAvailableCarMenu();
	//vector<string> rentCatMenu();
	//vector<string> returnCarMenu();


	//Customer Management Menu
	vector<string> addNewCustomerMenu();
	//vector<string> getCustomerInfo();
};

//Main Menu
vector<string> MainMenu::createMainMenu() {
	string welcome = "==> Welcome to Car sharing <==";
	string first = "1. Customer Management";
	string second = "2. Car Management";
	string exit = "0. Exit";
	vector<string> str{ welcome,first,second,exit };

	return str;

}

vector<string> MainMenu::customerManagementMenu() {
	string welcome = "==> Customer Management <==";
	string first = "1. Add new Customer";
	string second = "2. Get Customer Info";
	string mainMenu = "9. Main Menu";
	string exit = "0. Exit";
	vector<string> str{ welcome,first,second,mainMenu, exit};
	return str;
}

vector<string> MainMenu::Responce(char option) {
	option = '1';
	cout << "Responce Called" + option << endl;
	switch (option) {
	case '1':
		return MainMenu::addNewCustomerMenu();
		break;
	/*case '2':
		return MainMenu::getCustomerInfo();
		break;
	case '9':
		return MainMenu::createMainMenu();
		break;*/
	//case '0':
	//	return NULL;
	//	break;
	default:
		break;
	}
}

////Main Menu
//vector<string> MainMenu::carManagementMenu() {
//	cout << "==> Car Management <==" << endl;
//	cout << "1. Show All cars" << endl;
//	cout << "2. Show available cars" << endl;
//	cout << "3. Rent Car" << endl;
//	cout << "4. Return Car" << endl;
//	cout << "5. Add new Car" << endl;
//	cout << "6. Find a Car by id" << endl;
//	cout << "7. Update a Car" << endl;
//	cout << "9. Main Menu" << endl;
//	cout << "0. Exit" << endl;
//}
//
//vector<string> MainMenu::showAllCarsMenu() {
//
//}
//
//vector<string> MainMenu::showAvailableCarMenu() {
//
//}
//
//vector<string> MainMenu::rentCatMenu() {
//
//}
//
//vector<string> MainMenu::returnCarMenu() {
//
//}
//
////Customer Management Menu
//vector<string> MainMenu::getCustomerInfo() {
//
//}

vector<string> MainMenu::addNewCustomerMenu() {
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
	
	
	

	User u{ "1","Reza",33,"Kiel", "Email", "Address" };

	return MainMenu::customerManagementMenu();	
}

#endif