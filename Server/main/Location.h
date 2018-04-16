#include <string>

using namespace std;

class Location
{

private:


	std::string address{ "test" };
	int test = 5;

public:
	// int für test

	Location(string, int) {}

	string getLocation();
	int getTest();

	void setTest(int test);
	void setLocation(string address);

	Location() {}
	~Location() {}
};