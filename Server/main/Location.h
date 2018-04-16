#include <string>

using namespace std;

class Location
{

private:

	std::string address{ "test" };
	
public:

	
	Location(string);

	string getLocation();
	
	void setLocation(string address);

	
	Location() {};
	~Location() {};
};