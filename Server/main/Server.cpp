
#include "Server.h"
#include "User.h"
#include "ManageUser.h"
#include  <iostream>
#include "Car.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>


using namespace std;

int main()
{

	User user("string", "test", 5, "test", "test", "test");

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

	std::cout << "Die ID" << car.getID();

	list<string> test3 = car.getCarInfo();
	std::list<std::string>::iterator iter;
	std::string findString = "uno";

	Car_Location carl2 = car.getLocation();

	std::cout << carl2.getLocation();

	// Finds the String "uno" , which is created by Constructor
	if ((iter = std::find(test3.begin(), test3.end(), findString)) != test3.end())
	{
		for (int idx = 0; idx < 1; ++idx)
		{
			std::cout << *iter << " ";
			++iter;
		}
		std::cout << std::endl;
	}




	system("pause");
	return 0;
}