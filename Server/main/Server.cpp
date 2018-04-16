// Server.cpp : Defines the entry point for the application.
//

#include "Server.h"
#include "User.h"
#include "ManageUser.h"
#include <Location.h>
#include  <iostream>




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






	return 0;
}
