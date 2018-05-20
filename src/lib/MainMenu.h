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

enum FUNCTIONTYPE { AddNewUser, AddNewCar, ShowAllUsers, ShowAddUsers };

class EXPORT_SYMBOL MainMenu {

public:
	void createMainMenu();
	void customerManagementMenu();
	void carManagementMenu();
	void showAllCarsMenu();
	void showAvailableCarMenu();
	void rentCatMenu();
	void returnCarMenu();

	//Customer Management Menu
	User addNewCustomerMenu();
	void getCustomerInfo();

	MainMenu() {};
	~MainMenu() {};

private:
	ManageUser manageUser;
	
	

protected:
	
};

#endif