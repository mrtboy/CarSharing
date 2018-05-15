#ifndef CAR_H
#define CAR_H

#include "libdef.h"
#include <string>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

using namespace std;

class EXPORT_SYMBOL Car {

private:

	string owner ;
	int price;
	string location;
	int id;
	string model;
	int year;
	string engine;
	int NoOfDoors;
	int seats;
	string transmission;
	string consumption;
	string type;
	bool isAvailable;

	
public:
	Car(string owner, int price, string location, int id, string model, int year, string engine, int NoOFDoors, 
		int seats, string transmission, string consumption, string type, bool isAvalable);

	string getEngine();
	int getYear();
	int getID();
	string getModel();
	string getLocation();
	string getOwner();
	int getPrice();
	int getNoOfDoors();
	int getSeats();
	string getTransmission();
	string getConsumption();
	string getType();
	bool getIsAvailable();
	

	void setNoOfDoors(int NoOfDoors);
	void setSeats(int seats);
	void setTransmission(string transmission);
	void setConsumption(string consumption);
	void setType(string type);
	void setIsAvailable(bool IsAvailable);
	void setYear(int year);
	void setEngine(string engine);
	void setID(int id);
	void setModel(string model);
	void setLocation(string location);
	void setOwner(string owner);
	void setPrice(int price);

	Car() {};
	~Car() {};

	friend boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive &ar, Car &c, const unsigned int version);
};
template <typename Archive>
void serialize(Archive &ar, Car &c, const unsigned int version)
{
	ar & c.owner;
	ar & c.price;
	ar & c.location;
	ar & c.id;
	ar & c.model;
	ar & c.year;
	ar & c.engine;
	ar & c.NoOfDoors;
	ar & c.seats;
	ar & c.transmission;
	ar & c.consumption;
	ar & c.type;
	ar & c.isAvailable;

}


#endif // !CAR_H