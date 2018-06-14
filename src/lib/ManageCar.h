#ifndef MANAGECAR_H
#define MANAGECAR_H
#include <string>
#include "libdef.h"
#include "Car.h"
#include <vector>

using namespace std;

class EXPORT_SYMBOL ManageCar {
public:
	bool reserveCar(int id);
	//Car* getCarById(int id); 
	vector<Car> getAllCars();
	//vector<Car> getAllReservedCars(); ali
	//vector<Car> getAllAvailableCars();ali
	//Car* getCarByModel(string model); ali
	//Car* getCarByLocation(string location);ali
	//bool update(Car car);ali
	static vector<Car> cars;
	bool insert(Car car);
	
	//void remove(Car car); ali

	ManageCar() {} ;
	~ManageCar() {};
protected:

private:

};

#endif