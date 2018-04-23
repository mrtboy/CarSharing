#include <string>

using namespace std;

class Car_Location


{

private:

	string address;
	
public:

	Car_Location(string);

	string getLocation();
	
	void setLocation(string address);

	
	Car_Location() {}
	~Car_Location() {}
};