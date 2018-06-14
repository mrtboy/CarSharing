#include "ManageCar.h"
#include <vector>
#include <algorithm>

/*
bool ManageCar::update(Car model)
{


	return;
}

*/

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


//ManageCar::ManageCar()
//{
//	return;
//}
//
//void ManageCar::add(Car car)
//{
//	
//}
//void ManageCar::remove(Car car) {
//	
//}
//
//vector<Car> ManageCar::getAllCars() {
//	return;
//}
//vector<Car> ManageCar::getAllReservedCars() {
//	return;
//}
//vector<Car> ManageCar::getAllAvailableCars() {
//	return Car;
//}
//Car* ManageCar::getCarByModel(string title)
//{
//	return;
//}
//Car* ManageCar::getCarByLocation(string author)
//{
//	return;
//}
