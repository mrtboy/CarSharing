
#include <string>
#include "Car_Location.h"


Car_Location::Car_Location(string address)

{

	this->address = address;
	
}

void Car_Location::setLocation(string address) {

	this->address = address;
}

string Car_Location::getLocation() {

	return this->address;

}
