#include "stdafx.h"
#include <string>
#include <Location.h>




Location::Location(string address, int test)
{

	this->address = address;
	this->test = test;
	

}


// Setters

void Location::setLocation(string address) {
	this->address = address;
}

void Location::setTest(int test) {

	this->test = test;
}

int Location::getTest() {

	return this->test;

}

string Location::getLocation() {

	return this->address;

}



Location::~Location() {}