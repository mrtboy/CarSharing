// Server.cpp : Defines the entry point for the application.
//

#include "Server.h"
#include "User.h"
#include "ManageUser.h"
#include  <iostream>
#include "Car.h"
#include <list>

using namespace std;

int main()
{
	
	User user("string","test",5,"test","test","test");

	ManageUser *muser = new ManageUser();

	std::cout << muser->insert(user);

	std::cout << muser->userExist("string");

	std::cout << user.getId();

	vector<User> test = muser->getAllUsers();



	for (int i = 0; i < ManageUser::users.size(); i++) {

		cout << ManageUser::users[i].getId() << " ";
	}
	Car_Location carl("test");

	list<string> test2;

	test2.push_back("uno");

	Car car("test", 5, test2, carl, 5, "test", 5, "test", 5, 5, "test", "test", "test", 1);

	std::cout << car.getID();
	
	return 0;
}
