#include "ManageUser.h"
#include <algorithm>

vector<User> ManageUser::users;

vector<User> ManageUser::getAllUsers() {
	return this->users;
}
bool ManageUser::userExist(string userId) {
	for (auto &user : users)
	{
		if (user.getId() == userId)
		{
			return true;
		}
	}
	return false;
}
bool ManageUser::insert(User model)
{
	try {

		users.push_back(model);
		return true;
	}
	catch (exception ex) {
		return false;
	}
}