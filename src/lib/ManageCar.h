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
	bool returnCar(int id);
	Car* getCarByID(int id); 
	vector<Car> getAllCars();
	vector<Car> getAllReservedCars();
	vector<Car> getAllAvailableCars();
	Car* getCarByModel(string model);
	Car* getCarByLocation(string location);
	bool update(Car car);
	static vector<Car> cars;
	static vector<Car> reserve_Cars;
	static vector<Car> available_Cars;
	static vector<Car> update_cars;
	bool insert(Car car);
	void remove(Car car);
	
	//void remove(Car car); ali

	ManageCar() {} ;
	~ManageCar() {};
protected:

private:

};

#endif