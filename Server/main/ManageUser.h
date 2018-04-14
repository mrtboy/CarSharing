#ifndef MANAGEUSER_H
#define MANAGEUSER_H
#include <string>
#include "User.h"
#include <vector>

using namespace std;

class ManageUser {
public:
	bool userExist(string userId);
	bool insert(User model);
	vector<User> getAllUsers();

	static vector<User> users;

	ManageUser() {};
	~ManageUser() {};
protected:

private:

};

#endif
