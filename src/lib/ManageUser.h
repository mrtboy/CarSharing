#ifndef MANAGEUSER_H
#define MANAGEUSER_H

#include <string>
#include "User.h"
#include <vector>
#include "libdef.h"

using namespace std;

class EXPORT_SYMBOL ManageUser {
public:
	bool userExist(string userId);
	bool insert(User model);

	vector<User> getAllUsers();

	static vector<User> users;

	ManageUser() {};
	~ManageUser() {};

};

#endif // !MANAGEUSER_H