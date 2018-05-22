#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <string>
#include <boost\archive\binary_oarchive.hpp>
#include <boost\archive\binary_iarchive.hpp>
#include "libdef.h"
#include "User.h"
#include "Connection.h"
#include "ManageUser.h"
#include "Connection.h"


using namespace std;

class EXPORT_SYMBOL MainMenu {

public:
	void createMainMenu();
	void customerManagementMenu();
	FUNCTIONTYPE carManagementMenu();

	//Customer Management Menu
	User addNewCustomerMenu();
	void getCustomerInfo();

	//Car Management Menu
	FUNCTIONTYPE ShowAllCars();
	FUNCTIONTYPE ShowAvailableCars();
	FUNCTIONTYPE RentCar();
	FUNCTIONTYPE ReturnCar();
	FUNCTIONTYPE AddNewCar();
	FUNCTIONTYPE FindCarById();

	MainMenu() {};
	~MainMenu() {};

private:
	ManageUser manageUser;
	
	

protected:
	
};

#endif