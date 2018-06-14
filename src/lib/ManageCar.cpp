#include "ManageCar.h"
#include <vector>
#include <algorithm>

bool ManageCar::update(Car model)
{
	for (auto &car : cars)
	{
		if (car.getID() == model.getID())
		{
			car = model;
			//std::replace(cars.begin(), cars.end(), car, model);
			return true;
		}
	}
	return false;
}


vector<Car> ManageCar::cars;

vector<Car> ManageCar::getAllCars() {
	return this->cars;
}


bool ManageCar::insert(Car model)
{


	try {

		cars.push_back(model);
		return true;
	}
	catch (exception ex) {
		return false;
	}
	
}

bool ManageCar::reserveCar(int id) {


	for (auto &car : cars)
	{
		if (car.getID() == id && car.getIsAvailable() == true)
		{
			car.setIsAvailable(false);
			return true;
		}
	}
	return false;


}

vector<Car> ManageCar::update_cars;
void ManageCar::remove(Car r_car) {
	for (auto &car : cars)
	{
		if (car.getID() != r_car.getID())
		{
			update_cars.push_back(car);
		}
	}
	cars = update_cars;
}

vector<Car> ManageCar::reserve_Cars;
vector<Car> ManageCar::getAllReservedCars() {
	for (auto &car : cars)
	{
		cout<< car.getID();
		if (car.getIsAvailable() == false)
		{
			reserve_Cars.push_back(car);
		}
	}
	return reserve_Cars;
}

vector<Car> ManageCar::available_Cars;
vector<Car> ManageCar::getAllAvailableCars() {
	for (auto &car : cars)
	{
		cout << car.getID();
		if (car.getIsAvailable() == true)
		{
			available_Cars.push_back(car);
		}
	}
	return available_Cars;
}

Car* ManageCar::getCarByModel(string model) {
	for (auto &car : cars)
	{
		if (car.getModel() == model)
		{
			return &car;
		}
	}
	return NULL;
}

Car* ManageCar::getCarByLocation(string location) {
	for (auto &car : cars)
	{
		if (car.getLocation() == location)
		{
			return &car;
		}
	}
	return NULL;
}