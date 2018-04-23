
//#include "stdafx.h"
#include <string>
#include <list>
#include "Car_Location.h"




using namespace std;


class Car
{

private:

	string owner ;
	int price;
    list<string> CarInfo;
	Car_Location location;
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

	
	Car(string, int, list<string>, Car_Location, int, string, int, string, int, int, string, string, string, bool);


	string getEngine();
	int getYear();
	int getID();
	string getModel();
	Car_Location getLocation();
	

	string getOwner();

	int getPrice();
	list<string> getCarInfo();

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
	void setLocation(Car_Location location);
	
	void setOwner(string owner);
	void setPrice(int price);
	void setCarInfo(list<string> CarInfo);

	Car() {};
	~Car() {};
};
