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
	//vector<Car> getAllReservedCars();
	//vector<Car> getAllAvailableCars();
	//Car* getCarByModel(string model);
	//Car* getCarByLocation(string location);
	//bool update(Car car);
	static vector<Car> cars;
	bool insert(Car car);
	
	//void remove(Car car);

	ManageCar() {} ;
	~ManageCar() {};
protected:

private:

};

#endif