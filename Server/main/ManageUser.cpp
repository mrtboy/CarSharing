#include "ManageUser.h"
#include <algorithm>


vector<User> ManageUser::users;

vector<User> ManageUser::getAllUsers() {
	return users;
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
		/*User user(model.getId(), model.getName(), model.getAddress(), model.getAge(), model.getPhone(), model.getEmail());*/
		
		users.push_back(model);
		return true;
	}
	catch (exception ex) {
		return false;
	}
}