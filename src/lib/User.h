#ifndef USER_H
#define USER_H
#include<string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <iostream>
#include <sstream>
#include <utility>
#include "libdef.h"

using namespace std;

class EXPORT_SYMBOL User {

private:
	string id;
	string name;
	int age;
	string email;
	string address;
	string phone;

public:
	User(string, string, int, string, string, string);
	string getId();
	string getName();
	int getAge();
	string getEmail();
	string getAddress();
	string getPhone();
	string getUserString();

	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setAddress(string address);
	void setPhone(string phone);

	User() {};
	~User() {};

	friend boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive &ar, User &u, const unsigned int version);

};

template <typename Archive>
void serialize(Archive &ar, User &u, const unsigned int version)
{
	ar & u.address;
	ar & u.age;
	ar & u.email;
	ar & u.id;
	ar & u.name;
	ar & u.phone;

}


#endif // !USER_H