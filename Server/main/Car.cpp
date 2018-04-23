// #include "stdafx.h"
#include "Car.h"

using namespace std;



Car::Car(string owner, int price, list<string> carinfo, Car_Location location, int id, string model, int year, string engine, int NoOfDoors, int seats, string transmission, string consumption, string type, bool isAvailable)

{

	this->owner = owner;
	this->price = price;
	this->CarInfo = carinfo;
	this->location = location;
	this->id = id;
	this->model = model;
	this->year = year;
	this->engine = engine;
	this->NoOfDoors = NoOfDoors;
	this->seats = seats;
	this->transmission = transmission;
	this->consumption = consumption;
	this->type = type;
	this->isAvailable = isAvailable;
	
}


// Setters

void Car::setLocation(Car_Location location) {

	this->location = location;
}




void Car::setID(int id) {
	this->id = id;
}

void Car::setModel(string model) {
	this->model = model;
}

void Car::setYear(int year) {
	this->year = year;
}

void Car::setEngine(string engine) {
	this->engine = engine;
}

void Car::setNoOfDoors(int NoOfDoors) {
	this->NoOfDoors = NoOfDoors;
}

void Car::setSeats(int seats) {
	this->seats = seats;
}


void Car::setTransmission(string transmission) {
	this->transmission = transmission;
}

void Car::setConsumption(string consumption) {
	this->consumption = consumption;
}

void Car::setType(string type) {
	this->type = type;
}

void Car::setIsAvailable(bool isAvailable) {
	this->isAvailable = isAvailable;
}



void Car::setOwner(string owner) {
	this->owner = owner;
}


void Car::setPrice(int price) {
	this->price = price;
}



void Car::setCarInfo(list<string> CarInfo) {
	this->CarInfo = CarInfo;
}


// Getters


Car_Location Car::getLocation() {

	return this->location;

}



int Car::getID() {

	return this->id;

}

string Car::getModel() {

	return this->model;

}

int Car::getYear() {

	return this->year;

}

string Car::getEngine() {

	return this->engine;

}

int Car::getNoOfDoors() {

	return this->NoOfDoors;

}

int Car::getSeats() {

	return this->seats;

}

string Car::getTransmission() {

	return this->transmission;

}

string Car::getConsumption() {

	return this->consumption;

}

string Car::getType() {

	return this->type;

}


bool Car::getIsAvailable() {

	return this->isAvailable;

}


string Car::getOwner() {

	return this->owner;

}


	int Car::getPrice() {
		return this->price;
	
}

	list<string> Car::getCarInfo() {
<<<<<<< HEAD
=======


>>>>>>> ab5d8b7f17ec9801f79bcbfbcaf9f71cd67c5f94
		return this->CarInfo;

	}
	
