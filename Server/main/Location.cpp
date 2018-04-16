
#include <string>
#include "Location.h"


Location::Location(string address)

{

	this->address = address;
	
}

void Location::setLocation(string address) {
	this->address = address;
}

string Location::getLocation() {

	return this->address;

}
