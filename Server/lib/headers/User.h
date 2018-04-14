#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class User {

private:
	string id;
	string name;
	int age;
	string email;
	string address;
	string phone;

public:
	User(string, string, int, string, string, string);
	string getId;
	string getName;
	int getAge;
	string getEmail;
	string getAddress;
	string getPhone;


	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setAddress(string address);
	void setPhone(string phone);

	User() {};
	~User() {};


};

#endif // !USER_H