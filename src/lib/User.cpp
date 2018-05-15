#include "User.h"

User::User(string id, string name, int age, string phone, 
	string address, string email) {
	this->id = id;
	this->name = name;
	this->age = age;
	this->phone = phone;
	this->address = address;
	this->email = email;
}

#pragma region Getter

string User::getId() {
	return this->id;
}

string User::getName() {
	return this->name;
}

int User::getAge() {
	return this->age;
}

string User::getEmail() {
	return this->email;
}

string User::getAddress() {
	return this->address;
}

string User::getPhone() {
	return this->phone;
}

#pragma endregion

#pragma region Setter

void User::setName(string name) {
	this->name = name;
}

void User::setAge(int age) {
	this->age = age;
}

void User::setPhone(string phone) {
	this->phone = phone;
}

void User::setAddress(string address) {
	this->address = address;
}

void User::setEmail(string email) {
	this->email = email;
}

string User::getUserString() {
	return "Customer Id: " + id + " name: " + name + " Age: " + " Phone: " + phone + " Address: " + address + " Email: " + email + ".";
}

#pragma endregion
